#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MainWindow::moveEnemigo()
{
    int desplazarx,desplazary,posx,posy, direcion=0,indice;
    QVector<int> posicion;
    m->diff(0.5);  //semilla para la probabilidad de aparicion de enemigo
    for(int i=0;i<dificult;i++){ //dificult = 6


    bool difgod=true;
    int god=1;


    if(god==1){  //loki

        int danho = 10;
        int vm= 5;
        int magia= 20;
        int vida = 100;

    }

    if(god==2){//thor


        int danho =15;
        int vm= 10;
        int magia= 25;
        int vida = 100;

    }

    if(god==3){ //odin

        int danho = 20;
        int vm= 15;
        int magia= 30;
        int vida = 100;
    }



        if(enemigo[i]->Vida){
            posx=enemigo[i]->x(); //posicion del enemigo en x
            posy=enemigo[i]->y(); //posicion del enemigo en y

            if(enemigo[i]->direction==-1 || (posx%tam==0  && posy%tam==0)){//si el enemigo se encuentra quieto en el escenario, entonces apartir de
                // de este condicional, se empieza a escoger la direcion aleatoria que tomara el enemigo, mientras su posicion este este alineada con
                //los bloques, de ahi la razon de los modulos entre la posicion del enemigo y el tamaño del escenario
                for(int n=0;n<=3;n++){
                    posicion.push_back(n); // se agregan 4 numeros al vector, estos numeros despues nos diran en que direccion se desplaza el enemigo
                }
                do{
                    desplazarx=0,desplazary=0;// se inicializan

                    if(posicion.size()==0){ //si el vector esta vacio, no hay direcion para desplazarse
                        break;
                    } // indice sera un numero aleatorio que permitira que el enemigo se desplace en cualquier direcion que diga ese numero aleatorio
                    indice=m->aleatorio(0,posicion.size()-1);
                    direcion=posicion[m->aleatorio(0,posicion.size()-1)];// direcion guardara este numero aleatorio que permitira el desplazamiento

                    if(direcion==0) desplazarx=-1; // se desplaza a la izquierda
                    else if(direcion==1) desplazarx=1; // se desplaza a la derecha
                   //else if(direcion==2) desplazary=1; // se desplaza hacia abajo
                   // else if(direcion==3) desplazary=-1; // se desplaza hacia arriba

                    // si en la matriz, esos lugares en el que se quiere ir son bloques o ladrillos, se elimina esa opcion de dezplazamiento
                    if(mat[(posy/tam)-2+desplazary][posx/tam+desplazarx]!=8) {
                        posicion.erase(posicion.begin()+indice);
                    }
                    else break;
                }while(true);
                enemigo[i]->direction=direcion;// el enemigo se mueve con la direcion resultante
                //cout << endl;
            }
            else{
                desplazarx=0,desplazary=0; // se inicializan
                if(enemigo[i]->direction==0){// si el enemigo tiene la opcion de desplazarse de una vez, entonces...
                    desplazarx=-1; //se desplaza a la izquierda
                }
                else if(enemigo[i]->direction==1) {desplazarx=1;}//derecha
                //else if(enemigo[i]->direction==2) {desplazary=1;}//abajo
               // else if(enemigo[i]->direction==3) {desplazary=-1;}//arriba
            }
            if(god==1 and difgod==true){        //VELOCIDAD DE MOVIMIENTO

                int danho = 20;
                int vm= 10;
                int vp=30;
                int magia= 30;
                int vida = 100;

                enemigo[i]->setPos(posx+(desplazarx*vm),posy+(desplazary*vm));
            }

            else if(god==2 and true){        //VELOCIDAD DE MOVIMIENTO

                int danho = 30;
                int vm= 30;
                int magia= 35;
                int vida = 100;

                enemigo[i]->setPos(posx+(desplazarx*vm),posy+(desplazary*vm));
            }

            else if(god==3 and difgod==true){        //VELOCIDAD DE MOVIMIENTO

                int danho = 40;
                int vm= 30;
                int magia= 35;
                int vida = 100;

                enemigo[i]->setPos(posx+(desplazarx*vm),posy+(desplazary*vm));
            }

            else{
            enemigo[i]->setPos(posx+(desplazarx*5),posy+(desplazary*5));//el enemigo aparece en estas posiciones ya que es donde puede moverse
            }
            scene->removeItem(enemigo[i]);// se elimina a enemigo
            scene->addItem(enemigo[i]); // se agrega enemigo
            scene->addItem(poder); // Se agrega poder
            scene->removeItem(player); // se elimina personaje
            scene->addItem(player); // se agrega personaje
            tempo->start(10);
            if(desplazarx==-1||desplazary==-1) enemigo[i]->set_imagen(2+enemigo[i]->sprite);//se mueve los sprites izquierda
            else enemigo[i]->set_imagen(enemigo[i]->sprite); // se mueve los sprites derecha
            enemigo[i]->sprite++;
        }
        else{
            if(scene->items().count(enemigo[i])>0){
                enemigo[i]->Cambiarimg(":/enemigo/Enemigo/EnemigoM.png");
                if(enemigo[i]->muerte>4){
                    scene->removeItem(enemigo[i]);
                    player->puntaje+=100;
                }
                else{
                    enemigo[i]->set_imagen(enemigo[i]->muerte);
                    enemigo[i]->muerte++;
                }
            }
        }
    }
}


void MainWindow::ponerimagen(){

    power->start(30);


    QVector<ataque *> power;
    power=atk;
    int posx=enemigo[0]->x();
    int posy=enemigo[0]->y();

    for(int i=0;i<atk.size();i++){
        atk.at(i)->ecuacion(10);
        //atk[i]->setPos(ui->graphicsView->width()/2+-(atk[i]->Px/10),ui->graphicsView->height()/2-200/10);
        //Px=posx;
        atk[i]->setPos((atk[i]->Px/10)+posx,posy);

    scene->addItem(atk[i]);
   }

}

void MainWindow::agregar()
{
    poder = new ataque;

    atk.push_back(poder);

}


