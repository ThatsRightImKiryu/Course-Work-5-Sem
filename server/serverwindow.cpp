#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <server_settings.h>
#include <QTime>

ServerWindow::ServerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    connect(&serverConnection, &TcpServerConnection::clientChangeSignal,
            this, &ServerWindow::clientChangeSlot);
    connect(&serverConnection, &TcpServerConnection::setReserveServerSignal,
            this, &ServerWindow::setReserveServerSlot);
    connect(&serverConnection, &TcpServerConnection::resetReserveServerSignal,
            this, &ServerWindow::resetReserveServerSlot);
    connect(&serverConnection, &TcpServerConnection::keepAliveSignal,
            this, &ServerWindow::keepAliveSlot);
}

ServerWindow::~ServerWindow()
{
    delete ui;
    qDebug()<<"AAAAAAAA";
}

void ServerWindow::on_startServerButton_clicked()
{

    if(serverConnection.setServer(SERVER_ADDRESS, SERVER_PORT))
        ui->LogWidget->append(QTime::currentTime().toString() +
                              " Server started on " + SERVER_ADDRESS.toString() + ":" +
                              QString::number(SERVER_PORT));
     else
        ui->LogWidget->append(QTime::currentTime().toString() +
                              " Couldn`t server started on " + SERVER_ADDRESS.toString() + ":" +
                              QString::number(SERVER_PORT));
}

void ServerWindow::clientChangeSlot(int clientId, bool isOpen){
    if(isOpen)
        ui->LogWidget->append(QTime::currentTime().toString() +
                              " Connected client with id = " +
                              QString::number(clientId));
    else
        ui->LogWidget->append(QTime::currentTime().toString() +
                              " Client Disconnected");

    ui->conectionsCountLineEdit->setText(QString::number(serverConnection.clientList.size()));
    fillConnectionTable();
}

void ServerWindow::fillConnectionTable(){
    QTableWidget *connectionTable = ui->connectionTable;
    resetConnectionTable(connectionTable);
    qDebug()<<"list in table"<<serverConnection.clientList;
    for(auto client: serverConnection.clientList.values()){
        int rowCount = 0;
            connectionTable->insertRow(rowCount);
            ui->connectionTable->setItem(rowCount, 0,
                new QTableWidgetItem(QString::number(client->socketDescriptor())));
    }
}

void ServerWindow::resetConnectionTable(QTableWidget* connectionTable){
    connectionTable->clear(); connectionTable->setRowCount(0);
    QStringList headers = {"Client ID"};
    connectionTable->setHorizontalHeaderLabels(headers);

}

void ServerWindow::setReserveServerSlot(){
    ui->reserveServerlineEdit->setText("Connected");
};

void ServerWindow::resetReserveServerSlot(){
    ui->reserveServerlineEdit->setText("Disonnected");
};

void ServerWindow::keepAliveSlot(){
    ui->LogWidget->append(QTime::currentTime().toString() +
                          " Keep Alive Command from Reserve Server");
}

void ServerWindow::on_pushButton_clicked()
{
    exit(1);
}

