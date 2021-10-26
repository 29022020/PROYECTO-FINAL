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

QRectF God::boundingRect() const
{
     return QRectF(0,0,20, 30);

}

void God::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/sprites/VIKINGARENA/Viking-removebg-preview.png");

    painter->drawPixmap(0,0,20,30,pixmap);
}
