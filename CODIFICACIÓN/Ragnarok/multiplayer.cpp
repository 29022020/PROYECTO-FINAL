#include "multiplayer.h"
#include "ui_multiplayer.h"


Multiplayer::Multiplayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Multiplayer)
{

    ui->setupUi(this);

    MyName="Juan1";

    scene = new QGraphicsScene(this); //Motor del aparado grafico

    scene->setSceneRect(0,0,1340,780);

    ui->graphicsView->setSceneRect(0, 0, 1340, 780);

    //scene->setStyle(QStyle )

    ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

  //  scene->setBackgroundBrush(Qt::darkGreen);

    scene->setBackgroundBrush(QImage(":/sprites/FONDOS/fondo7.jpg").scaled(1340, 780));

    BjornSotrack = new PersonajeSotrak(0, 350, 0, 0, 20, 0,2000,0,scene);

    BjornSotrack2 = new PersonajeSotrak(0, 200, 0, 0, 20, 0,2000,0,scene);

    Vikings.push_back(new VikingsArena(900, 320,  800, 1200,20, 0,2, 200, 15));

    Items.push_back(new PowerUpItems(900, 320, 1));

    Items.push_back(new PowerUpItems(700, 420, 5));

    MyRunes.push_back(new Runes(740, 420, 2));

    MyRunes.push_back(new Runes(940, 300, 1));

    Vikings.push_back(new VikingsArena(700, 420,  600, 800,20, 0,2, 200, 15));

    scene->addItem(BjornSotrack);

    scene->addItem(BjornSotrack2);

    VelXpersonaje=30;

    VelYpersonaje=35;

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &Multiplayer::OnUpdate);

    //connect(AuxTime, &QTimer::timeout, this, &Multiplayer::OnUpdate2);


  //  connect(GlobalTime, &QTimer::timeout, this, &LevelWindow::OnUpdate);

 //   connect(ui->CSpushButton, &QPushButton::clicked, this, &LevelWindow::closeMe);

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

    ///Axe
    MyAxes.push_back( new Axe(20, 200, 0, 0, 20));

    scene->addItem(MyAxes.back());

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

    if(BjornSotrack->getMyPosX()>=1200){

    ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX()-600, 0, 1240, 680);

    }else{

        ui->graphicsView->setSceneRect(0, 0, 1240, 680);

    }

}

Multiplayer::Multiplayer(QWidget *parent, QString User,float MyPosX, int MyPosY, float MyVelX, int MyVelY,int Score, int level, float damage, float magic, float life)
    : QMainWindow(parent)
    , ui(new Ui::Multiplayer)
{
    ui->setupUi(this);

    MyName=User;

    MyLevel=level;

    if(MyLevel==1){

        scene = new QGraphicsScene(this); //Motor del aparado grafico

        scene->setSceneRect(0,0,4000,700);

        ui->graphicsView->setSceneRect(0, 0, 1240, 680);

        ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

        scene->setBackgroundBrush(QImage(":/sprites/FONDOS/fondo.jpg").scaled(1240, 680));

    }else if(MyLevel==2){

        scene = new QGraphicsScene(this); //Motor del aparado grafico

        scene->setSceneRect(0,0,8000,700);

        ui->graphicsView->setSceneRect(0, 0, 1240, 680);

        ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

        scene->setBackgroundBrush(QImage(":/sprites/FONDOS/fondo2.jpg").scaled(1240, 680));


    }else if(MyLevel==3){

        scene = new QGraphicsScene(this); //Motor del aparado grafico

        scene->setSceneRect(0,0,10000,700);

        ui->graphicsView->setSceneRect(0, 0, 1240, 680);

        ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

        scene->setBackgroundBrush(QImage(":/sprites/FONDOS/fondo4.jpg").scaled(1240, 680));


    }

    qDebug()<<"PosX: "<<MyPosX<<", PosY: "<<MyPosY;
    qDebug()<<"VelX: "<<VelXpersonaje<<", VelY: "<<VelYpersonaje;
    qDebug()<<"Score: "<<Score;
    qDebug()<<"Life: "<<life;
    qDebug()<<"Magic: "<<magic;
    qDebug()<<"Damage: "<<damage;
    qDebug()<<"Level: "<<MyLevel;

    BjornSotrack = new PersonajeSotrak(MyPosX, MyPosY, 0, 0, damage, magic,life,Score,scene);

    // PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX, float MyVelX, float MyDamage, float MyMagic, float MyLife_,int MyScore_,QGraphicsScene *MyScene_);

    scene->addItem(BjornSotrack);

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &Multiplayer::OnUpdate);

    //connect(ui->SpushButton, &QPushButton::clicked, this, &LevelWindow::SaveMatch);

    //connect(ui->CSpushButton, &QPushButton::clicked, this, &LevelWindow::closeMe);

    CreateMyFloor(level);

    OnStartGame();

    ContSwordAttack=0;

    ContSpriteAttack=0;

    FlagSwordAttack=false;

    FlagWindow=false;

    FlagSwordAttackActive=false;

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QString LiFeBS=QString::number(BjornSotrack->getMyLife());
    ui->MyLevelValue->setText(LiFeBS);

    QString ScoreBS=QString::number(BjornSotrack->getMyScore());
    ui->MyScoreValue->setText(ScoreBS);

    //  player->play();

    espada = new QMediaPlayer();
      // ...
    espada->setMedia(QUrl::fromLocalFile("../Ragnarok/music/espada.mp3"));

    espada->setVolume(50);

}

