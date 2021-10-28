#include "multiplayer.h"
#include "ui_multiplayer.h"


Multiplayer::Multiplayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Multiplayer)
{

    ui->setupUi(this);

    MyName="Juan1";

    scene = new QGraphicsScene(this); //Motor del aparado grafico

    scene->setSceneRect(0,0,1300,780);

    ui->graphicsView->setSceneRect(0, 0, 1300, 780);

    //scene->setStyle(QStyle )

    ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

    scene->setBackgroundBrush(QImage(":/sprites/FONDOS/fondo7.jpg").scaled(1300, 780));

    BjornSotrack = new PersonajeSotrak(40, 100, 0, 0, 60, 50,2000,0,scene);

    BjornSotrack->setRestarMyPosX(40);

    BjornSotrack->setResastPosY(100);

    BjornSotrack2 = new PersonajeSotrak(1100, 100, 0, 0, 60, 50,2000,0,scene);

    BjornSotrack2->setRestarMyPosX(1100);

    BjornSotrack2->setResastPosY(100);

    scene->addItem(BjornSotrack);

    scene->addItem(BjornSotrack2);

    VelXpersonaje=30;

    VelYpersonaje=35;

    MyNumOfProyectiles=15;

    MyNumOfProyectiles2=15;

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &Multiplayer::OnUpdate);

    connect(ui->CSpushButton, &QPushButton::clicked, this, &Multiplayer::closeMe);

    CreateMyFloor(1);

    OnStartGame();

    ContSwordAttack=0;

    ConTProyectiles=0;

    ContSpriteAttack=0;

    ContProyectilKill=0;

    FlagSwordAttack=false;

    FlagWindow=false;

    FlagSwordAttackActive=false;


    ////2
    ContSwordAttack2=0;

    ConTProyectiles2=0;

    ContSpriteAttack2=0;

    ContProyectilKill2=0;

    ContProyectilKill3=0;

    FlagSwordAttack2=false;

    FlagWindow2=false;

    FlagSwordAttackActive2=false;

    ///

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QString LiFeBS=QString::number(BjornSotrack->getMyLife());
    ui->MyLevelValue->setText(LiFeBS);

    QString ScoreBS=QString::number(BjornSotrack->getMyScore());
    ui->MyScoreValue->setText(ScoreBS);

    QString LiFeBS2=QString::number(BjornSotrack2->getMyLife());
    ui->MyLevelValue->setText(LiFeBS2);

    QString ScoreBS2=QString::number(BjornSotrack2->getMyScore());
    ui->MyScoreValue->setText(ScoreBS2);

    MyAxes.push_back( new Axe(200, 270, 0, 0, 200, 2, 70));

     MyAxes.push_back( new Axe(1100, 270, 0, 0, 200, 2, 70));

    MyAxes.push_back( new Axe(600, 300, 0.05, 30, 200, 1, 90));

    for(auto value: MyAxes){

        scene->addItem(value);
    }

    /////////////////Audio
    ///
    player = new QMediaPlayer();
    // ...
    player->setMedia(QUrl::fromLocalFile("../Ragnarok/music/mario.mp3"));
    player->setVolume(10);
   // player->play();

    espada = new QMediaPlayer();
    // ...
    espada->setMedia(QUrl::fromLocalFile("../Ragnarok/music/espada.mp3"));
    espada->setVolume(50);

}

Multiplayer::~Multiplayer()
{

    delete scene;


    for(auto value: MyFloor){

       delete value;

    }

    delete BjornSotrack;

    delete BjornSotrack2;

    delete GlobalTime;

    delete ui;

}

void Multiplayer::OnStartGame()
{

    GlobalTime->start(5);

}

