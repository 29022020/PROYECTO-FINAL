#ifndef PLATAFORMRANDI_H
#define PLATAFORMRANDI_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

#define DT 0.1
#define WT2 120
#define HT2 50

class PlataformRandI: public QGraphicsItem
{
public:
    PlataformRandI();

    PlataformRandI(float MyPosX_, float MyPosy, float MyVelX_, float MyVelY_, unsigned int MyType_);

    float MyPosX, MyPosY;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyType;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float getMyPosX() const;
    void setMyPosX(float value);
    float getMyPosY() const;
    void setMyPosY(float value);
};

#endif // PLATAFORMRANDI_H
