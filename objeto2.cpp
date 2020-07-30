#include "objeto2.h"

Objeto2::Objeto2(int _x,int _y)
{
    pos[0]=_x;
    pos[1]=_y;
    g=-9.8;
    R=20;
    velocidad=5;
    t=0;
    y0=pos[1];
}

float Objeto2::getR()
{
    return R;
}

void Objeto2::Actualizar()
{
    pos[1]=pos[1]+velocidad*t+0.5*g*t;
    setPos(pos[0],pos[1]);
}

void Objeto2::tamano(int _R)
{
    R=_R;
    this->update();
}
QRectF Objeto2::boundingRect() const
{
        return QRectF(pos[0],pos[1],2*R,2*R);
}

void Objeto2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);        //asigna el color
    painter->drawEllipse(pos[0],pos[1],2*R,2*R);    //dibuja una elipse encerrada en la boundingRect
}
