#ifndef WIND_H
#define WIND_H
#include <cstdlib>

/*
 * @brief Wind класс определяющий ветер
 * */

class Wind
{

    float speedX,speedY;
    int count;
    int mod;
    float drobnoe;
public:
    Wind();
    void changeSpeed();
    float getSpeedX();
    float getSpeedY();
};

#endif // WIND_H
