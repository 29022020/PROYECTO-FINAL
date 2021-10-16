#include "personajebs.h"

PersonajeBS::PersonajeBS(QObject *parent) : QObject(parent)
{

}

void PersonajeBS::SwordAttack()
{

}

void PersonajeBS::MagicAttack()
{

}

void PersonajeBS::advance(int phase)
{

}

QRectF PersonajeBS::boundingRect() const
{
    return QRectF(0,0,30, 30);
}

void PersonajeBS::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // QPixmap pixmap(":/blocks/Sprite/SpriteBomberman.png");

   // painter->drawPixmap(0,0, pixmap, 30*columnsSprite, 30*filasSprite, 30, 30);
}
