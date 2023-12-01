#include "reservewindow.h"
#include "ui_reservewindow.h"

ReserveWindow::ReserveWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReserveWindow)
{
    ui->setupUi(this);
}

ReserveWindow::~ReserveWindow()
{
    delete ui;
}


void ReserveWindow::on_connectButton_clicked()
{

}

