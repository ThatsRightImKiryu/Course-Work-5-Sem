/********************************************************************************
** Form generated from reading UI file 'reservewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVEWINDOW_H
#define UI_RESERVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReserveWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *connectToServerLineEdit;
    QPushButton *connectToMainServerButton;
    QTextBrowser *logWidget;
    QPushButton *disconnectButton;
    QTableWidget *connectionTable;
    QLineEdit *connectionsCountLineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReserveWindow)
    {
        if (ReserveWindow->objectName().isEmpty())
            ReserveWindow->setObjectName(QString::fromUtf8("ReserveWindow"));
        ReserveWindow->resize(800, 600);
        centralwidget = new QWidget(ReserveWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        connectToServerLineEdit = new QLineEdit(centralwidget);
        connectToServerLineEdit->setObjectName(QString::fromUtf8("connectToServerLineEdit"));
        connectToServerLineEdit->setGeometry(QRect(60, 430, 113, 25));
        connectToMainServerButton = new QPushButton(centralwidget);
        connectToMainServerButton->setObjectName(QString::fromUtf8("connectToMainServerButton"));
        connectToMainServerButton->setGeometry(QRect(200, 430, 171, 25));
        logWidget = new QTextBrowser(centralwidget);
        logWidget->setObjectName(QString::fromUtf8("logWidget"));
        logWidget->setGeometry(QRect(400, 20, 371, 521));
        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(280, 510, 89, 25));
        connectionTable = new QTableWidget(centralwidget);
        if (connectionTable->columnCount() < 1)
            connectionTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        connectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        connectionTable->setObjectName(QString::fromUtf8("connectionTable"));
        connectionTable->setGeometry(QRect(20, 20, 361, 311));
        connectionsCountLineEdit = new QLineEdit(centralwidget);
        connectionsCountLineEdit->setObjectName(QString::fromUtf8("connectionsCountLineEdit"));
        connectionsCountLineEdit->setGeometry(QRect(200, 360, 181, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 370, 141, 17));
        ReserveWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReserveWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ReserveWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ReserveWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ReserveWindow->setStatusBar(statusbar);

        retranslateUi(ReserveWindow);

        QMetaObject::connectSlotsByName(ReserveWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ReserveWindow)
    {
        ReserveWindow->setWindowTitle(QCoreApplication::translate("ReserveWindow", "ReserveWindow", nullptr));
        connectToServerLineEdit->setText(QCoreApplication::translate("ReserveWindow", "127.0.0.1:1221", nullptr));
        connectToMainServerButton->setText(QCoreApplication::translate("ReserveWindow", "Connect to Main Server", nullptr));
        disconnectButton->setText(QCoreApplication::translate("ReserveWindow", "Disconnect", nullptr));
        QTableWidgetItem *___qtablewidgetitem = connectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ReserveWindow", "Client ID", nullptr));
        label->setText(QCoreApplication::translate("ReserveWindow", "Connections count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReserveWindow: public Ui_ReserveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVEWINDOW_H
