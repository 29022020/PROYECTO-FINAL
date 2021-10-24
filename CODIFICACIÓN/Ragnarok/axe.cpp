#include "axe.h"

Axe::Axe()
{

}

Axe::Axe(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_, unsigned int MyDamage_)
{
    MyPosX=MyPosX_;

     MyPosY=MyPosY_;

     MyVelX=MyVelX_;

     MyVelY=MyVelY_;

     MyDamage=MyDamage_;

     MyMass=40;

     degrees=0.0f;

     //MomentInercia=(1/3)*MyMass*AXEH*AXEH;

    FrecAngular=sqrt((MyMass*10*AXEH)/MomentInercia);

     FrecAngular=0.34;

     qDebug()<<"FA: "<<QString::number(FrecAngular);


     setPos(MyPosX, MyPosY);

}


void Axe::advance(int phase)
{

    float A=AXEH;

    MyPosX=10*qCos(20*DT);

    //float radians= qDegreesToRadians(degrees);

    setPos(A*qCos(degrees)+MyPosX, A*qSin(degrees)+MyPosY);

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
