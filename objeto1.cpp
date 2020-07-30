#include "objeto1.h"

Objeto1::Objeto1(int _x, int _y)
{
    pos[0]=_x;
    pos[1]=_y;
    setPos(pos[0],pos[1]);
    R=10;
    g=9.8;
    velocidad[0]=2;
    velocidad[1]=0;
    velocidad[2]=5;
    angulo=40*rad;
}
QRectF Objeto1::boundingRect() const
{
        return QRectF(pos[0],pos[1],2*R,2*R);
}

void Objeto1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);        //asigna el color
    painter->drawEllipse(pos[0],pos[1],2*R,2*R);    //dibuja una elipse encerrada en la boundingRect
}
void Objeto1::ActualizarPosicion()
{
    pos[0]=pos[0]+velocidad[1]*t;
    pos[1]=pos[1]+velocidad[2]*t-(0.5*g*t*t);
    setPos(pos[0],-pos[1]);
}

void Objeto1::ActualizarVelocidad()
{
    velocidad[1]=velocidad[0]*cos(angulo);
    velocidad[2]=velocidad[0]*sin(angulo)-g*t;
    angulo=atan2(velocidad[2],velocidad[1]);
    velocidad[0]= sqrt(pow(velocidad[1],2)+ pow(velocidad[2],2));
}
