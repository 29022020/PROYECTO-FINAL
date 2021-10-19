#include "plataformrandi.h"

PlataformRandI::PlataformRandI()
{

}

PlataformRandI::PlataformRandI(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_, unsigned int MyType_)
{
    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyVelX=MyVelX_;

    MyVelY=MyVelY_;

    MyType=MyType_;

    setPos(MyPosX, MyPosY);

}

void PlataformRandI::advance(int phase)
{


}

QRectF PlataformRandI::boundingRect() const
{

     return QRectF(0,0,WT2, HT2);

}

void PlataformRandI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MyType==1){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Hielo-removebg-preview.png");

        painter->drawPixmap(0,0,WT2,HT2,pixmap);

    }else if(MyType==2){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Roca-removebg-preview.png");

        painter->drawPixmap(0,0,WT2,HT2,pixmap);

    }

}
