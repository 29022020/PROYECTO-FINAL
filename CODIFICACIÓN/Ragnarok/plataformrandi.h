#ifndef PLATAFORMRANDI_H
#define PLATAFORMRANDI_H
#include <QGraphicsItem>

class PlataformRandI: public QGraphicsItem
{
public:
    PlataformRandI();

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLATAFORMRANDI_H
