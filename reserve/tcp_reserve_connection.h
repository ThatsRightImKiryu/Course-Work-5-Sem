#ifndef TCP_RESERVE_CONNECTION_H
#define TCP_RESERVE_CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QTcpServer>

#define WAIT_FOR_CONNECTION_SECS 1000
#define KEEP_ALIVE_TIME 5*1000

#define INIT_COMMAND "init"
#define END_COMMAND "end"
#define RESERVE_COMMAND "res"
#define END_RESERVE_COMMAND "endres"
#define REQUEST_COMMAND "res"
#define KEEP_ALIVE_COMMAND "alive"


#define NEW_CONNECTED true
#define ABOUT_TO_CLOSE false

class TcpReserveConnection: public QObject
{
    Q_OBJECT
public:
    TcpReserveConnection();
    virtual ~TcpReserveConnection();

    bool setServer(QHostAddress serverAddress, int serverPort);
    bool tryToListen(QHostAddress serverAddress, int serverPort);
    void sendDataToClient();
//    void sendKeepAlive(QTcpSocket * clientSocket);

    bool connectToHost(QHostAddress ipAddress, int port);
    void disconnectFromHost();
    void sendDataToServer(QString command);
    void sendRequestToServer();

    bool waitForConnectionToServer(QHostAddress ipAddress, int port);

protected:
    void keepAliveTimerEvent();
    void startKeepAliveTimer();
public:
    QSet<QTcpSocket*> clientList;
    bool isConnected = false;
private:
    QTcpSocket * tcpSocket = nullptr;
    QTcpServer *tcpServer = nullptr;
    int keepAliveCounter = 0;
    QTimer *timer = nullptr;
public slots:
    void readServer();
    void disconnectedSlot();
    void crashServerSlot();
    void setConnection();
    void readClient();
    void disconnected();

signals:
    void disconnectedSignal();
    void clientChangeSignal(int, bool);
    void setReserveServerSignal();
    void resetReserveServerSignal();
    void keepAliveSignal();
};

#endif // TCP_RESERVE_CONNECTION_H
