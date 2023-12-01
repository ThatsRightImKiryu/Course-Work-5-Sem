#include "reservewindow.h"
#include "ui_reservewindow.h"
#include <QTime>
ReserveWindow::ReserveWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReserveWindow)
{
    ui->setupUi(this);
    connect(&connection, &TcpReserveConnection::disconnectedSignal,
                          this, &ReserveWindow::disconnectedSlot);
    connect(&connection, &TcpReserveConnection::setReserveServerSignal,
                          this, &ReserveWindow::setReserveServerSlot);
    connect(&connection, &TcpReserveConnection::clientChangeSignal,
            this, &ReserveWindow::clientChangeSlot);

}

ReserveWindow::~ReserveWindow()
{
    delete ui;
}


void ReserveWindow::on_connectToMainServerButton_clicked()
{
    QString addressFromQLineEdit = ui->connectToServerLineEdit->text();
    QHostAddress ipAddress = getIPAddressFromQLineEdit(addressFromQLineEdit);
    uint16_t port = getPortFromQLineEdit(addressFromQLineEdit);
    connection.sendDataToServer("res");
    ui->logWidget->append(QTime::currentTime().toString() +
                          " Try to connect " + ipAddress.toString() + ":" +
                          QString::number(port) + "..." );
    if(connection.isConnected){
        ui->logWidget->append(QTime::currentTime().toString() +
                              " You are ALREADY connected to host ");
    } else {
        if(connection.connectToHost(ipAddress, port))
            ui->logWidget->append(QTime::currentTime().toString() +
                                  " Connection successful ");
        else
            ui->logWidget->append(QTime::currentTime().toString() +
                                  " Connection FAILED");
    }

}

QHostAddress ReserveWindow::getIPAddressFromQLineEdit(QString qLineEditAddress){
    QStringList fullAddress = qLineEditAddress.split(addressSeparator);
    return QHostAddress(fullAddress[0]);
};

uint16_t ReserveWindow::getPortFromQLineEdit(QString qLineEditAddress){
    QStringList fullAddress = qLineEditAddress.split(addressSeparator);
    return fullAddress[1].toInt();
};


void ReserveWindow::on_disconnectButton_clicked()
{
    connection.disconnectFromHost();
}

void ReserveWindow::disconnectedSlot(){
    disconnectFromHost();
}


void ReserveWindow::disconnectFromHost(){
    connection.disconnectFromHost();
    ui->logWidget->append(QTime::currentTime().toString() +
                      " Disconnected from host");
}

void ReserveWindow::setReserveServerSlot(){

    QString addressFromQLineEdit = ui->connectToServerLineEdit->text();
    QHostAddress ipAddress = getIPAddressFromQLineEdit(addressFromQLineEdit);
    uint16_t port = getPortFromQLineEdit(addressFromQLineEdit);

    if(connection.setServer(ipAddress, port))
        ui->logWidget->append(QTime::currentTime().toString() +
                              " Server started on " + ipAddress.toString() + ":" +
                              QString::number(port));
     else
        ui->logWidget->append(QTime::currentTime().toString() +
                              " Couldn`t server started on " + ipAddress.toString() + ":" +
                              QString::number(port));

}

void ReserveWindow::clientChangeSlot(int clientId, bool isOpen){
    if(isOpen)
        ui->logWidget->append(QTime::currentTime().toString() +
                              " Connected client with id = " +
                              QString::number(clientId));
    else
        ui->logWidget->append(QTime::currentTime().toString() +
                              " Client Disconnected");

    ui->connectionsCountLineEdit->setText(QString::number(connection.clientList.size()));
    fillConnectionTable();
}

void ReserveWindow::fillConnectionTable(){
    QTableWidget *connectionTable = ui->connectionTable;
    resetConnectionTable(connectionTable);
    qDebug()<<"list in table"<<connection.clientList;
    for(auto client: connection.clientList.values()){
        int rowCount = 0;
            connectionTable->insertRow(rowCount);
            ui->connectionTable->setItem(rowCount, 0,
                new QTableWidgetItem(QString::number(client->socketDescriptor())));
    }

}

void ReserveWindow::resetConnectionTable(QTableWidget *connectionTable){
    connectionTable->clear(); connectionTable->setRowCount(0);
    QStringList headers = {"Client ID"};
    connectionTable->setHorizontalHeaderLabels(headers);
}
