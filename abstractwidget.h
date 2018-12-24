#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H
#include <QWidget>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPointF>
class AbstractWidget:public QWidget
{
public:
    virtual ~AbstractWidget() = 0;
    virtual float getX() = 0;
    virtual float getY() = 0;
    virtual float setX(float) = 0;
    virtual float setY(float) = 0;
    virtual float setDeltaX(float) = 0;
    virtual float setDeltaY(float) = 0;
    virtual void doWind(float x,float y) = 0;
    virtual void returnToBeginPosition(QPointF) = 0;
    virtual void move()=0;
    virtual AbstractWidget* getMirrowSneg()=0;
    virtual void setMirrowSnegPos(QPointF p) = 0;
    virtual void createMirrowSneg()=0;
    void clearMirrowSneg();
};


#endif // ABSTRACTWIDGET_H
