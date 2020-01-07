#pragma once

#include "iwidget.h"


class Snow:public IWidget
{
public:
    Snow();
    ~Snow();


private:
    void onWind(float x,float y) override;
    void initilizeVariable(QPointF) override;
    void move() override;
    void move(int x, int y) override;
    IWidget* getMirrow() override;
    void createMirrow() override;
    void clearMirrow() override;
    void paintEvent(QPaintEvent *) override;
    void checkIntervalDelta();


    float deltaX;
    float deltaY;
    QPixmap pixmap;
    Snow * mirrowSnow;
    QPainter painter;


};
