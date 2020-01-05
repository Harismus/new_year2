#pragma once

#include "iwidget.h"


class Snow:public IWidget
{
public:
    Snow();
    ~Snow();


private:
    void doWind(float x,float y) override;
    void initilizeVariable(QPointF) override;
    void move() override;
    void move(int x, int y) override;
    IWidget* getMirrow() override;
    void createMirrow() override;
    void clearMirrow() override;
    void paintEvent(QPaintEvent *) override;



    float deltaX;
    float deltaY;
    float windX;
    float windY;
    QPixmap pixmap;
    Snow * mirrowSnow;
    QPainter painter;

};