void Multiplayer::OnUpdate()
{
    scene->advance();

    // * Análisis de colisones con los bloques Floor, por los diferentes lados del bloque.


    for(auto value: MyFloor){

        if(value->collidesWithItem(BjornSotrack)){

            if(value->getMyType()==8){


                if(BjornSotrack->getMyPosY()>=value->getMyPosY()+50 && BjornSotrack->getMyPosY()<=value->getMyPosY()+50 && BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()+60<=value->getMyPosX()+120){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelY(-80);

                                         BjornSotrack->setFlagJump(true);

                                         qDebug()<<"Bloque Colling3"<<endl;
                                         break;


               }

                //Colision por la parte de abajo del bloque si el personaje esta saltando pico izquierdo.
                if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack->getMyPosX()+60>=value->getMyPosX() && BjornSotrack->getMyPosX()+60>=value->getMyPosX()){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelY(-80);

                                         BjornSotrack->setFlagJump(true);

                                         qDebug()<<"Bloque Colling1"<<endl;
                                         break;


               }
                if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack->getMyPosX()<=value->getMyPosX()){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelY(-80);

                                         BjornSotrack->setFlagJump(true);

                                         qDebug()<<"Bloque Colling2"<<endl;
                                         break;


               }

                else{
                    BjornSotrack->setMyAceY(10);

                }

            }else{




            //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho (medio).
            if(BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                    // qDebug()<<"Bloque Colling1"<<endl;
                                    break;
           }
                //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho (medio).
                if(BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                      //  qDebug()<<"Bloque Colling2"<<endl;
                                        break;
               }
                //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho.
                if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                     //   qDebug()<<"Bloque Colling3"<<endl;
                                        break;
               }
                //Colision por la parte de izquierda del bloque si el personaje esta en el suelo.
                if(BjornSotrack->getMyPosX()+60>=value->getMyPosX() && BjornSotrack->getMyPosY()+69>=value->getMyPosY() && BjornSotrack->getMyPosY()<=(value->getMyPosY()+50)){

                              BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());
                             //  qDebug()<<"Bloque Colling4"<<endl;

                              break;

                   }
                  //Colision por la parte de derecha del bloque si el personaje esta en el suelo.
                  if(BjornSotrack->getMyPosX()>=value->getMyPosX()+120 && BjornSotrack->getMyPosY()+69>=value->getMyPosY() && BjornSotrack->getMyPosY()<=(value->getMyPosY()+50)){

                              BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());
                            //   qDebug()<<"Bloque Colling5"<<endl;

                              break;

                   }
                  if(BjornSotrack->getMyPosX()>=value->getMyPosX()+120 && BjornSotrack->getMyPosY()+35>=value->getMyPosY() && BjornSotrack->getMyPosY()+35<=(value->getMyPosY()+50)){

                              BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());
                            //   qDebug()<<"Bloque Colling5"<<endl;

                              break;

                   }


            }



            if(BjornSotrack->getMyPosY()!=BjornSotrack->getMyLastPosY() || BjornSotrack->getMyPosY()!=BjornSotrack->getMyPosY()){

            //    qDebug()<<BjornSotrack->getMyPosX()<<"::"<<BjornSotrack->getMyPosY()<<" vs "<<value->getMyPosX()<<"::"<<value->getMyPosY();

            }

        }
        //Si no se colsiona se mantiene la gravedad.
        else{

          BjornSotrack->setMyAceY(10);

        }
    }
    for(auto value: MyFloor){

        if(value->collidesWithItem(BjornSotrack2)){

            if(value->getMyType()==8){


                if(BjornSotrack2->getMyPosY()>=value->getMyPosY()+50 && BjornSotrack2->getMyPosY()<=value->getMyPosY()+50 && BjornSotrack2->getMyPosX()>=value->getMyPosX()&&BjornSotrack2->getMyPosX()+60<=value->getMyPosX()+120){

                                         BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                                         BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                                          BjornSotrack2->setMyVelY(-80);

                                         BjornSotrack2->setFlagJump(true);

                                         qDebug()<<"Bloque Colling3"<<endl;
                                         break;


               }

                //Colision por la parte de abajo del bloque si el personaje esta saltando pico izquierdo.
                if(BjornSotrack2->getMyPosY()>=value->getMyPosY() && BjornSotrack2->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack2->getMyPosX()+60>=value->getMyPosX() && BjornSotrack2->getMyPosX()+60>=value->getMyPosX()){

                                         BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                                         BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                                          BjornSotrack2->setMyVelY(-80);

                                         BjornSotrack2->setFlagJump(true);

                                         qDebug()<<"Bloque Colling1"<<endl;
                                         break;


               }
                if(BjornSotrack2->getMyPosY()>=value->getMyPosY() && BjornSotrack2->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack2->getMyPosX()<=value->getMyPosX()){

                                         BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                                         BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                                          BjornSotrack2->setMyVelY(-80);

                                         BjornSotrack2->setFlagJump(true);

                                         qDebug()<<"Bloque Colling2"<<endl;
                                         break;


               }

                else{
                    BjornSotrack2->setMyAceY(10);

                }

            }else{




            //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho (medio).
            if(BjornSotrack2->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack2->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack2->getMyPosX()<=value->getMyPosX()){

                                     BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                                     BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                                      BjornSotrack2->setMyVelX(-BjornSotrack2->getMyVelX());

                                    // qDebug()<<"Bloque Colling1"<<endl;
                                    break;
           }
                //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho (medio).
                if(BjornSotrack2->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack2->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack2->getMyPosX()+60>=value->getMyPosX()+120){

                                         BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                                         BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                                          BjornSotrack2->setMyVelX(-BjornSotrack2->getMyVelX());

                                      //  qDebug()<<"Bloque Colling2"<<endl;
                                        break;
               }
                //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho.
                if(BjornSotrack2->getMyPosY()>=value->getMyPosY() && BjornSotrack2->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack2->getMyPosX()+60>=value->getMyPosX()+120){

                                         BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                                         BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                                          BjornSotrack2->setMyVelX(-BjornSotrack2->getMyVelX());

                                     //   qDebug()<<"Bloque Colling3"<<endl;
                                        break;
               }
                //Colision por la parte de izquierda del bloque si el personaje esta en el suelo.
                if(BjornSotrack2->getMyPosX()+60>=value->getMyPosX() && BjornSotrack2->getMyPosY()+69>=value->getMyPosY() && BjornSotrack2->getMyPosY()<=(value->getMyPosY()+50)){

                              BjornSotrack2->setMyVelX(-BjornSotrack2->getMyVelX());
                              BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                              BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());
                             //  qDebug()<<"Bloque Colling4"<<endl;

                              break;

                   }
                  //Colision por la parte de derecha del bloque si el personaje esta en el suelo.
                  if(BjornSotrack2->getMyPosX()>=value->getMyPosX()+120 && BjornSotrack2->getMyPosY()+69>=value->getMyPosY() && BjornSotrack2->getMyPosY()<=(value->getMyPosY()+50)){

                              BjornSotrack2->setMyVelX(-BjornSotrack2->getMyVelX());
                              BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                              BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());
                            //   qDebug()<<"Bloque Colling5"<<endl;

                              break;

                   }
                  if(BjornSotrack2->getMyPosX()>=value->getMyPosX()+120 && BjornSotrack2->getMyPosY()+35>=value->getMyPosY() && BjornSotrack2->getMyPosY()+35<=(value->getMyPosY()+50)){

                              BjornSotrack2->setMyVelX(-BjornSotrack2->getMyVelX());
                              BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                              BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());
                            //   qDebug()<<"Bloque Colling5"<<endl;

                              break;

                   }


            }



            if(BjornSotrack2->getMyPosY()!=BjornSotrack2->getMyLastPosY() || BjornSotrack2->getMyPosY()!=BjornSotrack2->getMyPosY()){

            //    qDebug()<<BjornSotrack->getMyPosX()<<"::"<<BjornSotrack->getMyPosY()<<" vs "<<value->getMyPosX()<<"::"<<value->getMyPosY();

            }
        }
        //Si no se colsiona se mantiene la gravedad.
        else{

          BjornSotrack2->setMyAceY(10);

        }
    }

    QList<QGraphicsItem *> colisiones = scene->collidingItems(BjornSotrack); //bloques

     if(!colisiones.isEmpty()){

         for(auto value: colisiones){

         //Colision con el piso.

         Floor *muros = dynamic_cast<Floor *>(value);

         if(muros){

             if(muros->getMyType()==7 ||muros->getMyType()==8){


                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                     BjornSotrack->setMyVelY(-0.1*BjornSotrack->getMyVelY());
                     BjornSotrack->setMyAceY(-0.1*BjornSotrack->getMyAceY());

                     BjornSotrack->setFlagJump(false);

             }
             else{

                 BjornSotrack->setMyAceY(10);

             }

             }
         }

     }
     else{

         BjornSotrack->setMyAceY(10);

     }

     QList<QGraphicsItem *> colisiones1 = scene->collidingItems(BjornSotrack2); //bloques

      if(!colisiones1.isEmpty()){

          for(auto value: colisiones1){

          //Colision con el piso.

          Floor *muros = dynamic_cast<Floor *>(value);

          if(muros){

              if(muros->getMyType()==7 ||muros->getMyType()==8){


                      BjornSotrack2->setMyPosX(BjornSotrack2->getMyLastPosX());
                      BjornSotrack2->setMyPosY(BjornSotrack2->getMyLastPosY());

                      BjornSotrack2->setMyVelY(-0.1*BjornSotrack2->getMyVelY());
                      BjornSotrack2->setMyAceY(-0.1*BjornSotrack2->getMyAceY());

                      BjornSotrack2->setFlagJump(false);

              }
              else{

                  BjornSotrack2->setMyAceY(10);

              }

              }
          }

      }
      else{

          BjornSotrack2->setMyAceY(10);

      }

     //Timer de animacion de ataque del personaje.

     if(FlagSwordAttack){

     if(ContSwordAttack<=450){

         ContSwordAttack+=5;

         if(ContSwordAttack==200){

             ContSpriteAttack++;

         }
         if(ContSwordAttack==300){

             ContSpriteAttack++;

         }
         if(ContSwordAttack==400){

             ContSpriteAttack++;

         }


         BjornSotrack->SwordAttack(ContSpriteAttack);


     }else{

         ContSwordAttack=0;

         ContSpriteAttack=0;

         FlagSwordAttack=false;

         BjornSotrack->setMyWidht(60);

         BjornSotrack->setMyHeight(70);

         BjornSotrack->RestartSprite();

         espada->stop();

     }
     }
     //Timer de animacion de ataque del personaje.

     if(FlagSwordAttack2){

     if(ContSwordAttack2<=450){

         ContSwordAttack2+=5;

         if(ContSwordAttack2==200){

             ContSpriteAttack2++;

         }
         if(ContSwordAttack2==300){

             ContSpriteAttack2++;

         }
         if(ContSwordAttack2==400){

             ContSpriteAttack2++;

         }


         BjornSotrack2->SwordAttack(ContSpriteAttack2);


     }else{

         ContSwordAttack2=0;

         ContSpriteAttack2=0;

         FlagSwordAttack2=false;

         BjornSotrack2->setMyWidht(60);

         BjornSotrack2->setMyHeight(70);

         BjornSotrack2->RestartSprite();

         //espada->stop();

     }
     }


     if(BjornSotrack->collidesWithItem(BjornSotrack) && FlagSwordAttackActive ){

         if(BjornSotrack->getMyDirection()==1){
         BjornSotrack2->setMyVelX(-40);
         }else{
             BjornSotrack2->setMyVelX(40);
         }

         BjornSotrack2->setMyLife(BjornSotrack2->getMyLife()-BjornSotrack->getMyDamage());

         FlagSwordAttackActive=false;

         if(BjornSotrack2->getMyLife()>2000){

             BjornSotrack2->setMyLife(0);

         }


     }

     if(BjornSotrack2->collidesWithItem(BjornSotrack) && FlagSwordAttackActive2 ){
         if(BjornSotrack2->getMyDirection()==1){
         BjornSotrack->setMyVelX(-40);
         }else{
             BjornSotrack->setMyVelX(40);
         }

         BjornSotrack->setMyLife(BjornSotrack->getMyLife()-BjornSotrack2->getMyDamage());

         FlagSwordAttackActive2=false;

         if(BjornSotrack->getMyLife()>2000){

             BjornSotrack->setMyLife(0);

         }


     }


     //Colision de Ataque Axe vs Personaje.

     for(auto value1: MyAxes){

     if(value1->collidesWithItem(BjornSotrack) && value1->getFlagAttack() ){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);


          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }
          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue_2->setText(LiFeBS);

     }

     }

     //Colision de Ataque Axe vs Personaje2.

     for(auto value1: MyAxes){

     if(value1->collidesWithItem(BjornSotrack2) && value1->getFlagAttack() ){

          BjornSotrack2->EnemyAttackMe(value1->getMyDamage(), 20);


          if(BjornSotrack2->getMyLife()>2000){

              BjornSotrack2->setMyLife(0);

          }

          QString LiFeBS=QString::number(BjornSotrack2->getMyLife());
          ui->MyLevelValue_2->setText(LiFeBS);

     }

     }


     //proyectiles Sotrak2 vs Sotrak


     //if(!ProyectilesSotrak2.empty()){
     int contpr3=0;
     for(auto value1: ProyectilesSotrak2){

     if(value1->collidesWithItem(BjornSotrack)){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 25);

          scene->removeItem(value1);

          delete  value1;

          ProyectilesSotrak2.removeAt(contpr3);

          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }

          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);



     }

     contpr3++;

     }
   //  }

     //proyectiles Sotrak vs Sotrak2

     if(!ProyectilesSotrak.empty()){
     int contpr=0;
     for(auto value1: ProyectilesSotrak){

     if(value1->collidesWithItem(BjornSotrack2)){

          BjornSotrack2->EnemyAttackMe(value1->getMyDamage(), 25);

          scene->removeItem(value1);

          delete  value1;

          ProyectilesSotrak.removeAt(contpr);

          if(BjornSotrack2->getMyLife()>2000){

              BjornSotrack2->setMyLife(0);

          }
          QString LiFeBS=QString::number(BjornSotrack2->getMyLife());
          ui->MyLevelValue_2->setText(LiFeBS);


     }

     contpr++;

     }
    }


     if(!ProyectilesSotrak2.empty()){
     int contpr3=0;
     for(auto value1: ProyectilesSotrak2){

     if(value1->collidesWithItem(BjornSotrack)){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 25);

          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }

          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);



          scene->removeItem(value1);

          delete  value1;

          ProyectilesSotrak2.removeAt(contpr3);


     }

     contpr3++;

     }
     }


     if(!ProyectilesSotrak.empty()){

     if(ContProyectilKill2==2500){

         ContProyectilKill2=0;

         scene->removeItem(ProyectilesSotrak.front());

         delete  ProyectilesSotrak.front();

         ProyectilesSotrak.removeAt(0);
     }
     else{

         ContProyectilKill2+=5;

     }
     }
    if(!ProyectilesSotrak2.empty()){

     if(ContProyectilKill3==2500){

         ContProyectilKill3=0;

         scene->removeItem(ProyectilesSotrak2.front());

         delete  ProyectilesSotrak2.front();

         ProyectilesSotrak2.removeAt(0);
     }
     else{

         ContProyectilKill3+=5;

     }
     }


     QString LiFeBS=QString::number(BjornSotrack->getMyLife());
     ui->MyLevelValue->setText(LiFeBS);

     QString ScoreBS=QString::number(BjornSotrack->getMyScore());
     ui->MyScoreValue->setText(ScoreBS);

     QString LiFeBS2=QString::number(BjornSotrack2->getMyLife());
     ui->MyLevelValue_2->setText(LiFeBS2);

     QString ScoreBS2=QString::number(BjornSotrack2->getMyScore());
     ui->MyScoreValue_2->setText(ScoreBS2);

     if(BjornSotrack->getMyLife()<=0 || BjornSotrack->getMyLife()>2000){

         QMessageBox::information(this, tr("Felicidades!"), tr("El jugador ganador es: %1").arg("Player2"));

         BjornSotrack->setMyLife(1);

         closeMe();



     }else  if(BjornSotrack2->getMyLife()<=0|| BjornSotrack2->getMyLife()>2000){

         QMessageBox::information(this, tr("Felicidades!"), tr("El jugador ganador es: %1").arg("Player1"));

         BjornSotrack2->setMyLife(1);

          closeMe();

     }



}

