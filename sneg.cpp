#include "sneg.h"
#include <QDebug>
sneg::sneg(QPointF pos,bool top_flag)
{
    MirrowSneg = NULL;
    setWindowFlags(Qt::SplashScreen | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    pixmap.setMask(pixmap.createMaskFromColor(Qt::white, Qt::MaskInColor));

    pixmap.load(":/snow8.png");

    returnToBeginPosition(pos);
    right_flag = false;
    left_flag = false;
    setGeometry(x,y,pixmap.width(),pixmap.height());
    setMask(pixmap.mask());
    this->top_flag =top_flag;
//this->clearFocus();
    update();
}
//sneg::sneg(const sneg&sn)
//{
//    x = sn.x;
//    y = sn.y;
//    deltax = sn.deltax;
//    deltay = sn.deltay;
//    pixmap = sn.pixmap;
//    right_flag = sn.right_flag;
//    left_flag = sn.left_flag;
//}

sneg::~sneg()
{

}

void sneg::returnToBeginPosition(QPointF pos)
{
    x = pos.x();
    int i = (rand()%2);
    if(!i) i=-1;
    y = /*-pixmap.height();*/pos.y();
    //deltax = /*i**/0;//(0.1+(float)rand()/RAND_MAX *1);
    deltay = ((float)rand()/RAND_MAX *1)+0.1;
    if(deltay>=0.7) deltay = 0.7;

    top_flag = true;
}

void sneg::move()
{
    //    QDesktopWidget d;

//    if(top_flag)
//    {
//         //srand(rand()%time(0));
//        int t = ((float)rand()/RAND_MAX*1000);
//        //qDebug()<<x;
//        if(t >=998)
//        {
//            x += deltax;
//            y += deltay;
//            x += windX;
//            y += windY;



//            setGeometry(x,y,pixmap.width(),pixmap.height());
//            top_flag = false;
//        }
//    }
//    else
    {

        //int x=0,y= 0;
        x += deltax;
        y += deltay;
        x += windX;
        y += windY;

//        qDebug()<<windX;
        setGeometry(x,y,pixmap.width(),pixmap.height());
    }
        //====================================================

}

void sneg::doWind(float x, float y)
{
    windX = x; windY = y;
}
void sneg::createMirrowSneg()
{
    if(!MirrowSneg)
    {
        MirrowSneg = new sneg(QPointF(0,0),false);
    }
}
void sneg::clearMirrowSneg()
{
    if(MirrowSneg)
    {
        delete MirrowSneg;
        MirrowSneg = NULL;
    }
}

void sneg::setMirrowSnegPos(QPointF p)
{
    MirrowSneg->setX(p.x());
    MirrowSneg->setY(p.y());
}

AbstractWidget *sneg::getMirrowSneg()
{

    return MirrowSneg;
}

void sneg::paintEvent(QPaintEvent *)
{
    paint.begin(this);
    paint.drawPixmap(0,0,pixmap);
    paint.end();
}




