#include <QDebug>

#include "snow.h"


Snow::Snow()
    : deltaX(0)
    , deltaY(0)
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

    checkIntervalDelta();
}

void Snow::move()
{
    QWidget::move(static_cast<int>(this->x() + deltaX)
                  , static_cast<int>(this->y() + deltaY));
}

void Snow::move(int x, int y)
{
    QWidget::move(x, y);
}

void Snow::onWind(float windX, float windY)
{
    QWidget::move(this->x() + windX, this->y() + windY);
}

void Snow::checkIntervalDelta()
{
    if (deltaY > 4.7)
        deltaY = 4.7;
    else  if (deltaY < -4.7)
        deltaY = -4.7;

    if (deltaX > 4.7)
        deltaX = 4.7;
    else  if (deltaX < -4.7)
        deltaX = -4.7;
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
    painter.rotate(1);
    painter.drawPixmap(0, 0, pixmap);
    painter.end();
}
