#ifndef RUNES_H
#define RUNES_H
#include <QGraphicsItem>

class Runes: public QGraphicsItem
{
public:
    Runes();

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RUNES_H
