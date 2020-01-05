#include "monitorssize.h"

#include <QApplication>
#include <QDesktopWidget>

MonitorsSize::MonitorsSize(QObject *parent) : QObject(parent)
{
    listScreen = QGuiApplication::screens();
}

int MonitorsSize::size()
{
    return listScreen.size();
}

//QSize MonitorsSize::getQSizeAt(int n)
//{
//    if( size() )
//        return listScreen.at(n)->size();
//    else
//        return QSize();
//}

QSize MonitorsSize::getQSizeAt(const int & n)
{
    if( QGuiApplication::screens().size() )
        return QGuiApplication::screens().at(n)->size();
    else
        return QSize();
}

QRect MonitorsSize::getQRectAt(const int & n)
{
    if( size() )
        return listScreen.at(n)->geometry();
    else
        return QRect();
}

int MonitorsSize::getWidthAt(int n)
{
    if( size() )
        return listScreen.at(n)->size().width();
    else
        return 0;
}

int MonitorsSize::getHeightAt(int n)
{
    if( size() )
        return listScreen.at(n)->size().height();
    else
        return 0;
}
