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
    escena=new QGraphicsScene(x,y,ancho,alto);
    escena->setBackgroundBrush(QPixmap(":/Imagenes/fondo.jpg"));
    ui->graphicsView->setScene(escena);
    ui->graphicsView->resize(ancho,alto);
}

Widget::~Widget()
{
    delete ui;
}

