#ifndef PERSONAJESOTRAK_H
#define PERSONAJESOTRAK_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include <math.h>
#include <QtMath>
#include "plataformrandi.h"

#define DT 0.01
#define WT1 60
#define HT1 70

class PersonajeSotrak: public QGraphicsItem
{
    //Q_OBJECT
public:

    explicit PersonajeSotrak(QObject *parent = nullptr);

    ~PersonajeSotrak();

    PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX, float MyVelY, QGraphicsScene *MyScene_);

    PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX, float MyVelY, float MyDamage, float MyMagic, float MyLife_,int MyScore_,QGraphicsScene *MyScene_);

    void SwordAttack(int SpriteNum);

    void MagicAttack(void);

    void PowerUp(int ItemType); //PowerUpItem

    void RunesItems(int ItemType);

    void advance(int phase);

    void CalculateMyAce();

    void CalculateMyVel();

    void CalculateMyPos();

    void Jump();

    void RestartSprite();

    void EnemyAttackMe(int Damage, int Vel);

    void ChangeMySprite(char Direction);

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

    unsigned int getMyDirection() const;
    void setMyDirection(unsigned int value);

    float getMyLastPosX() const;
    void setMyLastPosX(float value);

    float getMyLastPosY() const;
    void setMyLastPosY(float value);

    bool getFlagJump() const;
    void setFlagJump(bool value);

    float getMyAceY() const;
    void setMyAceY(float value);

    unsigned int getMyHeight() const;
    void setMyHeight(unsigned int value);

    unsigned int getMyWidht() const;
    void setMyWidht(unsigned int value);

    unsigned int getContSprites() const;
    void setContSprites(unsigned int value);

    unsigned int getMyDamage() const;
    void setMyDamage(unsigned int value);

    unsigned int getMyLife() const;
    void setMyLife(unsigned int value);

    unsigned int getMyScore() const;
    void setMyScore(unsigned int value);

private:

    float MyPosX, MyPosY;

    float MyLastPosX, MyLastPosY;

    float MyVelX, MyVelY;

    float MyAceX, MyAceY;

    unsigned int MyLife;

    unsigned int MyDirection;

    unsigned int MyScore;

    unsigned int MyDamage;

    unsigned int MyMagic;

    unsigned int MyHeight;

    unsigned int MyWidht;

    unsigned int ContSprites;

    unsigned int Mass;

    int ContSwordAttack;

    bool MagicActive;

    bool CollingEnemy;

    bool FlagJump;

    bool CollingAnalize(float MyPosX, float MyPosY);

    QGraphicsScene *MyScene;

    QPixmap *MyPixmap;

    QString JumpSprites[2]={":/new/prefix1/sprites/personaje/derecha2.png", ":/new/prefix1/sprites/personaje/izquierda2.png"};

    //QString arriba[3]={":/personaje/Personaje/arriba1.png",":/personaje/Personaje/arriba2.png",":/personaje/Personaje/arriba3.png"};

    QString RightSprites[3]={":/new/prefix1/sprites/personaje/derecha2.png",":/new/prefix1/sprites/personaje/derecha1.png",":/new/prefix1/sprites/personaje/derecha3.png"};

    QString LeftSprites[3]={":/new/prefix1/sprites/personaje/izquierda2.png",":/new/prefix1/sprites/personaje/izquierda1.png",":/new/prefix1/sprites/personaje/izquierda3.png"};

    /*int ScalePerx=TAM,ScalePery=TAM;

    short movimiento[4];*/

    //Container MyRunas

    //Container MyPowers

signals:

};

#endif // PERSONAJESOTRAK_H
