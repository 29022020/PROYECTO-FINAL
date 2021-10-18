#ifndef VIKINGSARENA_H
#define VIKINGSARENA_H
#include <QGraphicsItem>

class VikingsArena: public QGraphicsItem
{
public:
    VikingsArena();

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // VIKINGSARENA_H
