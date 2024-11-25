#include "Lab3s_5.h"
#include <QtWidgets/QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel HW("Hello, world!");
    HW.show();
    return a.exec();
}
