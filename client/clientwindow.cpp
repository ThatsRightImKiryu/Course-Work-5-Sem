#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QTime>

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClientWindow::tryToReconnectToServer);
    connect(&connection, &TcpClientConnection::disconnectedSignal,
                          this, &ClientWindow::disconnectedSlot);
    connect(&connection, &TcpClientConnection::crashServerSignal,
                          this, &ClientWindow::crashServerSlot);
    connect(&connection, &TcpClientConnection::getRequestAnswerSignal,
                          this, &ClientWindow::getRequestAnswerSlot);
}

ClientWindow::~ClientWindow()
{
    delete ui;
    if(timer) delete timer;
    if(exitButton) delete exitButton;
    if(requestWindow) delete requestWindow;
}


void ClientWindow::on_connectToServerButton_clicked()
{
    QString addressFromQLineEdit = ui->serverAddressLineEdit->text();
    QHostAddress ipAddress = getIPAddressFromQLineEdit(addressFromQLineEdit);
    uint16_t port = getPortFromQLineEdit(addressFromQLineEdit);
    ui->logWidget->append(QTime::currentTime().toString() +
                                  " Try to connect " + ipAddress.toString() + ":" +
                                  QString::number(port) + "..." );
    if(connection.isConnected){
        ui->logWidget->append(QTime::currentTime().toString() +
                                  " You are ALREADY connected to host ");
    } else {
        if(connection.connectToHost(ipAddress, port)){
            ui->logWidget->append(QTime::currentTime().toString() +
                                  " Connection successful ");
        }
        else
            ui->logWidget->append(QTime::currentTime().toString() +
                                  " Connection FAILED");
    }

}

QHostAddress ClientWindow::getIPAddressFromQLineEdit(QString qLineEditAddress){
    QStringList fullAddress = qLineEditAddress.split(addressSeparator);
    return QHostAddress(fullAddress[0]);
};

uint16_t ClientWindow::getPortFromQLineEdit(QString qLineEditAddress){
    QStringList fullAddress = qLineEditAddress.split(addressSeparator);
    return fullAddress[1].toInt();
};

void ClientWindow::on_disconnectToServerButton_clicked()
{
    if(connection.isConnected){
        disconnectFromHost();
    }
    else
        ui->logWidget->append(QTime::currentTime().toString() +
                              " You are not connected");
}


void ClientWindow::on_requestButton_clicked()
{
    if(!connection.isConnected)
        ui->logWidget->append(QTime::currentTime().toString() +
                              " You must connect to host");
    else {
        ui->logWidget->append(QTime::currentTime().toString() +
                              " Send request to server");
        connection.sendRequestToServer();
    }
}

void ClientWindow::disconnectedSlot(){
    connection.disconnectFromHost();
}

void ClientWindow::getRequestAnswerSlot(int commandCount, time_t workingTime){
    requestWindow = new RequestWindow(commandCount, workingTime);
    connect(requestWindow,&RequestWindow::destroyed,
            this, &ClientWindow::closeRequestWindowSlot);
}

void ClientWindow::closeRequestWindowSlot(){
    if(requestWindow){
        requestWindow = nullptr;
    }
}

void ClientWindow::disconnectFromHost(){
        ui->logWidget->append(QTime::currentTime().toString() +
                             " Disconnected from host");
    connection.disconnectFromHost();
}

void ClientWindow::crashServerSlot(){
    ui->logWidget->append(QTime::currentTime().toString() +
                             " Crash from host");
    connection.disconnectFromHost();

    timer->start(RECONNECTION_SEC_TIMER);
}

void ClientWindow::tryToReconnectToServer(){
    static int countConnection = 0;

    QString addressFromQLineEdit = ui->serverAddressLineEdit->text();
    QHostAddress ipAddress = getIPAddressFromQLineEdit(addressFromQLineEdit);
    uint16_t port = getPortFromQLineEdit(addressFromQLineEdit);

    ui->logWidget->append("Attempt " + QString::number(countConnection)+ " to reconnect");
    if(countConnection++ > 5){
        qDebug()<<"Reconnect FAILED";
        ui->logWidget->append("Reconnect FAILED");
        timer->stop();
    }
    if(connection.connectToHost(ipAddress, port)){
        qDebug()<<"Reconnect successful";
        ui->logWidget->append("Reconnect successful");
        timer->stop();
    }
}
