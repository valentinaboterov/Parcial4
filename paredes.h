#ifndef PAREDES_H
#define PAREDES_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
class Paredes:public QGraphicsItem
{
    int w,h;    //Ancho y alto
    int posx, posy;     //Posiciones
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    Paredes(int ancho,int alto,int x,int y);    //Genera la pared.
};

#endif // PAREDES_H
