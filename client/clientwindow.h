#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <tcp_client_connection.h>
#include <requestwindow.h>

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTimer>
#include <QFrame>
#include <QPushButton>

#define RECONNECTION_SEC_TIMER 2000

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private:
    void disconnectFromHost();
private slots:
    void on_connectToServerButton_clicked();
    void on_disconnectToServerButton_clicked();
    void on_requestButton_clicked();
    void disconnectedSlot();
    void crashServerSlot();
    void tryToReconnectToServer();
    void getRequestAnswerSlot(int commandCount, time_t workingTime);
    void closeRequestWindowSlot();

public:
    QHostAddress getIPAddressFromQLineEdit(QString addressFromQLineEdit);
    uint16_t getPortFromQLineEdit(QString addressFromQLineEdit);
    char addressSeparator = ':';
private:
    Ui::ClientWindow *ui;
    QTimer *timer= nullptr;
    TcpClientConnection connection;
private:
    RequestWindow *requestWindow = nullptr;
    QPushButton * exitButton = nullptr;
};
#endif // CLIENTWINDOW_H
