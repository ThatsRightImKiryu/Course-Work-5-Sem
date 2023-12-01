#ifndef RESERVEWINDOW_H
#define RESERVEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ReserveWindow; }
QT_END_NAMESPACE

class ReserveWindow : public QMainWindow
{
    Q_OBJECT

public:
    ReserveWindow(QWidget *parent = nullptr);
    ~ReserveWindow();

public:
//    TcpReserveConnection connection;

private slots:
    void on_connectButton_clicked();

private:
    Ui::ReserveWindow *ui;
};
#endif // RESERVEWINDOW_H
