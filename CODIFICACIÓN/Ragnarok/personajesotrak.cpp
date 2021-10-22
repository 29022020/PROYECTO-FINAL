#include "personajesotrak.h"

/*PersonajeSotrak::PersonajeSotrak(QObject *parent) : QObject(parent)
{

}*/

PersonajeSotrak::PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_, QGraphicsScene *MyScene_)
{

    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyVelX=MyVelX_;

    MyVelY=MyVelY_;

    MyAceX=0;

    MyAceY=10;

    ContSprites=0;

    MyDirection=0;

    MyHeight=HT1;

    MyWidht=WT1;

    MyScene=MyScene_;

    FlagJump=false;

    MyPixmap=new QPixmap(RightSprites[1]);

    setPos(MyPosX, MyPosY);

}

PersonajeSotrak::PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_, float MyDamage_, float MyMagic_, float MyLife_, QGraphicsScene *MyScene_)
{
    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyVelX=MyVelX_;

    MyVelY=MyVelY_;

    MyLife=MyLife_;

    MyDamage=MyDamage_;

    MyMagic=MyMagic_;

    MyAceX=0;

    MyAceY=10;

    ContSprites=0;

    MyDirection=0;

    MyHeight=HT1;

    MyWidht=WT1;

    MyScene=MyScene_;

    FlagJump=false;

    CollingEnemy=false;

    MyPixmap=new QPixmap(RightSprites[1]);

    setPos(MyPosX, MyPosY);

}

PersonajeSotrak::~PersonajeSotrak()
{
    delete  MyPixmap;

}

void PersonajeSotrak::SwordAttack(int SpriteNum)
{
    if(MyDirection==2 || MyDirection==0){

    delete MyPixmap;

    if(SpriteNum==0){

        MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataquederecha1.png");

    }
    if(SpriteNum==1){


        MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataquederecha2.png");

    }
    if(SpriteNum==2){


        MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataquederecha3.png");

    }

    if(SpriteNum==3){


        MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataquederecha4.png");

    }

    }
    if(MyDirection==1){

        delete MyPixmap;

        if(SpriteNum==0){

          MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataqueizquierda1.png");

        }
        if(SpriteNum==1){

            MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataqueizquierda2.png");

        }
        if(SpriteNum==2){

            MyPixmap= new QPixmap(":/new/prefix1/Personaje");

        }
        if(SpriteNum==3){

            MyPixmap= new QPixmap(":/new/prefix1/sprites/personaje/ataqueizquierda4.png");

        }

    }

}

void PersonajeSotrak::MagicAttack()
{

}

void PersonajeSotrak::advance(int phase)
{
    MyLastPosX=MyPosX;

    MyLastPosY=MyPosY;

    MyVelX = MyVelX + MyAceX*DT;

    MyVelY = MyVelY + MyAceY*DT;
    if(CollingEnemy==true){
    if(MyVelX>0 && MyVelX !=0){

    MyVelX = MyVelX  -0.5;

    }
    if(MyVelX<0 && MyVelX !=0){

    MyVelX = MyVelX +0.5;

   }
    }

    MyPosX = MyPosX + MyVelX*DT+0.5*(MyAceX*DT*DT);
    MyPosY = MyPosY + MyVelY*DT+0.5*(MyAceY*DT*DT);



    setPos(MyPosX, MyPosY);
}

void PersonajeSotrak::Jump()
{

    MyVelY=-5;

}

void PersonajeSotrak::RestartSprite()
{

    if(MyDirection==1){

    MyPixmap= new QPixmap(LeftSprites[1]);

    }
    if(MyDirection==2 || MyDirection==0){

    MyPixmap= new QPixmap(RightSprites[1]);

    }

}

void PersonajeSotrak::EnemyAttackMe(int Damage_, int Vel)
{
    if(MyDirection==2){

        MyVelX=-Vel;

    }

    else if(MyDirection==1){

        MyVelX=Vel;
    }

    qDebug()<<"Attack from Viking to Bjorn";

    MyLife=MyLife-Damage_;


}

QRectF PersonajeSotrak::boundingRect() const
{
    return QRectF(0,0,MyWidht, MyHeight);
}

void PersonajeSotrak::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->drawPixmap(0,0,MyWidht,MyHeight,*MyPixmap);

}

float PersonajeSotrak::getMyVelX() const
{
    return MyVelX;
}

void PersonajeSotrak::setMyVelX(float value)
{
    MyVelX = value;
}

float PersonajeSotrak::getMyVelY() const
{
    return MyVelY;
}

