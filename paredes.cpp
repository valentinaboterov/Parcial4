#include "paredes.h"
//Inicialización de variables con parámetros de entrada según la ventana.
Paredes::Paredes(int ancho, int alto, int x, int y)
{
    w=ancho;
    h=alto;
    posx=x;
    posy=y;
}

//Funciones propias de QT:
//Cuadrados para organizar la pantalla.
QRectF Paredes::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}
//Pinta un rectangulo rojo.
void Paredes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
}
