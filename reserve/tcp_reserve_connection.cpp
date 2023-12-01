#include "tcp_reserve_connection.h"
#include <QThread>

TcpReserveConnection::TcpReserveConnection()
{
    tcpSocket = new QTcpSocket(this);
    tcpServer = new QTcpServer(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &TcpReserveConnection::keepAliveTimerEvent);
    connect(tcpSocket, &QTcpSocket::disconnected,
            this, &TcpReserveConnection::disconnectedSlot);
    connect(tcpSocket, &QTcpSocket::errorOccurred,
            this, &TcpReserveConnection::crashServerSlot);
}

TcpReserveConnection::~TcpReserveConnection()
{
    disconnectFromHost();
}

// CLIENT PART

bool TcpReserveConnection::connectToHost(QHostAddress ipAddress, int port){
        tcpSocket -> connectToHost(ipAddress, port);
        return waitForConnectionToServer(ipAddress, port);
}

void TcpReserveConnection::disconnectFromHost(){
    isConnected = false;
    sendDataToServer(END_RESERVE_COMMAND);
    timer->stop();
    tcpSocket->close();
};


bool TcpReserveConnection::waitForConnectionToServer(QHostAddress ipAddress, int port){
    qDebug() << "Try to connect" << ipAddress << ":" << port << "...";
    qDebug()<<tcpSocket;
    if(tcpSocket -> waitForConnected(WAIT_FOR_CONNECTION_SECS)){
        sendDataToServer(RESERVE_COMMAND);
        startKeepAliveTimer();
        qDebug()<<tcpSocket->errorString();
        connect(tcpSocket, &QTcpSocket::readyRead,
                this, &TcpReserveConnection::readServer);
        return (isConnected = true);

    } else {
        qDebug() << "NOT Connected";
    };
    return (isConnected = false);
}

void TcpReserveConnection::readServer(){
    QByteArray data = tcpSocket->readAll().data();
    qDebug()<<"data from server:"<<data;
    if(!qstrcmp(data, KEEP_ALIVE_COMMAND)){
        keepAliveCounter--;
    }
}

void TcpReserveConnection::sendDataToServer(QString command){
    QByteArray segment;
    segment.append(command.toUtf8());
    tcpSocket->write(segment);
}

void TcpReserveConnection::sendRequestToServer(){
    sendDataToServer(REQUEST_COMMAND);
}

void TcpReserveConnection::keepAliveTimerEvent(){
    sendDataToServer(KEEP_ALIVE_COMMAND);
    keepAliveCounter++;
    if(keepAliveCounter >= 5){
        qDebug()<<"Start Reserve Server";
        timer->stop();
    }
    qDebug()<<"Send via timer"<<timer;
}

void TcpReserveConnection::startKeepAliveTimer(){
    timer->start(KEEP_ALIVE_TIME);
}

void TcpReserveConnection::disconnectedSlot(){
    emit disconnectedSignal();
    qDebug()<<"Disconnected";
}

void TcpReserveConnection::crashServerSlot(){
    emit setReserveServerSignal();
}

// SERVER PART

bool TcpReserveConnection::setServer(QHostAddress serverAddress, int serverPort){
    connect(tcpServer, &QTcpServer::newConnection,
            this, &TcpReserveConnection::setConnection);

    return tryToListen(serverAddress, serverPort);

}

bool TcpReserveConnection::tryToListen(QHostAddress serverAddress, int serverPort){
    QThread::sleep(1);
    if (tcpServer -> listen(serverAddress, serverPort)){
        qDebug() << "Server started on" << serverAddress << ":" << serverPort;
        return true;
    } else {
        qDebug() << "Couldn't start server on" << serverAddress << ":" << serverPort;
        return false;
    };

}

void TcpReserveConnection::setConnection(){
    QTcpSocket * clientSocket = tcpServer -> nextPendingConnection();
    clientList.insert(clientSocket);
    emit clientChangeSignal(clientSocket->socketDescriptor(),
                           NEW_CONNECTED);
    connect(clientSocket, &QTcpSocket::readyRead,
            this, &TcpReserveConnection::readClient);
    connect(clientSocket, &QTcpSocket::disconnected,
            this, &TcpReserveConnection::disconnected);
}

void TcpReserveConnection::disconnected(){
    QTcpSocket * clientSocket = (QTcpSocket*)sender();
    clientList.remove(clientSocket);
    emit clientChangeSignal(clientSocket->socketDescriptor(),
                            ABOUT_TO_CLOSE);
    qDebug()<<"Client disconnected"<<clientSocket->socketDescriptor();
}

void TcpReserveConnection::readClient(){
    QTcpSocket *clientSocket = (QTcpSocket *)sender();
    QByteArray data = clientSocket -> readAll().data();
    if(!qstrcmp(data, REQUEST_COMMAND)){
        clientSocket->write("d");
    }
    if(!qstrcmp(data, RESERVE_COMMAND)){
        emit setReserveServerSignal();
//        clientSocket->write("d");
    }
    if(!qstrcmp(data, END_RESERVE_COMMAND)){
        emit resetReserveServerSignal();
//        clientSocket->write("d");
    }
    qDebug()<<"read from client"<<data<<clientList;
}

void TcpReserveConnection::sendDataToClient(){

}
