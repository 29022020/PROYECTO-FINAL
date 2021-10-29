#ifndef PROYECTILBASE_H
#define PROYECTILBASE_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#define DT6 0.01
#define WT4 20
#define HT4 20

class ProyectilBase: public QGraphicsItem
{
public:
    ProyectilBase();

    ProyectilBase(float MyPosX_, float MyPosy, float MyVelX_, unsigned int MyType_,unsigned int Damage_);

    float MyPosX, MyPosY;

    float MyVelX;

    unsigned int MyDamage;

    float MyAceX, MyAceY;

    unsigned int MyType;

    unsigned int ContAttack;

    bool FlagAttack;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getMyPosX() const;
    void setMyPosX(float value);

    float getMyPosY() const;
    void setMyPosY(float value);

    bool getFlagAttack() const;
    void setFlagAttack(bool value);
    unsigned int getMyDamage() const;
    void setMyDamage(unsigned int value);
    float getMyVelX() const;
    void setMyVelX(float value);
};

#endif // PROYECTILBASE_H
