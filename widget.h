#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsItem>
#include<QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QPixmap>
#include<QTimer>
#include<QMessageBox>
#include"obstaculos.h"
#include"objeto1.h"
#include"objeto2.h"
#include"paredes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QGraphicsScene *escena;

private slots:
    void on_Agregar_clicked();
    void Actualizar();
private:
    Ui::Widget *ui;
    int x,y,ancho,alto,posx,posy,cantidad,aparecer,aparecer1,desaparecer;
    QTimer *timer;
    Obstaculos *obstaculo;
    Paredes *derecha;
    Paredes *izquierda;
    Paredes *arriba;
    Paredes *abajo;
    QList<Objeto1 *> parabolico;
    QList<Objeto2 *> caidalibre;
    QList<Obstaculos *> obstaculos;
    QList<Obstaculos *> cambiar(QList<Obstaculos*> lista,int pos);
    int contador1,o1,o2,o3;
    int aleatorio1,aleatorio2;
    int randInt(int bajo, int alto);
    void construccion_paredes();
};
#endif // WIDGET_H
