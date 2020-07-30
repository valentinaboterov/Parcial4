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
    contador1=0;
    contador2=0;
    o1=0;o3=0;
    o2=0;
    aparecer=100;
    aparecer1=100;
    desaparecer=0;
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondo.jpg"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    construccion_paredes();
    timer->start(100);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Agregar_clicked()
{
    posx=randInt(20,600);
    posy=randInt(10,50);
    caidalibre.push_back(new Objeto2(posx,posy)); escena->addItem(caidalibre.back());
}

void Widget::Actualizar()
{
    if(contador1<5000){
            contador1+=10;
    }
    //OBSTACULO
    if(contador2<600){
            contador2+=50;
    }
    if(contador2==aparecer1){
        aparecer1+=100;
        posx=randInt(100,700);
        posy=randInt(50,600);
        obstaculos.push_back(new Obstaculos(posx,posy));
        escena->addItem(obstaculos.back());
    }
    for(int i=0;i<obstaculos.size();i++){
       obstaculos.at(i)->actualizar();
    }
    //OBJETO ESPECIAL
    for(int i=0;i<caidalibre.length();i++){
        caidalibre.at(i)->t+=5;
        caidalibre.at(i)->Actualizar();
    }

    Colisiones();
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

void Widget::Colisiones()
{
    for(int i=0;i<caidalibre.length();i++){
        if(caidalibre.at(i)->collidesWithItem(abajo)){
            escena->removeItem(caidalibre.at(i));
        }
        for(int j=0;j<obstaculos.length();j++){
            if(caidalibre.at(i)->collidesWithItem(obstaculos.at(j))){
                caidalibre.at(i)->tamano(caidalibre.at(i)->getR()-2);
            }
        }
    }
}
