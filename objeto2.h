/* OBJETO ESPECIAL(Caida libre) */
#ifndef OBJETO2_H
#define OBJETO2_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<math.h>
class Objeto2: public QGraphicsItem
{
private:
    int pos[2],R;
    float velocidad,y0,g;
public:
    Objeto2(int _x,int _y);
    //Obtener posiciones.
    float getR();
    float t;
    void Actualizar();
    void tamano(int _R);
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

};

#endif // OBJETO2_H
