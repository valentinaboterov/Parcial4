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

private:
    Ui::Widget *ui;
    int x,y,ancho,alto;
};
#endif // WIDGET_H
