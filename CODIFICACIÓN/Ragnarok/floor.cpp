#include "floor.h"

Floor::Floor()
{

}

Floor::Floor(float MyPosX_, float MyPosY_,unsigned int MyType_)
{

    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyType=MyType_;

    setPos(MyPosX, MyPosY);

}

float Floor::getMyPosY() const
{
    return MyPosY;
}

void Floor::setMyPosY(float value)
{
    MyPosY = value;
}

float Floor::getMyPosX() const
{
    return MyPosX;
}

void Floor::setMyPosX(float value)
{
    MyPosX = value;
}

unsigned int Floor::getMyType() const
{
    return MyType;
}

void Floor::setMyType(unsigned int value)
{
    MyType = value;
}

void Floor::advance(int phase)
{
    
}
QRectF Floor::boundingRect() const
{
    
    return QRectF(0,0,WT7,HT7);
    
}

void Floor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(MyType==1){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo1.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==2){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo1-Bajo.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==3){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo2.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==4){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo2-Bajo.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==5){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo3.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==6){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo3-Bajo.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==7){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo4.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);

    }else if(MyType==8){

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo4-Bajo.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);
    }

}
