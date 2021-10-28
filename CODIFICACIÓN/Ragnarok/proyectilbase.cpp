#include "proyectilbase.h"

ProyectilBase::ProyectilBase()
{

}

ProyectilBase::ProyectilBase(float MyPosX_, float MyPosy_, float MyVelX_, unsigned int MyType_,unsigned int Damage_)
{

    MyPosX=MyPosX_;

    MyPosY=MyPosy_;

    MyVelX=MyVelX_;

    MyDamage=Damage_;

    MyType=MyType_;

    ContAttack=0;

    setPos(MyPosX, MyPosY);

}

float ProyectilBase::getMyVelX() const
{
    return MyVelX;
}

void ProyectilBase::setMyVelX(float value)
{
    MyVelX = value;
}

unsigned int ProyectilBase::getMyDamage() const
{
    return MyDamage;
}

void ProyectilBase::setMyDamage(unsigned int value)
{
    MyDamage = value;
}

bool ProyectilBase::getFlagAttack() const
{
    return FlagAttack;
}

void ProyectilBase::setFlagAttack(bool value)
{
    FlagAttack = value;
}

float ProyectilBase::getMyPosY() const
{
    return MyPosY;
}

void ProyectilBase::setMyPosY(float value)
{
    MyPosY = value;
}

float ProyectilBase::getMyPosX() const
{
    return MyPosX;
}

void ProyectilBase::setMyPosX(float value)
{
    MyPosX = value;
}

void ProyectilBase::advance(int phase)
{

    MyVelX = MyVelX + MyAceX*DT6;

    MyPosX = MyPosX + MyVelX*DT6;

    ContAttack+=5;

    if(ContAttack==1500){

        FlagAttack=true;

         ContAttack=0;

    }
    else{

         FlagAttack=false;

    }

    setPos(MyPosX, MyPosY);

}

QRectF ProyectilBase::boundingRect() const
{

    return QRectF(0,0,WT4, HT4);

}

void ProyectilBase::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap(":/sprites/Proyectiles/personajeataque.png");

    painter->drawPixmap(0,0,WT4, HT4,pixmap);

}
