#ifndef TCP_SERVER_CONNECTION_H
#define TCP_SERVER_CONNECTION_H

#define END_COMMAND "end"
#define REQUEST_COMMAND "req"
#define RESERVE_COMMAND "res"
#define END_RESERVE_COMMAND "endres"
#define KEEP_ALIVE_COMMAND "alive"

#define NEW_CONNECTED true
#define ABOUT_TO_CLOSE false


#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>

struct ClientInfo{
    char* command;
};

class TcpServerConnection : public QObject
{
    Q_OBJECT
public:
    TcpServerConnection();
    virtual ~TcpServerConnection();

    bool setServer(QHostAddress serverAddress, int serverPort);
    bool tryToListen(QHostAddress serverAddress, int serverPort);
    void sendDataToClient();
    void sendKeepAlive(QTcpSocket * clientSocket);
    void sendRequestAnswer(QTcpSocket * clientSocket);
private:
    QTcpServer *tcpServer;
    uint32_t commandCount = 0;
    time_t startTime = 0;
public:
    QSet<QTcpSocket*> clientList;

public slots:
    void setConnection();
    void readClient();
    void disconnected();
signals:    
    void clientChangeSignal(int, bool);
    void setReserveServerSignal();
    void resetReserveServerSignal();
    void keepAliveSignal();
};

#endif // TCP_SERVER_CONNECTION_H
