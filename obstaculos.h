#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>


class Obstaculos: public QGraphicsItem
{
private:
    int pos[2],cambiar;
    float ancho,alto;
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

public:
    Obstaculos(int _x,int _y);
    void actualizar();
};

#endif // OBSTACULOS_H
