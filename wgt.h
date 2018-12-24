#ifndef WGT_H
#define WGT_H

#include <QTimer>
#include "sneg.h"
#include "derevo.h"
#include <QObject>
#include <QDesktopWidget>
#include <wind.h>

class Wgt:public QObject
{
    Q_OBJECT
    int countSnow;
    AbstractWidget * wgt;
    QDesktopWidget d;
    QPointF pBegin;
public:
      Wgt();
//      float speed_wind_max,speed_wind_min,speed_wind;
      QList<AbstractWidget*>wgtList;
  //    Elka elka;
      Wind wind;
      QTimer timer, indleTimer;

public slots:
       // void redraw();
        void calcWgt();
        void idleTimer();
};

#endif // WGT_H
