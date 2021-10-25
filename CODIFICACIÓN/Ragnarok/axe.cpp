#include "axe.h"

Axe::Axe()
{

}

Axe::Axe(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_, unsigned int MyDamage_)
{
    MyPosX=MyPosX_;

     MyPosY=MyPosY_;

     MyVelX=0.5;

     MyVelY=MyVelY_;

     MyDamage=MyDamage_;

     MyMass=40;

     degrees=0.0f;

     MyAceY=0.3f;

     //MomentInercia=(1/3)*MyMass*AXEH*AXEH;

     FrecAngular=sqrt((MyMass*10*AXEH)/MomentInercia);

     FrecAngular=0.34;

     qDebug()<<"FA: "<<QString::number(FrecAngular);


     setPos(MyPosX, MyPosY);

}


void Axe::advance(int phase)
{

    float A=AXEH;

    MyVelX = MyVelX + MyAceX*DT;

    MyVelY = MyVelY + MyAceY*DT;

    MyPosX = MyPosX + MyVelX*DT+0.5*(MyAceX*DT*DT);
    MyPosY = MyPosY + MyVelY*DT+0.5*(MyAceY*DT*DT);

   // MyPosX =10*qSin(0.02*DT)+MyPosX;

    MyPosY = MyPosY + MyVelY*DT+0.5*(MyAceY*DT*DT);

    setPos(A*qCos(MyPosX)+800, A*qSin(MyPosX)+200);

}

QRectF Axe::boundingRect() const
{
return QRectF(0,0,AXEW, AXEH);
}

void Axe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap(":/sprites/AXE/Axe.png");

    painter->drawPixmap(0,0,AXEW,AXEH,pixmap);


}
