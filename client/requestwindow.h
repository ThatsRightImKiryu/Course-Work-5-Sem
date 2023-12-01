#ifndef REQUESTWINDOW_H
#define REQUESTWINDOW_H

#include <QObject>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500



class RequestWindow: public QFrame
{
    Q_OBJECT
public:
    RequestWindow(int commandCount, time_t workingTime);
    ~RequestWindow();
private:
    QPushButton * exitButton = nullptr;
    QLineEdit * commandCountLineEdit = nullptr;
    QLineEdit * workingTimeLineEdit = nullptr;

    QLabel * commandCountLabel = nullptr;
    QLabel * workingTimeLabel = nullptr;

};

#endif // REQUESTWINDOW_H
