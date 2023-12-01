#include "tcp_client_connection.h"
#include <unistd.h>

TcpClientConnection::TcpClientConnection()
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::readyRead,
            this, &TcpClientConnection::readServer);
    connect(tcpSocket, &QTcpSocket::errorOccurred,
            this, &TcpClientConnection::crashServerSlot);
    connect(tcpSocket, &QTcpSocket::disconnected,
            this, &TcpClientConnection::disconnectedSlot);
}

TcpClientConnection::~TcpClientConnection()
{
    disconnectFromHost();
}

bool TcpClientConnection::connectToHost(QHostAddress ipAddress, int port){
    tcpSocket -> connectToHost(ipAddress, port);
    return waitForConnectionToServer(ipAddress, port);
}

void TcpClientConnection::disconnectFromHost(){
    isConnected = false;
    tcpSocket->close();
};


bool TcpClientConnection::waitForConnectionToServer(QHostAddress ipAddress, int port){
    qDebug() << "Try to connect" << ipAddress << ":" << port << "...";
    if(tcpSocket -> waitForConnected(WAIT_FOR_CONNECTION_SECS)){
        qDebug()<<"Connection successful";
        sendDataToServer(INIT_COMMAND);
        return (isConnected = true);

    } else {
        qDebug() << "NOT Connected";
    };
    return (isConnected = false);
}

void TcpClientConnection::readServer(){
    QByteArray data = tcpSocket->readAll().data();

    RequestStruct *requestStruct = reinterpret_cast<RequestStruct* >(data.data());
    qDebug()<<"data from server:"<<data<<requestStruct->command;
    if(!qstrcmp(requestStruct->command, REQUEST_COMMAND)){
        emit getRequestAnswerSignal(requestStruct->commandCount, requestStruct->workingTime);
    }
}

void TcpClientConnection::sendDataToServer(QString command){
    QByteArray segment;
    segment.append(command.toUtf8());
    tcpSocket->write(segment);
}

void TcpClientConnection::sendRequestToServer(){
    sendDataToServer(REQUEST_COMMAND);
}

void TcpClientConnection::disconnectedSlot(){
    if(isConnected)
        qDebug()<<"Disconnected";
    emit disconnectedSignal();

}

void TcpClientConnection::crashServerSlot(){
    if(isConnected)
    {
        qDebug()<<"Crash server";
        emit crashServerSignal();
    }
}
