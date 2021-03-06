#ifndef RUNES_H
#define RUNES_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

#define WT5 40
#define HT5 40


class Runes: public QGraphicsItem
{
public:

    Runes(float MyPosX_, float MyPosy, unsigned int MyType_);

    float MyPosX, MyPosY;

    unsigned int MyType;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    unsigned int getMyType() const;
    void setMyType(unsigned int value);
};

#endif // RUNES_H
