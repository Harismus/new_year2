#ifndef SNEG_H
#define SNEG_H
#include "abstractwidget.h"
class sneg:public AbstractWidget
{
    float x,y;
    float deltax,deltay;
    float windX,windY;
    QPainter paint;
    bool right_flag,left_flag, top_flag;
    QPixmap pixmap;


public:
    sneg(){}
    sneg(QPointF pos,bool top_flag);
//    sneg(const sneg&);
    sneg* MirrowSneg;
    ~sneg();
    virtual float getX(){return x;}
    virtual float getY(){return y;}
    virtual float setX(float new_x){x = new_x;}
    virtual float setY(float new_y){y = new_y;}
    virtual float setDeltaX(float newDeltaX){deltax = newDeltaX;}
    virtual float setDeltaY(float newDeltaY){deltay = newDeltaY;}
    virtual void returnToBeginPosition(QPointF);
    virtual void move();
    virtual void doWind(float x,float y);
    virtual AbstractWidget* getMirrowSneg();
    void paintEvent(QPaintEvent *);
    virtual void setMirrowSnegPos(QPointF p);
    virtual void createMirrowSneg();
    void clearMirrowSneg();
};






#endif //
