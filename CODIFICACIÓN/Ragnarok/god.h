#ifndef GOD_H
#define GOD_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#define DT3 0.01

class God: public QGraphicsItem
{
public:
    God(float MyPosX_, float MyPosy, float MyInitX_, float MyEndX,float MyVelX_, float MyVelY_, unsigned int MyType_, unsigned int MyLife_,unsigned int MyDamage_,unsigned int MyMagic_);

    float MyPosX, MyPosY;

    float MyInitX, MyEndX;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyType;

    int MyLife;

    unsigned int ContAttack;

    unsigned int MyDamage;

    bool FlagAttack;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GOD_H
