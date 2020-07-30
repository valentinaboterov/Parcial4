#include "obstaculos.h"

Obstaculos::Obstaculos(int _x,int _y)
{
    pos[0]=_x;
    pos[1]=_y;
    ancho=80;
    alto=20;
    cambiar=0;
}
QRectF Obstaculos::boundingRect() const
{
        return QRectF(pos[0],pos[1],ancho,alto);
}

void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);        //asigna el color
    painter->drawRect(boundingRect());    //dibuja una elipse encerrada en la boundingRect
}
void Obstaculos::actualizar(){
    //Suma o resta a la posicion en x segun el caso.
    if(cambiar==0){
        pos[0]+=30;
        if(pos[0]>400){
            cambiar=1;
        }
    }else{
        pos[0]-=30;
        if(pos[0]<80){
            cambiar=0;
        }
    }
    setPos(pos[0],pos[1]);
}
