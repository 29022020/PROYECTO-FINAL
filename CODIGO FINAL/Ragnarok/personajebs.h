#ifndef PERSONAJEBS_H
#define PERSONAJEBS_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class PersonajeBS : public QObject, QGraphicsItem
{
    Q_OBJECT
public:

    explicit PersonajeBS(QObject *parent = nullptr);

    void SwordAttack(void);

    void MagicAttack(void);

    void PowerUp(); //PowerUpItem

    void advance(int phase);

    void CalculateMyAce();

    void CalculateMyVel();

    void CalculateMyPos();

private:

    double MyPosX, MyPosY;

    double MyVelX, MyVelY;

    double MyAceX, MyAceY;

    unsigned int MyLife;

    unsigned int MyDirection;

    unsigned int MyDaño;

    unsigned int MyMagic;

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Container MyRunas

    //Container MyPowers


signals:

};

#endif // PERSONAJEBS_H
