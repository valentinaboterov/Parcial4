/*OBJETO1 (Movimiento parabolico)*/
#ifndef OBJETO1_H
#define OBJETO1_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>

class Objeto1: public QGraphicsItem
{
private:
    int pos[2];
    float R,velocidad[3],angulo,g,rad=2*M_PI;
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

public:
    Objeto1(int _x,int _y);
    float t;
    void ActualizarVelocidad();
    void ActualizarPosicion();
};

#endif // OBJETO1_H
