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

     MyMass=40;

     Theta=90;

     W=0.5f;

     qDebug()<<W;

     i=1;

     degrees=0.0f;

     MyAceY=0.3f;

     Cont=0;

     ContAttack=0;

     FlagAttack=false;

     //MomentInercia=(1/3)*MyMass*AXEH*AXEH;

     FrecAngular=sqrt((MyMass*10*AXEH)/MomentInercia);

     FrecAngular=0.34;

     qDebug()<<"FA: "<<QString::number(FrecAngular);


     setPos(MyPosX, MyPosY);

}


void Axe::advance(int phase)
{

   /* float A=AXEH;

    MyVelX = MyVelX + MyAceX*DT;

    MyVelY = MyVelY + MyAceY*DT;

    MyPosX = MyPosX + MyVelX*DT+0.5*(MyAceX*DT*DT);
    MyPosY = MyPosY + MyVelY*DT+0.5*(MyAceY*DT*DT);

   // MyPosX =10*qSin(0.02*DT)+MyPosX;

    MyPosY = MyPosY + MyVelY*DT+0.5*(MyAceY*DT*DT);
    */

    if(Cont==10){

        i=i+0.05f;

        float Theta0=Theta*cos(W*i);

        MyPosXnow=MyPosX+90*sin(Theta0*(2*pi/360));
        MyPosYnow=MyPosY+90*cos(Theta0*(2*pi/360));

        setPos(MyPosXnow, MyPosYnow);

      //  qDebug()<<"X: "<<MyPosXnow<<", Y: "<<MyPosXnow<<"Theta: "<<Theta0<<"W: "<<W;

        Cont=0;


    }else{

        Cont++;

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

   // setPos(A*qCos(MyPosX)+800, A*qSin(MyPosX)+200);

}

QRectF Axe::boundingRect() const
{
return QRectF(0,0,40, 40);
}

void Axe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap(":/sprites/AXE/Axe.png");

    painter->drawPixmap(0,0,40,40,pixmap);


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
