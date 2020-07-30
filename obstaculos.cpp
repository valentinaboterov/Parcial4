#include "obstaculos.h"

Obstaculos::Obstaculos(int _x,int _y)
{
    pos[0]=_x;
    pos[1]=_y;
    setPos(pos[0],pos[1]);
    ancho=60;
    alto=40;
    cambiar=0;
}
QRectF Obstaculos::boundingRect() const
{
        return QRectF(pos[0],pos[1],ancho,alto);
}

void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::magenta);        //asigna el color
    painter->drawRect(pos[0],pos[1], ancho,alto);    //dibuja una elipse encerrada en la boundingRect
}
void Obstaculos::actualizar(){
    //Suma o resta a la posicion en x segun el caso.
    if(cambiar==0){
        pos[0]+=30;
        if(pos[0]>740){
            cambiar=1;
        }
    }else{
        pos[0]-=30;
        if(pos[0]<60){
            cambiar=0;
        }
    }


}
