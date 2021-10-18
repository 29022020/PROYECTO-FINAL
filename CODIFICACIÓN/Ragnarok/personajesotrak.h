#ifndef PERSONAJESOTRAK_H
#define PERSONAJESOTRAK_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>

#define TAM 40
#define DT 0.1

class PersonajeSotrak: public QGraphicsItem
{
   // Q_OBJECT
public:

   // explicit PersonajeSotrak(QObject *parent = nullptr);

    PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX, float MyVelY);

    void SwordAttack(void);

    void MagicAttack(void);

    void PowerUp(); //PowerUpItem

    void advance(int phase);

    void CalculateMyAce();

    void CalculateMyVel();

    void CalculateMyPos();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getMyVelX() const;
    void setMyVelX(float value);

    float getMyVelY() const;
    void setMyVelY(float value);

    float getMyPosX() const;
    void setMyPosX(float value);

    float getMyPosY() const;
    void setMyPosY(float value);

private:

    float MyPosX, MyPosY;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyLife;

    unsigned int MyDirection;

    unsigned int MyDamage;

    unsigned int MyMagic;

    bool MagicActive;

    QGraphicsScene *MyScene;

    /*QString abajo[3]={":/personaje/Personaje/abajo1.png",":/personaje/Personaje/abajo2.png",":/personaje/Personaje/abajo3.png"};
    QString arriba[3]={":/personaje/Personaje/arriba1.png",":/personaje/Personaje/arriba2.png",":/personaje/Personaje/arriba3.png"};
    QString derecha[3]={":/personaje/Personaje/derecha1.png",":/personaje/Personaje/derecha2.png",":/personaje/Personaje/derecha3.png"};
    QString izquierda[3]={":/personaje/Personaje/izquierda1.png",":/personaje/Personaje/izquierda2.png",":/personaje/Personaje/izquierda3.png"};

    int ScalePerx=TAM,ScalePery=TAM;

    short movimiento[4];*/

    //Container MyRunas

    //Container MyPowers

signals:

};

#endif // PERSONAJESOTRAK_H
