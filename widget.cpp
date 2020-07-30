#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("PANTALLA");
    //Pantalla
    x =0 ;
    y =0;
    ancho = 800;
    alto  = 800;
    //Inicializacion variables
    cantidad=0;
    contador1=0;
    o1=0;o3=0;
    o2=0;
    aparecer=100;
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondo.jpg"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    construccion_paredes();
    timer->start(10);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Agregar_clicked()
{

}

void Widget::Actualizar()
{
    /*
    if(contador1==aparecer){
        if(aparecer<501){
            aparecer+=100;
            posx=randInt(60,600);
            parabolico.push_back(new Objeto1(posx,300)); escena->addItem(parabolico.back());
        }
    }
    */
    if(contador1==aparecer1){
        if(aparecer1<301){
              aparecer1+=100;
              posx=randInt(200,600);
              posy=randInt(400,600);
              obstaculos.push_back(new Obstaculos(posx,posy));escena->addItem(obstaculos.back());
         }
    }
    /*
    for(int i=0;i<parabolico.length();i++){
        parabolico.at(i)->t+=0.1;
        parabolico.at(i)->ActualizarVelocidad();
        parabolico.at(i)->ActualizarPosicion();
    }
    */
    for(int i=0;i<obstaculos.length();i++){
        obstaculos.at(i)->actualizar();
    }
    contador1+=10;
    /*
    o1+=10;
    o2+=10;
    o3+=10;
    if(o1>500){
        escena->removeItem(obstaculos.at(1));
        cambiar(obstaculos,1);
    }if(o2>700){
        escena->removeItem(obstaculos.at(2));
        cambiar(obstaculos,2);
    }if(o3>900){
        escena->removeItem(obstaculos.at(3));
        cambiar(obstaculos,3);
    }
    */
}

QList<Obstaculos *> Widget::cambiar(QList<Obstaculos *> lista, int pos)
{
    QList<Obstaculos*> aux;      //Lista auxiliar a retornar
    for(int i=0;i<lista.size();i++){
        if(i!=pos){ //Lo agrega a la lista auxiliar si no es el que se desea eliminar.
            aux.push_back(lista.at(i));
        }
    }
    return aux; //Retorna la lista.
}

int Widget::randInt(int bajo, int alto)
{
    return qrand()%((alto+1)-bajo)+bajo;
}

void Widget::construccion_paredes()
{
    derecha=new Paredes(20,770,760,10); escena->addItem(derecha);
    izquierda=new Paredes(20,760,10,10); escena->addItem(izquierda);
    arriba=new Paredes(750,20,10,10); escena->addItem(arriba);
    abajo=new Paredes(750,20,10,760);escena->addItem(abajo);
}