Multiplayer::~Multiplayer()
{

    delete scene;

    for(auto value: Vikings){

        delete  value;
    }
    for(auto value: ProyectilesGod){

        delete  value;
    }


    for(auto value: MyFloor){

       delete value;

    }

    for(auto value: Items){

        delete value;
    }
    for(auto value: Gods){

        delete value;
    }

    for(auto value: MyRunes){

       delete value;

    }

    delete  Plataform;

 //   delete  MyAxe;

    delete BjornSotrack;

    delete GlobalTime;

    delete ui;

}

void Multiplayer::OnStartGame()
{

    GlobalTime->start(5);

   /// AuxTime->start(5);

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


         /* if(BjornSotrack->getMyPosY()>=value->getMyPosY()&& BjornSotrack->getMyPosY()+70<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()){

                                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                               BjornSotrack->setMyVelY(-80);

                                              qDebug()<<"Bloque Colling2"<<endl;
                                              break;


           }
          if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()){

                                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                               BjornSotrack->setMyVelY(-80);

                                            qDebug()<<"Bloque Colling3"<<endl;
                                              break;


           }
            ////Colision por la parte de izquierda del bloque si el personaje esta saltando.
                      if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()>=value->getMyPosX()+120){

                                               BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                               BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                                BjornSotrack->setMyVelY(-80);

                                               qDebug()<<"Bloque Colling4"<<endl;
                                               break;


                     }

                     //Colision por la parte de abajo del bloque si el personaje esta saltando pico izquierdo.
                     if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()<=value->getMyPosX()+120){

                                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                               BjornSotrack->setMyVelY(-80);

                                              BjornSotrack->setFlagJump(true);

                                              qDebug()<<"Bloque Colling5"<<endl;
                                              break;


                    }
                     if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()){

                                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                               BjornSotrack->setMyVelY(-80);

                                              BjornSotrack->setFlagJump(true);

                                              qDebug()<<"Bloque Colling10"<<endl;
                                              break;


                    }

                    //Colision por la parte de derecha del bloque si el personaje esta saltando.
                    if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60<=value->getMyPosX()+120){

                                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                                BjornSotrack->setMyVelY(-80);

                                             qDebug()<<"Bloque Colling6"<<endl;
                                              break;

                     }
                     //Colision por la parte de izquierda del bloque si el personaje esta saltando.
                     if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()<=value->getMyPosX()+120){

                                              BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                              BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                               BjornSotrack->setMyVelY(-80);
                                              BjornSotrack->setFlagJump(true);

                                              qDebug()<<"Bloque Colling7"<<endl;
                                              break;

                    }*/

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

           /* ////Colision por la parte de izquierda del bloque si el personaje esta saltando.
            if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelY(-80);

                                //   qDebug()<<"Bloque Colling1"<<endl;
                                     break;


           }

           //Colision por la parte de abajo del bloque si el personaje esta saltando pico izquierdo.
           if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45&&BjornSotrack->getMyPosX()<=value->getMyPosX()){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                     BjornSotrack->setMyVelY(-80);

                                    BjornSotrack->setFlagJump(true);

                                   // qDebug()<<"Bloque Colling2"<<endl;
                                    break;


          }
          //Colision por la parte de derecha del bloque si el personaje esta saltando.
          if(BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack->getMyPosY()<=value->getMyPosY()+45&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelY(-80);

                                      BjornSotrack->setFlagJump(true);

                                   // qDebug()<<"Bloque Colling5"<<endl;
                                    break;

           }
           //Colision por la parte de izquierda del bloque si el personaje esta saltando.
           if(BjornSotrack->getMyPosY()+70>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+45&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120&&BjornSotrack->getMyPosX()<=value->getMyPosX()){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                     BjornSotrack->setMyVelY(-80);
                                    BjornSotrack->setFlagJump(true);

                                  //  qDebug()<<"Bloque Colling3"<<endl;
                                    break;

          }*/



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

     //Colision de Ataque vikingos vs Personaje.

     int cont=0;

     for(auto value1: Vikings){

     if(value1->collidesWithItem(BjornSotrack) && FlagSwordAttackActive ){

         value1->setMyVelX(-value1->getMyVelX());

         value1->setMyLife(value1->getMyLife()-BjornSotrack->getMyDamage());

         FlagSwordAttackActive=false;

     }

     if(value1->collidesWithItem(BjornSotrack) && value1->getFlagAttack() ){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);
          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);
     }

     if(value1->getMyLife()<=0){
         if(value1->getMyType()!=0){
         if(BjornSotrack->getMyDirection()==2){
         Items.push_back(new PowerUpItems(value1->getMyPosX()+3, value1->getMyPosY()-10, value1->getMyType()) );
         }else{
              Items.push_back(new PowerUpItems(value1->getMyPosX()-3, value1->getMyPosY()-10, value1->getMyType()) );
         }
         }
         scene->removeItem(value1);
         scene->addItem(Items.back());
         BjornSotrack->setMyScore(BjornSotrack->getMyScore()+100);
         QString ScoreBS=QString::number(BjornSotrack->getMyScore());
         ui->MyScoreValue->setText(ScoreBS);

         delete value1;

        Vikings.removeAt(cont);

     }

     cont++;

     }
     //Attaks Sotraks

     if(BjornSotrack->collidesWithItem(BjornSotrack) && FlagSwordAttackActive ){

         if(BjornSotrack->getMyDirection()==1){
         BjornSotrack2->setMyVelX(-40);
         }else{
             BjornSotrack2->setMyVelX(40);
         }

         BjornSotrack2->setMyLife(BjornSotrack2->getMyLife()-BjornSotrack->getMyDamage());

         FlagSwordAttackActive=false;


     }

     if(BjornSotrack2->collidesWithItem(BjornSotrack) && FlagSwordAttackActive2 ){
         if(BjornSotrack2->getMyDirection()==1){
         BjornSotrack->setMyVelX(-40);
         }else{
             BjornSotrack->setMyVelX(40);
         }

         BjornSotrack->setMyLife(BjornSotrack->getMyLife()-BjornSotrack2->getMyDamage());

         FlagSwordAttackActive2=false;


     }



     //Colision de Ataque Dioses vs Personaje.

     int cont3=0;

     for(auto value2: Gods){

     if(value2->collidesWithItem(BjornSotrack) && FlagSwordAttackActive ){

         value2->setMyVelX(-value2->getMyVelX());

         value2->setMyLife(value2->getMyLife()-BjornSotrack->getMyDamage());

         FlagSwordAttackActive=false;

     }

     if(value2->collidesWithItem(BjornSotrack) && value2->getFlagAttack() ){
          //Sprite
          BjornSotrack->EnemyAttackMe(value2->getMyDamage(), 20);
          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);
     }

     if(value2->getMyLife()<=0){
         if(value2->getMyType()!=0){
         if(BjornSotrack->getMyDirection()==2){
         MyRunes.push_back(new Runes(value2->getMyPosX()+3, value2->getMyPosY()-10, value2->getMyType()) );
         }else{
              MyRunes.push_back(new Runes(value2->getMyPosX()-3, value2->getMyPosY()-10, value2->getMyType()) );
         }
         }
         scene->removeItem(value2);
         scene->addItem(MyRunes.back());
         BjornSotrack->setMyScore(BjornSotrack->getMyScore()+100);
         QString ScoreBS=QString::number(BjornSotrack->getMyScore());
         ui->MyScoreValue->setText(ScoreBS);

         delete value2;

        Gods.removeAt(cont3);

     }

     cont3++;

     }
     //Colision de Ataque Axe vs Personaje.

     for(auto value1: MyAxes){

     if(value1->collidesWithItem(BjornSotrack) && value1->getFlagAttack() ){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);
          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue_2->setText(LiFeBS);
     }

     }

     //Colision de Ataque Axe vs Personaje2.

     for(auto value1: MyAxes){

     if(value1->collidesWithItem(BjornSotrack2) && value1->getFlagAttack() ){

          BjornSotrack2->EnemyAttackMe(value1->getMyDamage(), 20);
          QString LiFeBS=QString::number(BjornSotrack2->getMyLife());
          ui->MyLevelValue_2->setText(LiFeBS);
     }

     }
     //Colision de Ataque Proyectiles vs Personaje.

     int contp=0;
     for(auto value1: ProyectilesGod){

     if(value1->collidesWithItem(BjornSotrack) && value1->getFlagAttack() ){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);
          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);


          scene->removeItem(value1);

          delete  value1;

          ProyectilesGod.removeAt(contp);


     }

     contp++;

     }

     //Colision de Items vs Personaje.

     int cont1=0;

     for(auto value2: Items){

         if(value2->collidesWithItem(BjornSotrack)){

             scene->removeItem(value2);
             if(value2->getMyType()!=5){

                BjornSotrack->PowerUp(value2->getMyType());

             }else{

                 int VelXpersonajeAux=VelXpersonaje+5;

                 int VelYpersonajeAux=VelYpersonaje+5;

                 if(VelXpersonajeAux<=60){

                     VelXpersonaje+=5;
                 }

                 if(VelYpersonajeAux<=50){

                    // VelYpersonaje+=5;
                 }

                 qDebug()<<"VelX: "<<VelXpersonaje<<" VelY: "<<VelYpersonaje;

             }

              QString LiFeBS=QString::number(BjornSotrack->getMyLife());

              ui->MyLevelValue->setText(LiFeBS);

             delete value2;

            Items.removeAt(cont1);

         }

         cont1++;
     }

     //Colision de Runas vs Personaje.

     int cont2=0;

     for(auto value3: MyRunes){

         if(value3->collidesWithItem(BjornSotrack)){

            scene->removeItem(value3);

            BjornSotrack->RunesItems(value3->getMyType());

            delete value3;

            MyRunes.removeAt(cont2);

         }

         cont2++;
     }

     QString LiFeBS=QString::number(BjornSotrack->getMyLife());
     ui->MyLevelValue->setText(LiFeBS);

     QString ScoreBS=QString::number(BjornSotrack->getMyScore());
     ui->MyScoreValue->setText(ScoreBS);

     QString LiFeBS2=QString::number(BjornSotrack2->getMyLife());
     ui->MyLevelValue_2->setText(LiFeBS2);

     QString ScoreBS2=QString::number(BjornSotrack2->getMyScore());
     ui->MyScoreValue_2->setText(ScoreBS2);


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

     }else if(event->key() == Qt::Key_P && FlagSwordAttack==false){


        espada->play();

        BjornSotrack->setMyWidht(BjornSotrack->getMyWidht()+20);

        FlagSwordAttackActive=true;

      //  BjornSotrack->setMyHeight(BjornSotrack->getMyHeight()+10);

        FlagSwordAttack=true;

      }

    /*if(BjornSotrack->getMyPosX()>=1240&&BjornSotrack->getMyPosX()<2480 && FlagWindow==false){

     ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX(), 0, 1240, 680);
     FlagWindow=true;

     } else if(BjornSotrack->getMyPosX()>=2480&&BjornSotrack->getMyPosX()<3720&& FlagWindow==false){

         ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX(), 0, 1240, 680);

         FlagWindow=true;

     }else if(BjornSotrack->getMyPosX()>=3720 && BjornSotrack->getMyPosX()>=4000 && FlagWindow==false){

         ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX(), 0, 1240, 680);

         FlagWindow=true;

     }
     else{
              ui->graphicsView->setSceneRect(0, 0, 1240, 680);
     }*/
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

     }else if(event->key() == Qt::Key_S){

         //BjornSotrack->setMyVelY(VEL);
        // BjornSotrack->setMyVelX(0);
       //  BjornSotrack->ChangeMySprite(event->key());
       //  band=true;

     }else if(event->key() == Qt::Key_M && FlagSwordAttack2==false){


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

    else if(event->key() == Qt::Key_P){

           //espada->stop();

        }

}

