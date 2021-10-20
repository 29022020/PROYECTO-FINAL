#include "vikingsarena.h"

VikingsArena::VikingsArena()
{

}

VikingsArena::VikingsArena(float MyPosX_, float MyPosY_, float MyInitX_, float MyEndX_, float MyVelX_, float MyVelY_, unsigned int MyType_)
{
    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyInitX=MyInitX_;

    MyEndX=MyEndX_;

    MyType=MyType_;

    MyVelX=MyVelX_;

    MyVelY=MyVelY_;

    setPos(MyPosX, MyPosY);

}

void VikingsArena::advance(int phase)
{
    MyVelX = MyVelX + MyAceX*DT1;

    MyPosX = MyPosX + MyVelX*DT1;

    if(MyPosX>=MyEndX){

        MyVelX=-1*MyVelX;

    }
    if(MyPosX<=MyInitX){

        MyVelX=-1*MyVelX;

    }

    setPos(MyPosX, MyPosY);

}

QRectF VikingsArena::boundingRect() const
{

    return QRectF(-WT6/2,-HT6/2,WT6, HT6);

}

void VikingsArena::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap(":/sprites/VIKINGARENA/Viking-removebg-preview.png");

    painter->drawPixmap(-WT6/2,-HT6/2,WT6,HT6,pixmap);


}
