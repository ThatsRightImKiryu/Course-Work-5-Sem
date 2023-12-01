#include "reservewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReserveWindow w;
    w.show();
    return a.exec();
}
