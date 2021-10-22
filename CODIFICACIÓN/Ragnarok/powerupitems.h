#ifndef POWERUPITEMS_H
#define POWERUPITEMS_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

#define WT3 40
#define HT3 40

class PowerUpItems: public QGraphicsItem
{
public:
    PowerUpItems();

    PowerUpItems(float MyPosX_, float MyPosy, unsigned int MyType_);

    float MyPosX, MyPosY;

    unsigned int MyType;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // POWERUPITEMS_H