void Multiplayer::keyPressEvent(QKeyEvent *event)
{

     if(event->key() == Qt::Key_A){

         BjornSotrack->setMyVelX(-30);

         BjornSotrack->setMyDirection(1);

         BjornSotrack->setMyWidht(60);

         BjornSotrack->setMyHeight(70);

         BjornSotrack->ChangeMySprite(event->key());

         BjornSotrack->setContSprites(BjornSotrack->getContSprites()+1);

         if(BjornSotrack->getContSprites()>2)BjornSotrack->setContSprites(0);

     }else if(event->key() == Qt::Key_D){

         BjornSotrack->setMyVelX(30);

         BjornSotrack->setMyDirection(2);

         BjornSotrack->setMyWidht(60);

         BjornSotrack->setMyHeight(70);

         BjornSotrack->ChangeMySprite(event->key());

         BjornSotrack->setContSprites(BjornSotrack->getContSprites()+1);

         if(BjornSotrack->getContSprites()>2)BjornSotrack->setContSprites(0);


     }else if(event->key() == Qt::Key_W && BjornSotrack->getFlagJump()==false){

         BjornSotrack->setMyVelY(-35);

         BjornSotrack->setMyWidht(60);

         BjornSotrack->setMyHeight(70);

         BjornSotrack->ChangeMySprite(event->key());

         BjornSotrack->setFlagJump(true);

     }else if(event->key() == Qt::Key_S){

         //BjornSotrack->setMyVelY(VEL);
        // BjornSotrack->setMyVelX(0);
       //  BjornSotrack->ChangeMySprite(event->key());
       //  band=true;

     }else if(event->key() == Qt::Key_V && FlagSwordAttack==false){


        espada->play();

        BjornSotrack->setMyWidht(BjornSotrack->getMyWidht()+20);

        FlagSwordAttackActive=true;

      //  BjornSotrack->setMyHeight(BjornSotrack->getMyHeight()+10);

        FlagSwordAttack=true;

      }else if(event->key() == Qt::Key_C){


         if(MyNumOfProyectiles>=0){

               qDebug()<<"Drop";

            if(BjornSotrack->getMyDirection()==1){

                ProyectilesSotrak.push_back(new ProyectilBase(BjornSotrack->getMyPosX(), BjornSotrack->getMyPosY()+30, -60, 2, BjornSotrack->getMyMagic()));

                scene->addItem(ProyectilesSotrak.back());


            }else if(BjornSotrack->getMyDirection()==2){

                ProyectilesSotrak.push_back(new ProyectilBase(BjornSotrack->getMyPosX(), BjornSotrack->getMyPosY()+30, 60, 2, BjornSotrack->getMyMagic()));

                scene->addItem(ProyectilesSotrak.back());

            }
                      --MyNumOfProyectiles;

          }


    }


     if(event->key() == Qt::Key_J){

         BjornSotrack2->setMyVelX(-30);

         BjornSotrack2->setMyDirection(1);

         BjornSotrack2->setMyWidht(60);

         BjornSotrack2->setMyHeight(70);

         BjornSotrack2->ChangeMySprite(event->key());

         BjornSotrack2->setContSprites(BjornSotrack2->getContSprites()+1);

         if(BjornSotrack2->getContSprites()>2)BjornSotrack2->setContSprites(0);

     }else if(event->key() == Qt::Key_L){

         BjornSotrack2->setMyVelX(30);

         BjornSotrack2->setMyDirection(2);

         BjornSotrack2->setMyWidht(60);

         BjornSotrack2->setMyHeight(70);

         BjornSotrack2->ChangeMySprite(event->key());

         BjornSotrack2->setContSprites(BjornSotrack2->getContSprites()+1);

         if(BjornSotrack2->getContSprites()>2)BjornSotrack2->setContSprites(0);


     }else if(event->key() == Qt::Key_I && BjornSotrack2->getFlagJump()==false){

         BjornSotrack2->setMyVelY(-35);

         BjornSotrack2->setMyWidht(60);

         BjornSotrack2->setMyHeight(70);

         BjornSotrack2->ChangeMySprite(event->key());

         BjornSotrack2->setFlagJump(true);

     }else if(event->key() == Qt::Key_B){


         if(MyNumOfProyectiles2>=0){

               qDebug()<<"Drop";

            if(BjornSotrack2->getMyDirection()==1){

                ProyectilesSotrak2.push_back(new ProyectilBase(BjornSotrack2->getMyPosX(), BjornSotrack2->getMyPosY()+30, -60, 2, BjornSotrack2->getMyMagic()));

                scene->addItem(ProyectilesSotrak2.back());


            }else if(BjornSotrack2->getMyDirection()==2){

                ProyectilesSotrak2.push_back(new ProyectilBase(BjornSotrack2->getMyPosX(), BjornSotrack2->getMyPosY()+30, 60, 2, BjornSotrack2->getMyMagic()));

                scene->addItem(ProyectilesSotrak2.back());

            }
                      --MyNumOfProyectiles2;

          }


    }else if(event->key() == Qt::Key_N && FlagSwordAttack2==false){


        espada->play();

        BjornSotrack2->setMyWidht(BjornSotrack2->getMyWidht()+20);

        FlagSwordAttackActive2=true;

      //  BjornSotrack->setMyHeight(BjornSotrack->getMyHeight()+10);

        FlagSwordAttack2=true;

      }

}