void Multiplayer::closeMe()
{
     //SaveMatch();

     //this->close();

     emit fin(3);
}

void Multiplayer::CreateMyFloor(int level)
{

    //string mapa="0000000000000011110000000000000000000000000000000111100000000000010000000000000000000111100000000000010000000000000000000111101000000000010000000000000000000111101000000000010000000000000002220111101000000000010000000000000021110111101000000000010000000000000211110111101000000000010000000000002111110000001000000020010000000000201111110000001002002000010000001110001111110111111000000000011111111110001111110111111000000000011111111111";
              //  "
   // |
    /* string mapa="000000000000000000000000222222000000000000000000000000000000111111000000000000000000000000000000111111000000000000000000000000000000111111000000000000000222200000000000111111000002000000002111120000000000000000000002000000021111112000000000000000000021000000211111111000000000000000000211000002111111111000000000111111111111000021111111111000011111111111111111000211111111111020011111111111111111222111111111111000011111111111111111";
     string temporal;

         for(int i=0,j=1,prb=50; j<mapa.size(); i+=120,j+=1){

             if(j==36 || j==72||j==108||j==144||j==180||j==216||j==252||j==288||j==324||j==360||j==396){
                 prb+=50;

                 i=0;

             }*/
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

       Vikings.push_back(new VikingsArena(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5]),stof(atributesfinal[6]),stof(atributesfinal[7]),stof(atributesfinal[8])));

       k=-1;
       atributoagregar.clear();



      // atributesfinal->clear();
      // temporal.clear();

      }

    }

         // text.close();

}

