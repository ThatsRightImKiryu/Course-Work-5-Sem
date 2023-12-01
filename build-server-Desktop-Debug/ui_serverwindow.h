/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

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

class Ui_ServerWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startServerButton;
    QTableWidget *connectionTable;
    QLabel *label;
    QLineEdit *conectionsCountLineEdit;
    QLineEdit *reserveServerlineEdit;
    QLabel *label_2;
    QTextBrowser *LogWidget;
    QLineEdit *serverAddressLineEdit;
    QPushButton *startServerButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QString::fromUtf8("ServerWindow"));
        ServerWindow->resize(800, 600);
        centralwidget = new QWidget(ServerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startServerButton = new QPushButton(centralwidget);
        startServerButton->setObjectName(QString::fromUtf8("startServerButton"));
        startServerButton->setGeometry(QRect(50, 420, 89, 25));
        connectionTable = new QTableWidget(centralwidget);
        if (connectionTable->columnCount() < 1)
            connectionTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        connectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        connectionTable->setObjectName(QString::fromUtf8("connectionTable"));
        connectionTable->setGeometry(QRect(50, 20, 351, 241));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 300, 161, 17));
        conectionsCountLineEdit = new QLineEdit(centralwidget);
        conectionsCountLineEdit->setObjectName(QString::fromUtf8("conectionsCountLineEdit"));
        conectionsCountLineEdit->setGeometry(QRect(230, 290, 113, 25));
        reserveServerlineEdit = new QLineEdit(centralwidget);
        reserveServerlineEdit->setObjectName(QString::fromUtf8("reserveServerlineEdit"));
        reserveServerlineEdit->setGeometry(QRect(230, 350, 113, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 350, 121, 17));
        LogWidget = new QTextBrowser(centralwidget);
        LogWidget->setObjectName(QString::fromUtf8("LogWidget"));
        LogWidget->setGeometry(QRect(460, 20, 311, 521));
        serverAddressLineEdit = new QLineEdit(centralwidget);
        serverAddressLineEdit->setObjectName(QString::fromUtf8("serverAddressLineEdit"));
        serverAddressLineEdit->setGeometry(QRect(50, 470, 191, 25));
        startServerButton_2 = new QPushButton(centralwidget);
        startServerButton_2->setObjectName(QString::fromUtf8("startServerButton_2"));
        startServerButton_2->setGeometry(QRect(50, 510, 89, 25));
        ServerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ServerWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ServerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ServerWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ServerWindow->setStatusBar(statusbar);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QCoreApplication::translate("ServerWindow", "ServerWindow", nullptr));
        startServerButton->setText(QCoreApplication::translate("ServerWindow", "Start Server", nullptr));
        QTableWidgetItem *___qtablewidgetitem = connectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ServerWindow", "Client ID", nullptr));
        label->setText(QCoreApplication::translate("ServerWindow", "Count of connections", nullptr));
        label_2->setText(QCoreApplication::translate("ServerWindow", "Reserve Server", nullptr));
        serverAddressLineEdit->setText(QCoreApplication::translate("ServerWindow", "127.0.0.1:1221", nullptr));
        startServerButton_2->setText(QCoreApplication::translate("ServerWindow", "Stop Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
