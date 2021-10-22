#ifndef FLOOR_H
#define FLOOR_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#define WT7 120
#define HT7 50
class Floor: public QGraphicsItem
{
public:
    Floor();

    Floor(float MyPosX_, float MyPosy,unsigned int MyType_);

    float MyPosX, MyPosY;

    unsigned int MyType;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    unsigned int getMyType() const;
    void setMyType(unsigned int value);

    float getMyPosX() const;
    void setMyPosX(float value);

    float getMyPosY() const;
    void setMyPosY(float value);
};

#endif // FLOOR_H
