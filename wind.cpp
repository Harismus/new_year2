#include "wind.h"
#include <QDebug>

Wind::Wind()
{
    speedX = 0;
    speedY = 0;
    count = 0;
    mod = 1;
    drobnoe=0;
}

void Wind::changeSpeed()
{


    if(count>=1)
    {
        int i = 1;

        i = (rand()%20);


        if(mod>=50 && i >= 10)
        {
            i = (rand()%2);
            if(!i) i=-1;
            mod = 0;
            drobnoe += i*(float)(rand()%10)/100;
            if(speedX>=0.5 && drobnoe > 0)
            {

                drobnoe=-drobnoe;


            }
            else if(speedX<=-0.5 && drobnoe < 0)
            {

                drobnoe = -drobnoe;
            }
            else
                speedX+=drobnoe;
        }







        count = 0;
        mod++;

        //qDebug()<<"speedX"<<speedX;
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





//void sneg::set_wind(float wind_speed)
//{
//    deltax = wind_speed;
//    int celoe = 0;
//    float drobnoe = 0;
//    celoe = rand()%2;
//    drobnoe  = (float)(rand()%500)/100;
//    if(!celoe)
//    {
//        celoe = -1;
//        drobnoe = -1 *drobnoe;
//    }
//    deltax = celoe + drobnoe;
//    deltax+=wind_speed;
//}

//void sneg::mousePressEvent(QMouseEvent*me)
//{
//   x1 = me->x(); y1 = me->y();
//}

//void sneg::mouseMoveEvent(QMouseEvent*me)
//{
//    x = x + (me->x() - x1);
//    y = y + (me->y() - y1);
//    x1 = me->x(); y1 = me->y();
//    setGeometry(x,y,pixmap.width(),pixmap.height());
//}
