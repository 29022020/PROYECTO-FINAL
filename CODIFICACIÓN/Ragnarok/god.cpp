#include "god.h"


God::God(float MyPosX_, float MyPosY_, float MyInitX_, float MyEndX_, float MyVelX_, float MyVelY_, unsigned int MyType_, unsigned int MyLife_, unsigned int MyDamage_, unsigned int MyMagic_)
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

float God::getMyPosY() const
{
    return MyPosY;
}

void God::setMyPosY(float value)
{
    MyPosY = value;
}

float God::getMyPosX() const
{
    return MyPosX;
}

void God::setMyPosX(float value)
{
    MyPosX = value;
}

unsigned int God::getMyType() const
{
    return MyType;
}

void God::setMyType(unsigned int value)
{
    MyType = value;
}

bool God::getFlagAttack() const
{
    return FlagAttack;
}

void God::setFlagAttack(bool value)
{
    FlagAttack = value;
}

unsigned int God::getMyDamage() const
{
    return MyDamage;
}

void God::setMyDamage(unsigned int value)
{
    MyDamage = value;
}

int God::getMyLife() const
{
    return MyLife;
}

void God::setMyLife(int value)
{
    MyLife = value;
}

float God::getMyVelX() const
{
    return MyVelX;
}

void God::setMyVelX(float value)
{
    MyVelX = value;
}

void God::advance(int phase)
{
    MyVelX = MyVelX + MyAceX*0.01;

    MyPosX = MyPosX + MyVelX*0.01;

    if(MyPosX>=MyEndX){

        MyVelX=-1*MyVelX;

    }
    if(MyPosX<=MyInitX){

        MyVelX=-1*MyVelX;

    }
    ContAttack+=5;

    if(ContAttack==2500){

        FlagAttack=true;

         ContAttack=0;

    }
    else{

         FlagAttack=false;

    }
    setPos(MyPosX, MyPosY);


}

QRectF God::boundingRect() const
{
     return QRectF(0,0,GW, GH);

}

void God::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MyType==1){

        QPixmap pixmap(":/sprites/Gods/loki.png");

        painter->drawPixmap(0,0,GW, GH,pixmap);

    }else if(MyType==2){

        QPixmap pixmap(":/sprites/Gods/Thor.png");

        painter->drawPixmap(0,0,GW, GH,pixmap);

    }else if(MyType==3){

        QPixmap pixmap(":/sprites/Gods/odin.png");

        painter->drawPixmap(0,0,GW, GH,pixmap);

    }
}
