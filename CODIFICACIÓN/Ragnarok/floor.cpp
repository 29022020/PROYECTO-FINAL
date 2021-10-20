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

        QPixmap pixmap(":/sprites/PLATAFORMAS/Suelo1.png");

        painter->drawPixmap(0,0,WT7,HT7,pixmap);



}