void PersonajeSotrak::setMyVelY(float value)
{
    MyVelY = value;
}

float PersonajeSotrak::getMyPosX() const
{
    return MyPosX;
}

void PersonajeSotrak::setMyPosX(float value)
{
    MyPosX = value;
}

float PersonajeSotrak::getMyPosY() const
{
    return MyPosY;
}

void PersonajeSotrak::setMyPosY(float value)
{
    MyPosY = value;
}

unsigned int PersonajeSotrak::getMyDirection() const
{
    return MyDirection;
}

void PersonajeSotrak::setMyDirection(unsigned int value)
{
    MyDirection = value;
}

float PersonajeSotrak::getMyLastPosX() const
{
    return MyLastPosX;
}

void PersonajeSotrak::setMyLastPosX(float value)
{
    MyLastPosX = value;
}

float PersonajeSotrak::getMyLastPosY() const
{
    return MyLastPosY;
}

void PersonajeSotrak::setMyLastPosY(float value)
{
    MyLastPosY = value;
}

bool PersonajeSotrak::getFlagJump() const
{
    return FlagJump;
}

void PersonajeSotrak::setFlagJump(bool value)
{
    FlagJump = value;
}

float PersonajeSotrak::getMyAceY() const
{
    return MyAceY;
}

void PersonajeSotrak::setMyAceY(float value)
{
    MyAceY = value;
}

unsigned int PersonajeSotrak::getMyHeight() const
{
    return MyHeight;
}

void PersonajeSotrak::setMyHeight(unsigned int value)
{
    MyHeight = value;
}

unsigned int PersonajeSotrak::getMyWidht() const
{
    return MyWidht;
}

void PersonajeSotrak::setMyWidht(unsigned int value)
{
    MyWidht = value;
}

unsigned int PersonajeSotrak::getContSprites() const
{
    return ContSprites;
}

void PersonajeSotrak::setContSprites(unsigned int value)
{
    ContSprites = value;
}

unsigned int PersonajeSotrak::getMyDamage() const
{
    return MyDamage;
}

void PersonajeSotrak::setMyDamage(unsigned int value)
{
    MyDamage = value;
}

unsigned int PersonajeSotrak::getMyLife() const
{
    return MyLife;
}

void PersonajeSotrak::setMyLife(unsigned int value)
{
    MyLife = value;
}

bool PersonajeSotrak::CollingAnalize(float MyPosX, float MyPosY)
{
    if(MyPosX<0){
        
        //   return true;
        
    }
    
    if(MyPosX>1170){
        
        //    return true;

    }

    if(MyPosY<0){

     //   return true;

    }
    if(MyPosY<=450 && MyPosY <=500 && MyPosX>=600 && MyPosX <=800){

        if(FlagJump==true){

            MyAceY=0;

            MyVelY=0;

            MyVelX=0;

            MyDirection=0;

            FlagJump=false;

        }



        //return true;

    }

    if(MyPosY>500){

        if(FlagJump==true){

            MyAceY=0;

            MyVelY=0;

            MyVelX=0;

            MyDirection=0;

            FlagJump=false;

        }

        return true;

    }
   /* QList<QGraphicsItem *> colisiones1 =MyScene->collidingItems(this);

    if(!colisiones1.isEmpty()){
        for(auto valor: colisiones1){
        PlataformRandI*item = dynamic_cast<PlataformRandI *>(valor);
        if(item){

            MyLastPosX++;
            MyLastPosY++;

            MyVelX=0;
            MyVelY=0;
            MyAceY=0;
          return true;
        }
        }

    }

    colisiones1.clear();*/

    // Plataforms.push_back(new PlataformRandI(200, 500, 0, 0, 2));


     if(MyPosX>=200 && MyPosX<=320 && MyPosY >=500 && MyPosY<=550){

          return true;

     }
    return false;

}

void PersonajeSotrak::ChangeMySprite(char Direction)
{

    switch (Direction)
    {
        case 'W':

        delete MyPixmap;

        if(MyDirection==1){

        MyPixmap= new QPixmap(JumpSprites[1]);
        }
        if(MyDirection==2 || MyDirection==0){

        MyPixmap= new QPixmap(JumpSprites[0]);

        }

        break;

        case 'A':

        delete MyPixmap;

        MyPixmap= new QPixmap(LeftSprites[ContSprites]);

        break;

        case 'D':

        delete MyPixmap;

        MyPixmap= new QPixmap(RightSprites[ContSprites]);

        break;

    }

}
