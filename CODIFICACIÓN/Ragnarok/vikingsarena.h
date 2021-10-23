#ifndef VIKINGSARENA_H
#define VIKINGSARENA_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

#define DT1 0.01
#define WT6 60
#define HT6 70


class VikingsArena: public QGraphicsItem
{
public:
    VikingsArena();

    VikingsArena(float MyPosX_, float MyPosy, float MyInitX_, float MyEndX,float MyVelX_, float MyVelY_, unsigned int MyType_, unsigned int MyLife_,unsigned int MyDamage_);


    float MyPosX, MyPosY;

    float MyInitX, MyEndX;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyType;

    unsigned int MyLife;

    unsigned int ContAttack;

    unsigned int MyDamage;

    bool FlagAttack;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float getMyVelX() const;
    void setMyVelX(float value);
    unsigned int getMyLife() const;
    void setMyLife(unsigned int value);
    bool getFlagAttack() const;
    void setFlagAttack(bool value);
    unsigned int getMyDamage() const;
    void setMyDamage(unsigned int value);
};

#endif // VIKINGSARENA_H
