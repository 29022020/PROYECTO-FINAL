#include "ataque.h"

ataque::ataque()
{

   QPixmap ataque(":/enemigo/Enemigo/ataqueloki.png");

   setPixmap(ataque.scaled(40,40));




}

void ataque::ecuacion(float T)
{

    Px = Px + (2*T);
    Py = Py + (2*T);

}


int ataque::get_Px()
{
    return Px;
}

int ataque::get_Py()
{
    return Py;
}
