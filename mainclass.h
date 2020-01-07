#pragma once

#include <QTimer>
#include <QObject>
#include <QDesktopWidget>

#include <random>
#include <ctime>

#include "snow.h"
#include "elka.h"
#include "wind.h"


class MainClass:public QObject
{
    Q_OBJECT

public:
    MainClass();

    QList<IWidget*>widgetList;
    Elka elka;
    Wind wind;
    QTimer timer;

private:
    void createSnowList();
    bool checkBottom(const int &index);
    bool checkLeft(const int &index);
    bool checkRight(const int &index);
    bool checkShow(const int &index);
    void mirrowSnowMove(const int &index, const QPointF &p);
    void replaceMirrowSnow(const int &index);

    int countSnow;
    int pixmapSnowWidth;
    IWidget * w;
    QPointF pBegin;

public slots:
    void calcSnowPosition();

};
