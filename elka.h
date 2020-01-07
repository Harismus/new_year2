#pragma once

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QBitmap>
#include <QPainter>

#include "iwidget.h"


class Elka:public IWidget
{
public:
    Elka();

private:
    void onWind(float x,float y) override;
    void initilizeVariable(QPointF) override;
    void move() override;
    void move(int x, int y) override;
    IWidget *getMirrow() override;
    void createMirrow() override;
    void clearMirrow() override;
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;

    float x1;
    float y1;
    float x;
    float y;
    QPainter painter;
    QPixmap pixmap;
};

