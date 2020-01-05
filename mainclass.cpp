#include <QDebug>

#include "mainclass.h"
#include "monitorssize.h"


MainClass::MainClass()
    : countSnow(50)
    , pixmapSnowWidth(32)
    , gen(time(0))
    , uid(0, MonitorsSize::getQSizeAt(0).width())
    , genShower(0, 100)
{
    createSnowList();
    //  elka.show();

    connect(&timer, &QTimer::timeout, this, &MainClass::calcSnowPosition);

    timer.start(60);
}

void MainClass::createSnowList()
{
    for (int i = 0; i < countSnow; ++i)
    {
        pBegin = QPoint(uid(gen), -pixmapSnowWidth);

        IWidget * snowFlake = new Snow;
        snowFlake->initilizeVariable(pBegin);
        snowFlake->hide();
        widgetList.append(snowFlake);
    }
}

void MainClass::calcSnowPosition()
{
    wind.changeSpeed();
    for (int i = 0; i < widgetList.size(); ++i) //!< движение виджетов
    {
        if (!checkShow(i))     //!<
            continue;

        widgetList.at(i)->doWind(wind.getSpeedX(), wind.getSpeedY());
        widgetList.at(i)->move();

        if (checkBottom(i))     //!< проверка выхода за низ
            continue;
        else if (checkLeft(i))  //!< проверка выхода за левый край
            continue;
        else if (checkRight(i)) //!< проверка выхода за правый край
            continue;
    }
}

bool MainClass::checkShow(const int & index)
{
    if (!widgetList.at(index)->getFlagShow() && genShower(gen) == 0)
    {
        widgetList.at(index)->show();
        return true;
    }
    else if (widgetList.at(index)->getFlagShow())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MainClass::checkBottom(const int & index)
{
    if (widgetList.at(index)->y() > MonitorsSize::getQSizeAt(0).height()) //!< если вышел за нижние пределы экрана, то возвращаем на начальную позицию
    {
        pBegin = QPoint(uid(gen), -pixmapSnowWidth);
        widgetList.at(index)->initilizeVariable(pBegin);
        widgetList.at(index)->hide();
        return true;
    }
    return false;
}

bool MainClass::checkLeft(const int & index)
{
    if((widgetList.at(index)->x() <= 0)
            && ((widgetList.at(index)->x() + pixmapSnowWidth) >= 0))//если вышел за левые пределы экрана не полностью, то возвращаем на начальную позицию
    {
        QPointF p(widgetList.at(index)->x() + MonitorsSize::getQSizeAt(0).width()
                  , widgetList.at(index)->y());
        mirrowSnowMove(index, p);
        return true;
    }
    else if((widgetList.at(index)->x() <= 0)
            && ((widgetList.at(index)->x() + pixmapSnowWidth) <= 0))//если вышел за левые пределы экрана полностью, то возвращаем на начальную позицию
    {
        replaceMirrowSnow(index);
        return true;
    }
    return false;
}

bool MainClass::checkRight(const int & index)
{
    if((widgetList.at(index)->x() < MonitorsSize::getQSizeAt(0).width())
            && ((widgetList.at(index)->x() + pixmapSnowWidth) >= MonitorsSize::getQSizeAt(0).width()))//если вышел за правые пределы экрана, то возвращаем на начальную позицию
    {
        QPointF p(widgetList.at(index)->x() - MonitorsSize::getQSizeAt(0).width(),
                  widgetList.at(index)->y());

        mirrowSnowMove(index, p);
        return true;
    }
    else if(widgetList.at(index)->x() >= MonitorsSize::getQSizeAt(0).width())//если вышел за правые пределы экрана, то возвращаем на начальную позицию
    {
        replaceMirrowSnow(index);
        return true;
    }
    return false;
}

void MainClass::mirrowSnowMove(const int & index, const QPointF & p)
{
    widgetList.at(index)->getMirrow()->move(p.x(), p.y());
    widgetList.at(index)->getMirrow()->show();
}

void MainClass::replaceMirrowSnow(const int & index)
{
    IWidget * snowFlakeMirrow = widgetList.at(index)->getMirrow();
    widgetList.at(index)->move(snowFlakeMirrow->x(), snowFlakeMirrow->y());
    widgetList.at(index)->show();
    snowFlakeMirrow->hide();
}
