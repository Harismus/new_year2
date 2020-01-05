#include <QDebug>

#include <cstdlib>

#include "wind.h"


Wind::Wind()
{
    speedX = 0;
    speedY = 0;
    count = 0;
    mod = 1;
    drobnoe = 0;
}

void Wind::changeSpeed()
{
    if (count >= 1)
    {
        int i = (rand() % 20);

        if (mod >= 50 && i >= 10)
        {
            i = (rand() % 2);
            if (!i)
                i= -1;

            mod = 0;
            drobnoe += i * (float)(rand() % 10) / 100;
            if (speedX >= 2.5 && drobnoe > 0)
                drobnoe = -drobnoe;
            else if (speedX <= -2.5 && drobnoe < 0)
                drobnoe = -drobnoe;
            else
                speedX += drobnoe;
        }
        count = 0;
        mod++;
    }
    count++;
}

float Wind::getSpeedX()
{
    return speedX;
}

float Wind::getSpeedY()
{
    return speedY;
}
