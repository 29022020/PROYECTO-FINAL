#include "axe.h"

Axe::Axe()
{

}

Axe::Axe(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_, unsigned int MyDamage_)
{
     MyPosX=800;

     MyPosY=200;

     MyVelX=10;

     MyPosXnow=0;

     MyPosXnow=0;

     MyVelY=MyVelY_;

     MyDamage=MyDamage_;

     Theta=90;

     W=0.5f;

     qDebug()<<W;

     i=1;

     MyAceY=0.3f;

     Cont=0;

     ContAttack=0;

     FlagAttack=false;

     FrecAngular=0.34;

     qDebug()<<"FA: "<<QString::number(FrecAngular);


     setPos(MyPosX, MyPosY);

}

Axe::Axe(float MyPosX_, float MyPosy, float MyVelX_, float MyVelY_, unsigned int MyDamage_, unsigned int MyType_, unsigned int MyRadio_)
{

    MyPosX=MyPosX_;

    MyPosY=MyPosy;

    MyVelX=MyVelX_;

    MyType=MyType_;
    if(MyType==2){
    MyPosXnow=0;

    MyPosXnow=0;
    }else{
        MyPosXnow=MyPosX;

        MyPosYnow=MyPosY;
    }

    MyVelY=MyVelY_;

    MyDamage=MyDamage_;

    Theta=90;

    W=0.5f;

    i=1;

    Radio=MyRadio_;

    MyAceY=0.3f;

    Cont=0;

    ContAttack=0;

    FlagAttack=false;

    FrecAngular=0.34;

    setPos(MyPosX, MyPosY);

}


void Axe::advance(int phase)
{

   if(MyType==1){
    MyVelX = MyVelX + MyAceX*DT;

    MyVelY = MyVelY + MyAceY*DT;

    MyPosX = MyPosX + MyVelX*DT+0.5*(MyAceX*DT*DT);

    setPos(Radio*qCos(MyPosX)+MyPosXnow, Radio*qSin(MyPosX)+MyPosYnow);
   }else{

    if(Cont==10){

        i=i+0.05f;

        float Theta0=Theta*cos(W*i);

        MyPosXnow=MyPosX+90*sin(Theta0*(2*pi/360));
        MyPosYnow=MyPosY+90*cos(Theta0*(2*pi/360));

        setPos(MyPosXnow, MyPosYnow);

        Cont=0;


    }else{

        Cont++;

    }
   }
    ContAttack+=5;

    if(ContAttack==1500){

        FlagAttack=true;

         ContAttack=0;

    }
    else{

         FlagAttack=false;

    }

}

QRectF Axe::boundingRect() const
{
return QRectF(0,0,40, 70);
}

void Axe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap(":/sprites/AXE/Axe.png");

    painter->drawPixmap(0,0,40,70,pixmap);


}

bool Axe::getFlagAttack() const
{
    return FlagAttack;
}

void Axe::setFlagAttack(bool value)
{
    FlagAttack = value;
}

int Axe::getMyDamage() const
{
    return MyDamage;
}

void Axe::setMyDamage(int value)
{
    MyDamage = value;
}
