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

    VikingsArena(float MyPosX_, float MyPosy, float MyInitX_, float MyEndX,float MyVelX_, float MyVelY_, unsigned int MyType_);

    float MyPosX, MyPosY;

    float MyInitX, MyEndX;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyType;

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // VIKINGSARENA_H
