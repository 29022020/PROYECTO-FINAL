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

   if(MyType==1||MyType==2||MyType==3||MyType==4||MyType==5||MyType==6){
    MyVelX = MyVelX + MyAceX*DT6;

    MyPosX = MyPosX + MyVelX*DT6;
   }else{

       MyVelX = MyVelX + MyAceX*DT6;

       MyPosY= MyPosY + MyVelX*DT6;


   }

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



    if(MyType==1){
     return QRectF(0,0,30, 40);

    }else if(MyType==2){

        return QRectF(0,0,30, 40);

    }
    else if(MyType==3){

             return QRectF(0,0,50,30);
   }
    else if(MyType==4){

            return QRectF(0,0,50,30);

   }
    else if(MyType==5){

            return QRectF(0,0,45,30);

   }
    else if(MyType==6){

             return QRectF(0,0,45,30);
   }
    else if(MyType==7){

             return QRectF(0,0,40, 60);

   }
    else if(MyType==8){

             return QRectF(0,0,50, 60);
   }

}

void ProyectilBase::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MyType==1){
    QPixmap pixmap(":/sprites/Proyectiles/1.png");

    painter->drawPixmap(0,0,30, 40,pixmap);

    }else if(MyType==2){

        QPixmap pixmap(":/sprites/Proyectiles/2.png");

        painter->drawPixmap(0,0,30, 40,pixmap);

    }
    else if(MyType==3){

            QPixmap pixmap(":/sprites/Proyectiles/3.png");

            painter->drawPixmap(0,0,50,30,pixmap);

   }
    else if(MyType==4){

            QPixmap pixmap(":/sprites/Proyectiles/4.png");

            painter->drawPixmap(0,0,50,30,pixmap);

   }
    else if(MyType==5){

            QPixmap pixmap(":/sprites/Proyectiles/5.png");

            painter->drawPixmap(0,0,45,30,pixmap);

   }
    else if(MyType==6){

            QPixmap pixmap(":/sprites/Proyectiles/6.png");

            painter->drawPixmap(0,0,45,30,pixmap);

   }
    else if(MyType==7){

            QPixmap pixmap(":/sprites/Proyectiles/7.png");

            painter->drawPixmap(0,0,40, 60,pixmap);

   }
    else if(MyType==8){

            QPixmap pixmap(":/sprites/Proyectiles/8.png");

            painter->drawPixmap(0,0,50, 60,pixmap);

   }

}
