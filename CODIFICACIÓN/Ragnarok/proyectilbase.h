#ifndef PROYECTILBASE_H
#define PROYECTILBASE_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

#define WT4 60
#define HT4 70


class ProyectilBase: public QGraphicsItem
{
public:
    ProyectilBase();

    ProyectilBase(float MyPosX_, float MyPosy, float MyVelX_, float MyVelY_, unsigned int MyType_);

    float MyPosX, MyPosY;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyType;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PROYECTILBASE_H
