#ifndef POWERUPITEMS_H
#define POWERUPITEMS_H
#include <QGraphicsItem>

class PowerUpItems: public QGraphicsItem
{
public:
    PowerUpItems();

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // POWERUPITEMS_H
