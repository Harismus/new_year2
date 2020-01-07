#include <QDebug>

#include <cstdlib>

#include "wind.h"
#include "random.h"


Wind::Wind()
    : speedX(0)
    , speedY(0)
    , count(0)
    , drobnoe(0)
{

}

void Wind::changeSpeed()
{
    if (Random::get(0, 100) >= 90)
    {
        drobnoe += getModule() * Random::get(0.0, 0.05);
        if ((speedX >= 2.5) && (drobnoe > 0))
            drobnoe = -drobnoe;
        else if ((speedX <= -2.5) && (drobnoe < 0))
            drobnoe = -drobnoe;
        else
            speedX += drobnoe;
    }
}

int Wind::getModule()
{
    int i = (Random::get(0, 1));
    if (!i)
        i= -1;
    return i;
}

float Wind::getSpeedX()
{
    return speedX;
}

float Wind::getSpeedY()
{
    return speedY;
}
