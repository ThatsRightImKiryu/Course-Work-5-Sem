#include "requestwindow.h"

RequestWindow::RequestWindow(int commandCount, time_t workingTime)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    exitButton = new QPushButton(this);
    exitButton->setText("Exit");
    exitButton->move(2*WINDOW_WIDTH/5, 4*WINDOW_HEIGHT/5);
    connect(exitButton, &QPushButton::clicked,
            this, &RequestWindow::close);
    commandCountLineEdit = new QLineEdit(this);
    commandCountLineEdit->move(2*WINDOW_WIDTH/5, 2*WINDOW_HEIGHT/5);
    commandCountLineEdit->setText(QString::number(commandCount));
//    commandCountLineEdit->setReadOnly(true);

    workingTimeLineEdit = new QLineEdit(this);
    workingTimeLineEdit->move(2*WINDOW_WIDTH/7, WINDOW_HEIGHT/5);
    workingTimeLineEdit->resize(WINDOW_WIDTH/2, 25);
    workingTimeLineEdit->setText(QString::number(workingTime));
//    workingTimeLineEdit->setReadOnly(true);

    commandCountLabel = new QLabel(this);
    commandCountLabel->move(2*WINDOW_WIDTH/5, 3*WINDOW_HEIGHT/9);
    commandCountLabel->setText("Command Count");

    workingTimeLabel = new QLabel(this);
    workingTimeLabel->move(2*WINDOW_WIDTH/5, 1*WINDOW_HEIGHT/6);
    workingTimeLabel->setText("Working Time");

    this->show();
}


RequestWindow::~RequestWindow()
{
    if(exitButton)
        delete exitButton;
    if(commandCountLineEdit)
        delete commandCountLineEdit;
    if(workingTimeLabel)
        delete workingTimeLabel;
    if(commandCountLabel)
        delete commandCountLabel;

    this->close();
}
