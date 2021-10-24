#ifndef AXE_H
#define AXE_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QtMath>
#include "math.h"

//#define DT1 0.01
#define DT 0.01
#define AXEW 60
#define AXEH 70
class Axe : public QGraphicsItem
{
public:
    Axe();

    void advance(int phase);

    QRectF boundingRect() const;

    Axe(float MyPosX_, float MyPosy,float MyVelX_, float MyVelY_,unsigned int MyDamage_);

    float MyPosX, MyPosY;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    float MyMass;

    float FrecAngular;

    float degrees;

    float MomentInercia;

    int MyDamage;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // AXE_H
