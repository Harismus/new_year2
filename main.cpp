#include <QApplication>
#include "mainclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClass mainClass;
    return a.exec();
}