/*
void LevelWindow::CreateMyFloor(int level)
{
  QString mapa="0000000000000011110000000000000000000000000000000111100000000000010000000000000000000111100000000000010000000000000000000111101000000000010000000000000000000111101000000000010000000000000002220111101000000000010000000000000021110111101000000000010000000000000211110111101000000000010000000000002111110000001000000020010000000000201111110000001002002000010000001110001111110111111000000000011111111110001111110111111000000000011111111111";
              //  "
   // |                                     |                                    |                                   |                                      |                                      |                                      |                                      |                                                      |                                   |                                      |"


    //QString mapa="000000000000000000000000222222000000000000000000000000000000111111000000000000000000000000000000111111000000000000000000000000000000111111000000000000000222200000000000111111000002000000002111120000000000000000000002000000021111112000000000000000000021000000211111111000000000000000000211000002111111111000000000111111111111000021111111111000011111111111111111000211111111111020011111111111111111222111111111111000011111111111111111";
    QString temporal;

        for(int i=0,j=1,prb=50; j<int(mapa.size()); i+=120,j+=1){

            if(j==36 || j==72||j==108||j==144||j==180||j==216||j==252||j==288||j==324||j==360||j==396){
                prb+=50;

                i=0;

            }
            temporal=mapa[j];
            if(temporal.compare("1")==0){
                MyFloor.push_back(new Floor(i,prb, 7));
                scene->addItem(MyFloor.back());
            }

            else if(temporal.compare("2")==0){
                MyFloor.push_back(new Floor(i,prb, 7));
                scene->addItem(MyFloor.back());
            }

          }
  /* QString b="2. 23, 45, 67, 89, 20, 3, 200, 15";
    int A=b.toFloat();



    for(int i=0; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,500, 8));
        scene->addItem(MyFloor.back());

    }


    for(int i=0; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,550, 8));
        scene->addItem(MyFloor.back());

    }
    for(int i=0; i<4000; i+=120){

        MyFloor.push_back(new Floor(i,600, 8));
        scene->addItem(MyFloor.back());

    }

    for(int i=400; i<3000; i+=120){

        MyFloor.push_back(new Floor(i,450, 7));
        scene->addItem(MyFloor.back());

    }
    //MyFloor.push_back(new Floor(120,450, 7));
   // scene->addItem(MyFloor.back());

  //  MyFloor.push_back(new Floor(240,300, 7));
   // scene->addItem(MyFloor.back());

    for(int i=800; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,400, 7));
        scene->addItem(MyFloor.back());

    }
    for(int i=800; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,350, 7));
        scene->addItem(MyFloor.back());

    }
    for(int i=2000; i<3000; i+=120){

        MyFloor.push_back(new Floor(i,350, 7));
        scene->addItem(MyFloor.back());

    }




        MyFloor.push_back(new Floor(490,300, 8));
        scene->addItem(MyFloor.back());

        MyFloor.push_back(new Floor(360,300, 8));
        scene->addItem(MyFloor.back());

        MyFloor.push_back(new Floor(600,300, 8));
        scene->addItem(MyFloor.back());

        MyFloor.push_back(new Floor(480,250, 8));
        scene->addItem(MyFloor.back());

        MyFloor.push_back(new Floor(360,300, 8));
        scene->addItem(MyFloor.back());


    for(int i=2000; i<3000; i+=120){

        MyFloor.push_back(new Floor(i,250, 7));
        scene->addItem(MyFloor.back());

    }
    for(int i=2000; i<3000; i+=120){

        MyFloor.push_back(new Floor(i,150, 7));
        scene->addItem(MyFloor.back());

    }
    for(int i=2000; i<3000; i+=120){

        MyFloor.push_back(new Floor(i,200, 7));
        scene->addItem(MyFloor.back());

    }

}*/
