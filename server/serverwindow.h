#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <tcp_server_connection.h>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWindow; }
QT_END_NAMESPACE

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    ServerWindow(QWidget *parent = nullptr);
    ~ServerWindow();

private:
    void fillConnectionTable();
    void resetConnectionTable(QTableWidget* connectionTable);
private slots:
    void on_startServerButton_clicked();
    void clientChangeSlot(int clientId, bool isOpen);
    void setReserveServerSlot();
    void resetReserveServerSlot();
    void keepAliveSlot();
    void on_pushButton_clicked();

public:
    TcpServerConnection serverConnection;
private:
    Ui::ServerWindow *ui;
};
#endif // SERVERWINDOW_H
