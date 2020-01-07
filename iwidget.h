#pragma once

#include <QWidget>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPointF>
#include <QMouseEvent>


class IWidget:public QWidget
{
public:
    virtual void onWind(float x,float y) = 0;
    virtual void initilizeVariable(QPointF) = 0;
    virtual void move() = 0;
    virtual void move(int x, int y) = 0;
    /**
     * @brief getMirrow получение объекта зеркального отображения картинки
     * @return
     */
    virtual IWidget* getMirrow() = 0;
    virtual void createMirrow() = 0;
    virtual void clearMirrow() = 0;

    bool getFlagShow()
    {
        return QWidget::isVisible();
    }

    Qt::WindowFlags getWindowFlags()
    {
        return (Qt::SplashScreen
                | Qt::WindowStaysOnTopHint
                | Qt::FramelessWindowHint
                | Qt::X11BypassWindowManagerHint);
    }

    void mousePressEvent(QMouseEvent * e)
    {
        p0 = e->pos();
    }
    void mouseMoveEvent(QMouseEvent * e)
    {
        auto p1 = mapToParent(e->pos() - p0);
        QWidget::move(p1);
    }

private:
    QPoint p0;
};
