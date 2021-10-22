#include "runes.h"


Runes::Runes(float MyPosX_, float MyPosY_, unsigned int MyType_)
{
    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyType=MyType_;

    setPos(MyPosX, MyPosY);
}

void Runes::advance(int phase)
{

}

QRectF Runes::boundingRect() const
{

    return QRectF(0,0,WT5, HT5);

}

void Runes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MyType==1){

        QPixmap pixmap(":/sprites/RUNAS/Runa1.png");

        painter->drawPixmap(0,0,WT5,HT5,pixmap);

    }else if(MyType==2){

        QPixmap pixmap(":/sprites/RUNAS/Runa2.png");

        painter->drawPixmap(0,0,WT5,HT5,pixmap);

    }else if(MyType==3){

        QPixmap pixmap(":/sprites/RUNAS/Runa3.png");

        painter->drawPixmap(0,0,WT5,HT5,pixmap);

    }

}
