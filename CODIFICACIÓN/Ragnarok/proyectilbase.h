#ifndef PROYECTILBASE_H
#define PROYECTILBASE_H
#include <QGraphicsItem>

class ProyectilBase: public QGraphicsItem
{
public:
    ProyectilBase();

    void advance(int phase);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PROYECTILBASE_H
