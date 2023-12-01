#ifndef RESERVEWINDOW_H
#define RESERVEWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <tcp_reserve_connection.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ReserveWindow; }
QT_END_NAMESPACE

class ReserveWindow : public QMainWindow
{
    Q_OBJECT

public:
    ReserveWindow(QWidget *parent = nullptr);
    ~ReserveWindow();

private:
    void disconnectFromHost();
    void fillConnectionTable();
    void resetConnectionTable(QTableWidget *);
private slots:
    void on_connectToMainServerButton_clicked();
    void disconnectedSlot();
    void on_disconnectButton_clicked();
    void clientChangeSlot(int clientId, bool isOpen);
    void setReserveServerSlot();

private:
    Ui::ReserveWindow *ui;
    TcpReserveConnection connection;
    QTcpSocket * tcpSocket = nullptr;
    char addressSeparator = ':';
    QHostAddress getIPAddressFromQLineEdit(QString addressFromQLineEdit);
    uint16_t getPortFromQLineEdit(QString addressFromQLineEdit);
    bool isConnected = false;

};
#endif // RESERVEWINDOW_H
