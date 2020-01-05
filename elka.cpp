#include "elka.h"

Elka::Elka()
    : pixmap(":/1.png")
{
    setMask(pixmap.mask());
    setWindowFlags(getWindowFlags());
}

void Elka::doWind(float x, float y)
{

}

void Elka::initilizeVariable(QPointF)
{

}

void Elka::move()
{

}

void Elka::move(int x, int y)
{

}

IWidget *Elka::getMirrow()
{

}


void Elka::createMirrow()
{

}

void Elka::clearMirrow()
{

}

void Elka::resizeEvent(QResizeEvent *)
{
    x = width() / 2;
    y = height() / 2;
    setGeometry(x, y, pixmap.width(), pixmap.height());
    update();
}

void Elka::paintEvent(QPaintEvent *)
{
    painter.begin(this);
    painter.drawPixmap(0, 0, pixmap);
    painter.end();
}