void Multiplayer::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

       BjornSotrack->setMyVelX(0);


    }else if(event->key() == Qt::Key_D){

       BjornSotrack->setMyVelX(0);

    }

    else if(event->key() == Qt::Key_P){

           //espada->stop();

        }

    if(event->key() == Qt::Key_J){

       BjornSotrack2->setMyVelX(0);


    }else if(event->key() == Qt::Key_L){

       BjornSotrack2->setMyVelX(0);

    }


}

void Multiplayer::closeMe()
{

     emit fin(3);
}

void Multiplayer::CreateMyFloor(int level)
{
    string mapa;
    fstream text;
    string temporal;

   // int prb=50;
    //unsigned long long int tam;
        if(level==1){
        text.open("mapa4.txt",fstream::in);
        }else if(level==2){

            text.open("mapa2.txt",fstream::in);
        }
        else if(level==3){

            text.open("mapa3.txt",fstream::in);

        }

        if(text.is_open()){

            for(int j=1,prb=50; !text.eof();j+=1,prb+=50){

                getline(text,mapa);

            for(int i=0,cuenta=0;cuenta<36;cuenta++,i+=120){
            temporal=mapa[cuenta];
            if(temporal.compare("1")==0){
                MyFloor.push_back(new Floor(i,prb, 7));
                scene->addItem(MyFloor.back());
            }
            else if(temporal.compare("2")==0){
                MyFloor.push_back(new Floor(i,prb, 7));
                scene->addItem(MyFloor.back());
            }
         }
    }
               text.close();

  }

}

