#include "personajesotrak.h"

/*PersonajeSotrak::PersonajeSotrak(QObject *parent) : QObject(parent)
{

}*/

PersonajeSotrak::PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX_, float MyVelY_)
{

    MyPosX=MyPosX_;

    MyPosY=MyPosY_;

    MyVelX=MyVelX_;

    MyVelY=MyVelY_;

    MyAceX=0;

    MyAceY=0;

    setPos(MyPosX, MyPosY);

}

void PersonajeSotrak::SwordAttack()
{

}

void PersonajeSotrak::MagicAttack()
{

}

void PersonajeSotrak::advance(int phase)
{

    if(MyVelX>0 && MyVelX !=0){

    MyVelX = MyVelX + MyAceX*DT -2;

    }
    if(MyVelX<0 && MyVelX !=0){

    MyVelX = MyVelX + MyAceX*DT +4;

   }
    if(MyVelY>0 && MyVelY !=0){

    MyVelY = MyVelY + MyAceY*DT -2;

    }
    if(MyVelY<0 && MyVelY !=0){

    MyVelY = MyVelY + MyAceY*DT +4;

   }

    int _px = MyPosX + MyVelX*DT;
    int _py = MyPosY + MyVelY*DT;

    setPos(_px, _py);
}

QRectF PersonajeSotrak::boundingRect() const
{
    return QRectF(0,0,80, 100);
}

void PersonajeSotrak::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/new/prefix1/sprites/personaje/ataquederecha1.png");

    painter->drawPixmap(0,0,80,100,pixmap);

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
/*void PersonajeSotrak::personaje()
{
    setPixmap(QPixmap(abajo[0]).scaled(scaleperx,scalepery));
    setPixmap(QPixmap(arriba[0]).scaled(scaleperx,scalepery));
    setPixmap(QPixmap(derecha[0]).scaled(scaleperx,scalepery));
    setPixmap(QPixmap(izquierda[0]).scaled(scaleperx,scalepery));
    //muerte[7]={":/personaje/Personaje/muerteper1.png",":/personaje/Personaje/muerteper2.png",":/personaje/Personaje/muerteper3.png",":/personaje/Personaje/muerteper4.png",":/personaje/Personaje/muerteper5.png",":/personaje/Personaje/muerteper6.png",":/personaje/Personaje/muerteper7.png"};
    //setPixmap(QPixmap(muertep[0]).scaled(scaleperx,scalepery));
    movimiento[0]=0;
    direccion[0]=true;

}

void PersonajeSotrak::cambio_imagen(short a)
{
    switch (a)
    {
        case 's':
            if(movimiento[0]==2) direccion[0]=false;
            else if(movimiento[0]==0) direccion[0]=true;
            movimiento[0]+=(2*direccion[0]-1);
            setPixmap(QPixmap(abajo[movimiento[0]]).scaled(scaleperx,scalepery));
        break;

        case 'w':
            if(movimiento[0]==2) direccion[0]=false;
            else if(movimiento[0]==0) direccion[0]=true;
            movimiento[0]+=(2*direccion[0]-1);
            setPixmap(QPixmap(arriba[movimiento[0]]).scaled(scaleperx,scalepery));
        break;

        case 'a':
            if(movimiento[0]==2) direccion[0]=false;
            else if(movimiento[0]==0) direccion[0]=true;
            movimiento[0]+=(2*direccion[0]-1);
            setPixmap(QPixmap(izquierda[movimiento[0]]).scaled(scaleperx,scalepery));
        break;

        case 'd':
            if(movimiento[0]==2) direccion[0]=false;
            else if(movimiento[0]==0) direccion[0]=true;
            movimiento[0]+=(2*direccion[0]-1);
            setPixmap(QPixmap(derecha[movimiento[0]]).scaled(scaleperx,scalepery));
        break;

        case 'm':
            if(movimiento[0]==6) direccion[0]=false;
            else if(movimiento[0]==0) direccion[0]=true;
            movimiento[0]+=(6*direccion[0]-1);
            setPixmap(QPixmap(muertep[movimiento[0]]).scaled(scaleperx,scalepery));

        break;

    }
}
*/
