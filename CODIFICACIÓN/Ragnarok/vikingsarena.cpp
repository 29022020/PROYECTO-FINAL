#include "vikingsarena.h"

VikingsArena::VikingsArena()
{

}

VikingsArena::VikingsArena(float MyPosX_, float MyPosY_, float MyInitX_, float MyEndX_, float MyVelX_, float MyVelY_, unsigned int MyType_,unsigned int MyLife_,unsigned int MyDamage_)
{
    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyInitX=MyInitX_;

    MyEndX=MyEndX_;

    MyType=MyType_;

    MyVelX=MyVelX_;

    MyVelY=MyVelY_;

    MyLife=MyLife_;

    MyDamage=MyDamage_;

    ContAttack=0;

    FlagAttack=false;

    setPos(MyPosX, MyPosY);

}

unsigned int VikingsArena::getMyDamage() const
{
    return MyDamage;
}

void VikingsArena::setMyDamage(unsigned int value)
{
    MyDamage = value;
}

bool VikingsArena::getFlagAttack() const
{
    return FlagAttack;
}

void VikingsArena::setFlagAttack(bool value)
{
    FlagAttack = value;
}

unsigned int VikingsArena::getMyLife() const
{
    return MyLife;
}

void VikingsArena::setMyLife(unsigned int value)
{
    MyLife = value;
}

float VikingsArena::getMyVelX() const
{
    return MyVelX;
}

void VikingsArena::setMyVelX(float value)
{
    MyVelX = value;
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
    if(ContAttack<=2000){

        ContAttack+=5;

        if(ContAttack==1000){

            FlagAttack=true;

        }
        else{

             FlagAttack=false;

        }

    }
    else{
        ContAttack=0;
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
