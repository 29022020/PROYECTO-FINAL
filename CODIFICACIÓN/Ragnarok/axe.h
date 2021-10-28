#ifndef AXE_H
#define AXE_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QtMath>
#include <math.h>

//#define DT1 0.01
#define DT 0.05
#define pi 3.1416
#define AXEW 60
#define AXEH 70
class Axe : public QGraphicsItem
{
public:
    Axe();

    void advance(int phase);

    QRectF boundingRect() const;

    Axe(float MyPosX_, float MyPosy,float MyVelX_, float MyVelY_,unsigned int MyDamage_);

    Axe(float MyPosX_, float MyPosy,float MyVelX_, float MyVelY_,unsigned int MyDamage_,unsigned int MyType, unsigned int MyRadio_);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool getFlagAttack() const;
    void setFlagAttack(bool value);

    int getMyDamage() const;
    void setMyDamage(int value);

private:
    float MyPosX, MyPosY;

    float MyPosXnow, MyPosYnow;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    float Theta;

    float W;

    float i;

    int Cont;

    float FrecAngular;

    unsigned int MyType;

    unsigned int ContAttack;

    unsigned int Radio;

    int MyDamage;

    bool FlagAttack;
};

#endif // AXE_H
