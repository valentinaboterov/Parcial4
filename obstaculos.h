#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>
#include<QTimer>

class Obstaculos: public QGraphicsItem
{
private:
    int pos[2];
    float ancho,alto;
public:
    Obstaculos(int _x,int _y);
    //Obtener posiciones.
    float getx();
    float gety();
    void actualizar();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

};

#endif // OBSTACULOS_H
