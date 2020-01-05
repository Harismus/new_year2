#include <QDebug>

#include "snow.h"


Snow::Snow()
    : deltaX(0)
    , deltaY(0)
    , windX(0)
    , windY(0)
    , pixmap(":/snow8.png")
    , mirrowSnow(nullptr)
{
    setWindowFlags(getWindowFlags());
    pixmap.setMask(pixmap.createMaskFromColor(Qt::white, Qt::MaskInColor));
    setMask(pixmap.mask());
}

Snow::~Snow()
{

}

void Snow::initilizeVariable(QPointF pos)
{    
    move(pos.x(), pos.y());
    createMirrow();

    deltaY = ((float)rand() / RAND_MAX) + 3.1;

    if (deltaY >= 4.7)
        deltaY = 4.7;
}

void Snow::move()
{
    QWidget::move(static_cast<int>(this->x() + deltaX + windX), static_cast<int>(this->y() + deltaY + windX));
}

void Snow::move(int x, int y)
{
    QWidget::move(x, y);
}

void Snow::doWind(float x, float y)
{
    windX = x;
    windY = y;
}
void Snow::createMirrow()
{
    if (!mirrowSnow)
        mirrowSnow = new Snow();
}
void Snow::clearMirrow()
{
    if (mirrowSnow)
    {
        delete mirrowSnow;
        mirrowSnow = nullptr;
    }
}

IWidget * Snow::getMirrow()
{    
    return mirrowSnow;
}

void Snow::paintEvent(QPaintEvent *)
{
    painter.begin(this);
    painter.drawPixmap(0, 0, pixmap);
    painter.end();
}