void Multiplayer::putVikingsArena()
{
    string Arena;
    fstream text;
    string temporal;
    string atributoagregar;

    string atributesfinal[10];
    int k=-1;

        text.open("D:/Desktop/juanfer ragnarok/Ragnarok/sprites/vikingsarena.txt",fstream::in);
        if(text.is_open()){

            for(int j=1; !text.eof();j+=1){

                getline(text,Arena);

                qDebug() << QString::fromStdString(Arena);

            for(int i=0,cuenta=0;cuenta<int(Arena.size());cuenta++,i++){

                temporal=Arena[cuenta];

                if(temporal.compare(",")!=0){

                   atributoagregar.append(temporal);

                }

                else if(temporal.compare(",")==0){

                    k+=1;

                    atributesfinal[k]=atributoagregar;

                     qDebug() << QString::fromStdString(atributesfinal[k]);

                   atributoagregar.clear();
                }
        }

       k+=1;

       atributesfinal[k]=atributoagregar;

       qDebug() << QString::fromStdString(atributesfinal[k]);

       //Vikings.push_back(new VikingsArena(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5]),stof(atributesfinal[6]),stof(atributesfinal[7]),stof(atributesfinal[8])));

       k=-1;
       atributoagregar.clear();



      // atributesfinal->clear();
      // temporal.clear();

      }

    }

         // text.close();

}

