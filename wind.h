#pragma once




/*
 * @brief Wind класс определяющий ветер
*/
class Wind
{   
public:
    Wind();
    void changeSpeed();
    float getSpeedX();
    float getSpeedY();

private:
    float speedX,speedY;
    int count;
    int mod;
    float drobnoe;
};

