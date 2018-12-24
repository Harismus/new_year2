#include "wgt.h"
#include <QDebug>
Wgt::Wgt():countSnow(5)
{
    QDesktopWidget d;

    for(int i = 0;i<countSnow;i++)
    {
        pBegin = QPointF(((float)rand()/RAND_MAX *d.width()),-32);
        wgt = new sneg(pBegin,true);
        wgt->createMirrowSneg();
        wgt->show();
        wgtList.append(wgt);
    }
   // elka.show();
    connect(&timer,SIGNAL(timeout()),this,SLOT(calcWgt()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(idleTimer()));
    timer.start(60);


}

void Wgt::calcWgt()
{   

    wind.changeSpeed();
    for(int i = 0; i<wgtList.size();i++)//движение виджетов
    {

        wgtList.at(i)->doWind(wind.getSpeedX(),wind.getSpeedY());
        wgtList.at(i)->move();
        if(wgtList.at(i)->getY()/*+ wgtList.at(i)->height()*/>d.height())//если вышел за нижние пределы экрана, то возвращаем на начальную позицию
        {
            pBegin = QPointF(((float)rand()/RAND_MAX *d.width()),-32);
            wgtList.at(i)->returnToBeginPosition(pBegin);
            continue;
        }


        else if(wgtList.at(i)->getX()<=0 && wgtList.at(i)->getX() + 32>=0)//если вышел за левые пределы экрана, то возвращаем на начальную позицию
        {

            QPointF p(wgtList.at(i)->getX()+d.width(),wgtList.at(i)->getY());
            wgtList.at(i)->setMirrowSnegPos(p);
            wgtList.at(i)->getMirrowSneg()->move();
            wgtList.at(i)->getMirrowSneg()->show();
        }
        else if(wgtList.at(i)->getX()<=0 && wgtList.at(i)->getX() + 32<=0)//если вышел за левые пределы экрана, то возвращаем на начальную позицию
        {

            AbstractWidget * wgt = wgtList.at(i)->getMirrowSneg();
            wgtList.at(i)->setX(wgt->x());
            wgtList.at(i)->setY(wgt->y());
            wgtList.at(i)->move();
            wgtList.at(i)->show();
            wgt->hide();

        }



        else if(wgtList.at(i)->getX()<d.width() && wgtList.at(i)->getX() + 32>=d.width())//если вышел за правые пределы экрана, то возвращаем на начальную позицию
        {

            QPointF p(wgtList.at(i)->getX()-d.width(),wgtList.at(i)->getY());
            wgtList.at(i)->setMirrowSnegPos(p);
            wgtList.at(i)->getMirrowSneg()->move();
            wgtList.at(i)->getMirrowSneg()->show();
        }
        else if(wgtList.at(i)->getX()>=d.width() )//если вышел за правые пределы экрана, то возвращаем на начальную позицию
        {

            AbstractWidget * wgt = wgtList.at(i)->getMirrowSneg();
            wgtList.at(i)->setX(wgt->x());
            wgtList.at(i)->setY(wgt->y());
            wgtList.at(i)->move();
            wgtList.at(i)->show();
            wgt->hide();

        }
    }


}
#include <X11/extensions/scrnsaver.h>

void Wgt::idleTimer()
{
//    XScreenSaverInfo info;
//    Display *m_pDisplay = XOpenDisplay(NULL);
//    int EventBase = 0; int ErrorBase = 0; uint IdleTime = 0;
//    if (::XScreenSaverQueryExtension(m_pDisplay, &EventBase, &ErrorBase))
//    {}
//        XScreenSaverInfo* pInfo = ::XScreenSaverAllocInfo();
//        if (pInfo)
//        { ::XScreenSaverQueryInfo(::XOpenDisplay(NULL), DefaultRootWindow(m_pDisplay), pInfo);
//            IdleTime = static_cast<uint>(pInfo->idle)/1000; ::XFree(pInfo);
//        }
//    }
}


//    //===========================================
//        /* Лапмпочки*/
//    paint.drawPixmap(elka.width()/4,elka.height()/2,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2,elka.height()/2,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-30,190,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-60,290,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-80,490,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2+20,550,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-130,550,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.end();





