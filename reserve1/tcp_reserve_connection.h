#ifndef TCP_RESERVE_CONNECTION_H
#define TCP_RESERVE_CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class TcpReserveConnection:public QObject
{
    Q_OBJECT
public:
    TcpReserveConnection();
    virtual ~TcpReserveConnection();
    bool connectToHost(QHostAddress ipAddress, int port);
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
};

#endif // TCP_RESERVE_CONNECTION_H
