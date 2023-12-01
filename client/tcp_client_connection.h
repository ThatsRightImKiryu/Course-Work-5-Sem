#ifndef TCP_CLIENT_CONNECTION_H
#define TCP_CLIENT_CONNECTION_H

#define WAIT_FOR_CONNECTION_SECS 3000
#define INIT_COMMAND "init"
#define END_COMMAND "end"
#define REQUEST_COMMAND "req"

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>



class TcpClientConnection : public QObject
{
    Q_OBJECT
public:
    TcpClientConnection();
    virtual ~TcpClientConnection();
    bool connectToHost(QHostAddress ipAddress, int port);
    bool tryToReconnectToServer(QHostAddress ipAddress, int port);
    void disconnectFromHost();
    void sendDataToServer(QString command);
    void sendRequestToServer();

    bool waitForConnectionToServer(QHostAddress ipAddress, int port);

public:
    bool isConnected = false;
private:
    QTcpSocket * tcpSocket = nullptr;
public slots:
    void readServer();
    void disconnectedSlot();
    void crashServerSlot();

signals:
    void disconnectedSignal();
    void crashServerSignal();
    void getRequestAnswerSignal(int commandCount, time_t workingTime);
};

#pragma pack(push, 1)

typedef struct {
    char command[4];
    uint32_t commandCount;
    time_t workingTime;
} RequestStruct;

#pragma pack(pop)

#endif // TCP_CLIENT_CONNECTION_H
