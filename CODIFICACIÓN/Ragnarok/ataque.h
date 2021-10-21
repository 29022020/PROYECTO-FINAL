#define ATAQUE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class ataque: public QObject,public QGraphicsPixmapItem
{
public:
    ataque();
    void ecuacion(float T);


    float Vx,Vy;
    float Px;
    float Py;

    int get_Px();
    int get_Py();

private:


};

#endif // ATAQUE_H
