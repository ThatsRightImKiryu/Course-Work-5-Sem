#include <tcp_server_connection.h>

TcpServerConnection::TcpServerConnection(){
    tcpServer = new QTcpServer(this);
    startTime = std::time(nullptr);
}


TcpServerConnection::~TcpServerConnection(){
    for(auto client: clientList){
        client->close();
    }
}

bool TcpServerConnection::setServer(QHostAddress serverAddress, int serverPort){
    connect(tcpServer, &QTcpServer::newConnection,
            this, &TcpServerConnection::setConnection);

    return tryToListen(serverAddress, serverPort);

}

bool TcpServerConnection::tryToListen(QHostAddress serverAddress, int serverPort){
    if (tcpServer -> listen(serverAddress, serverPort)){
        qDebug() << "Server started on" << serverAddress << ":" << serverPort;
        return true;
    } else {
        qDebug() << "Couldn't start server on" << serverAddress << ":" << serverPort;
        return false;
    };

}

void TcpServerConnection::setConnection(){
    QTcpSocket * clientSocket = tcpServer -> nextPendingConnection();
    clientList.insert(clientSocket);
    emit clientChangeSignal(clientSocket->socketDescriptor(),
                           NEW_CONNECTED);
    connect(clientSocket, &QTcpSocket::readyRead,
            this, &TcpServerConnection::readClient);
    connect(clientSocket, &QTcpSocket::disconnected,
            this, &TcpServerConnection::disconnected);
}

void TcpServerConnection::disconnected(){
    QTcpSocket * clientSocket = (QTcpSocket*)sender();
    clientList.remove(clientSocket);
    emit clientChangeSignal(clientSocket->socketDescriptor(),
                            ABOUT_TO_CLOSE);
    qDebug()<<"Client disconnected"<<clientSocket->socketDescriptor();
}

void TcpServerConnection::readClient(){
    QTcpSocket *clientSocket = (QTcpSocket *)sender();
    QByteArray data = clientSocket -> readAll().data();
    if(!qstrcmp(data, REQUEST_COMMAND)){
        sendRequestAnswer(clientSocket);
    }
    if(!qstrcmp(data, RESERVE_COMMAND)){
        emit setReserveServerSignal();
//        clientSocket->write("d");
    }
    if(!qstrcmp(data, END_RESERVE_COMMAND)){
        emit resetReserveServerSignal();
//        clientSocket->write("d");
    }
    if(!qstrcmp(data, KEEP_ALIVE_COMMAND)){
        sendKeepAlive(clientSocket);
    }
    qDebug()<<"read from client"<<data<<clientList;
    commandCount++;
}

void TcpServerConnection::sendDataToClient(){

}

void TcpServerConnection::sendKeepAlive(QTcpSocket * clientSocket){
    emit keepAliveSignal();
    clientSocket->write(KEEP_ALIVE_COMMAND);
}

void TcpServerConnection::sendRequestAnswer(QTcpSocket * clientSocket){
    QByteArray segment;


    time_t workingTime = std::time(nullptr) - startTime;

    segment.append(REQUEST_COMMAND, strlen(REQUEST_COMMAND)+1);


    char * commandCountBytes = reinterpret_cast<char *>(&commandCount);
    segment.append(commandCountBytes, sizeof(commandCount));

    char * workingTimeBytes = reinterpret_cast<char *>(&workingTime);
    segment.append(workingTimeBytes, sizeof(workingTime));

    clientSocket->write(segment);
}
