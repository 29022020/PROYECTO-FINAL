#include "powerupitems.h"

PowerUpItems::PowerUpItems()
{

}

void PowerUpItems::advance(int phase)
{

}

QRectF PowerUpItems::boundingRect() const
{
    return QRectF(0,0,WT3, HT3);

}

void PowerUpItems::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MyType==1){

        QPixmap pixmap(":/sprites/ITEMS/DPurple.png");

        painter->drawPixmap(0,0,WT3,HT3,pixmap);

    }else if(MyType==2){

        QPixmap pixmap(":/sprites/ITEMS/Green.png");

        painter->drawPixmap(0,0,WT3,HT3,pixmap);

    }else if(MyType==3){

        QPixmap pixmap(":/sprites/ITEMS/Purplee.png");

        painter->drawPixmap(0,0,WT3,HT3,pixmap);

    }
    else if(MyType==4){

            QPixmap pixmap(":/sprites/ITEMS/White.png");

            painter->drawPixmap(0,0,WT3,HT3,pixmap);

        }
    else if(MyType==5){

            QPixmap pixmap(":/sprites/ITEMS/Yellow.png");

            painter->drawPixmap(0,0,WT3,HT3,pixmap);

        }


}
