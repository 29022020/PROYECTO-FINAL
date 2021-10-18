#ifndef GOD_H
#define GOD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class god
{
public:
    god();


    void ataques(int num);
    void movimiento();
    void atributos();
    void sonidos();
    void dificultadgod();
    void drop();

 private:
    //QPixmap originalBomba, img,rango,originalRango,imgBloque,bomba2;
    int scalex=40,scaley=40;


   };


#endif // GOD_H
