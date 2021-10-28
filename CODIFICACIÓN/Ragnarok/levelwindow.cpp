#include "levelwindow.h"
#include "ui_levelwindow.h"

LevelWindow::LevelWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelWindow)
{

    ui->setupUi(this);

    MyName="Juan1";

    MyLevel=1;

    scene = new QGraphicsScene(this); //Motor del aparado grafico

    scene->setSceneRect(0,0,4000,700);

    ui->graphicsView->setSceneRect(0, 0, 1240, 680);

    //scene->setStyle(QStyle )

    ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

  //  scene->setBackgroundBrush(Qt::darkGreen);

    scene->setBackgroundBrush(QImage(":/sprites/FONDOS/fondo.jpg").scaled(1240, 680));

    BjornSotrack = new PersonajeSotrak(0, 350, 0, 0, 20, 0,2000,0,scene);

   // Vikings.push_back(new VikingsArena(900, 320,  800, 1200,20, 0,2, 200, 15));

    Items.push_back(new PowerUpItems(900, 320, 1));

    Items.push_back(new PowerUpItems(700, 420, 5));

    MyRunes.push_back(new Runes(740, 420, 2));

    MyRunes.push_back(new Runes(940, 300, 1));

   // Vikings.push_back(new VikingsArena(700, 420,  600, 800,20, 0,2, 200, 15));

   /* Gods.push_back(new God(700, 300,  600, 800,20, 1,1, 200, 15, 20));

   Gods.push_back(new God(700, 250,  0, 800,20, 2,2, 200, 15, 20));

    Gods.push_back(new God(700, 200,  300, 800,20, 3,3, 200, 15, 20));*/

    for(auto value: Gods){

       // scene->addItem(value);
    }

    //Plataform =new PlataformRandI(200, 500, 0, 0, 2);

   // Plataforms.push_back(new PlataformRandI(200, 500, 0, 0, 2));

    scene->addItem(BjornSotrack);

    scene->setFocusItem(BjornSotrack);

    VelXpersonaje=30;

    VelYpersonaje=35;

   // scene->addItem(Plataforms.back());

    for(auto value: Vikings){

     //  scene->addItem(value);
    }

    for(auto value: Items){

        scene->addItem(value);
    }

    for(auto value1: MyRunes){

        scene->addItem(value1);
    }

    if(MyLevel==1){

        BjornSotrack->setRestarMyPosX(20);

        BjornSotrack->setResastPosY(500);


    }else if(MyLevel==2){

        BjornSotrack->setRestarMyPosX(20);

        BjornSotrack->setResastPosY(550);

    }else if(MyLevel==3){

        BjornSotrack->setRestarMyPosX(20);

        BjornSotrack->setResastPosY(500);


    }
    GlobalTime=new QTimer();

    AuxTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &LevelWindow::OnUpdate);

    connect(ui->SpushButton, &QPushButton::clicked, this, &LevelWindow::SaveMatch);

    connect(ui->CSpushButton, &QPushButton::clicked, this, &LevelWindow::closeMe);

    CreateMyFloor(1);

    OnStartGame();

    ContSwordAttack=0;

    ConTProyectiles=0;

    ContSpriteAttack=0;

    ContProyectilKill=0;

    ContProyectilKill2=0;

    ConTProyectilesMap=0;//Rayos

    if(MyLevel==2){

        MyNumOfProyectiles=30;
    }else if(MyLevel==3){
        MyNumOfProyectiles=40;
    }

    MyNumOfProyectiles=30;

    FlagSwordAttack=false;

    FlagWindow=false;

    FlagSwordAttackActive=false;

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QString LiFeBS=QString::number(BjornSotrack->getMyLife());
    ui->MyLevelValue->setText(LiFeBS);

    QString ScoreBS=QString::number(BjornSotrack->getMyScore());
    ui->MyScoreValue->setText(ScoreBS);

    ///Axe
    MyAxes.push_back( new Axe(800, 200, 0.03, 0.5, 20, 2, 70));
    //Axe::Axe(float MyPosX_, float MyPosy, float MyVelX_, float MyVelY_, unsigned int MyDamage_, unsigned int MyType_, unsigned int MyRadio_)

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

    putEnemys();

}

LevelWindow::LevelWindow(QWidget *parent, QString User,float MyPosX, int MyPosY, float MyVelX, int MyVelY,int Score, int level, float damage, float magic, float life)
    : QMainWindow(parent)
    , ui(new Ui::LevelWindow)
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
    if(MyLevel==1){

        BjornSotrack->setRestarMyPosX(20);

        BjornSotrack->setResastPosY(500);


    }else if(MyLevel==2){

        BjornSotrack->setRestarMyPosX(20);

        BjornSotrack->setResastPosY(550);

    }else if(MyLevel==3){

        BjornSotrack->setRestarMyPosX(20);

        BjornSotrack->setResastPosY(500);

    }
    scene->addItem(BjornSotrack);

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &LevelWindow::OnUpdate);

    connect(ui->SpushButton, &QPushButton::clicked, this, &LevelWindow::SaveMatch);

    connect(ui->CSpushButton, &QPushButton::clicked, this, &LevelWindow::closeMe);

    CreateMyFloor(level);

    OnStartGame();

    ContSwordAttack=0;

    ContSpriteAttack=0;

    FlagSwordAttack=false;

    FlagWindow=false;

    FlagSwordAttackActive=false;

   // ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

LevelWindow::~LevelWindow()
{

    delete scene;

    for(auto value: Vikings){

        delete  value;
    }

    for(auto value: ProyectilesSotrak){

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

 //   delete  MyAxe;

    delete BjornSotrack;

    delete GlobalTime;

    delete ui;

}

void LevelWindow::OnStartGame()
{

    GlobalTime->start(5);

}

void LevelWindow::OnUpdate()
{
    scene->advance();

    // * Análisis de colisones con los bloques Floor, por los diferentes lados del bloque.


    for(auto value: MyFloor){

        if(value->collidesWithItem(BjornSotrack)){

            if(value->getMyType()==8){


                if(BjornSotrack->getMyPosY()>=value->getMyPosY()+50 && BjornSotrack->getMyPosY()<=value->getMyPosY()+50 && BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()+60<=value->getMyPosX()+120){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelY(80);

                                         BjornSotrack->setFlagJump(true);

                                         qDebug()<<"Bloque Colling3"<<endl;
                                         break;


               }

                //Colision por la parte de abajo del bloque si el personaje esta saltando pico izquierdo.
                if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack->getMyPosX()+60>=value->getMyPosX()){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelY(80);

                                         BjornSotrack->setFlagJump(true);

                                         qDebug()<<"Bloque Colling1"<<endl;
                                         break;


               }
                if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50 && BjornSotrack->getMyPosX()<=value->getMyPosX()){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                         BjornSotrack->setMyVelY(80);

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

          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }

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
          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }

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
         if(value2->getMyType()==1){
         BjornSotrack->setMyScore(BjornSotrack->getMyScore()+1000);
         }else if(value2->getMyType()==2){
             BjornSotrack->setMyScore(BjornSotrack->getMyScore()+1500);
         }if(value2->getMyType()==3){
             BjornSotrack->setMyScore(BjornSotrack->getMyScore()+2000);
         }

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

          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }

          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);
     }

     }

     //Poner proyectiles Dios

    if(!Gods.empty()){
         if(ConTProyectiles<=150){
             ConTProyectiles++;
    }else{

             if(Gods[0]->getMyVelX()>0){

             ProyectilesGod.push_back(new ProyectilBase(Gods[0]->getMyPosX(), Gods[0]->getMyPosY()+30, 60, 2, Gods[0]->getMyMagic()));
             }else {

                 ProyectilesGod.push_back(new ProyectilBase(Gods[0]->getMyPosX(), Gods[0]->getMyPosY()+30, -60, 2, Gods[0]->getMyMagic()));


             }

             scene->addItem(ProyectilesGod.back());

             ConTProyectiles=0;
         }
         }

     //Poner proyectiles Mapa
     if(MyLevel==1){

             if(ConTProyectilesMap<=150){
                 ConTProyectilesMap++;
             }else{

                 int RamdonXNum=qrand()%1601+2000;
                 ProyectilesMap.push_back(new ProyectilBase(RamdonXNum, 10, 60, 3, 200));

                 scene->addItem(ProyectilesMap.back());

                 ConTProyectilesMap=0;

             }
     }else if(MyLevel==2){


         int RamdonXNum=qrand()%1601+2000;
         ProyectilesMap.push_back(new ProyectilBase(RamdonXNum, 10, 60, 3, 400));

         scene->addItem(ProyectilesMap.back());

         ConTProyectilesMap=0;


     }
             else if(MyLevel==3){

                 int RamdonXNum=qrand()%1601+2000;
                 ProyectilesMap.push_back(new ProyectilBase(RamdonXNum, 10, 60, 3, 600));

                 scene->addItem(ProyectilesMap.back());

                 ConTProyectilesMap=0;


              }

     //Colision de Ataque ProyectilesGod vs Personaje.

     int contp=0;
     for(auto value1: ProyectilesGod){

     if(value1->collidesWithItem(BjornSotrack)){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);

          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }

          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);


          scene->removeItem(value1);

          delete  value1;

          ProyectilesGod.removeAt(contp);


     }

     contp++;

     }

     //Colision de Ataque Proyectiles Maps Personaje.

     int contM=0;
     for(auto value1: ProyectilesMap){

     if(value1->collidesWithItem(BjornSotrack)){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);

          if(BjornSotrack->getMyLife()>2000){

              BjornSotrack->setMyLife(0);

          }


          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);


          scene->removeItem(value1);

          delete  value1;

          ProyectilesMap.removeAt(contM);


     }

     contM++;

     }

     //Quitar proyectiles Dios

      if(!ProyectilesGod.empty()){
      if(ContProyectilKill==800){


            ContProyectilKill=0;

            scene->removeItem(ProyectilesGod.front());

            delete  ProyectilesGod.front();

            ProyectilesGod.removeAt(0);



        }
        }
     //Quitar MapProyectiles

     int contM1=0;

     for(auto value1: ProyectilesMap){

        if(value1->getMyPosY()>=700){
             scene->removeItem(value1);

             delete  value1;

             ProyectilesMap.removeAt(contM1);


        }

        contM1++;

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

    //Proyectiles Sotrak vs Vikings

    if(!ProyectilesSotrak.empty()){
        int contProyectil=0;
        for(auto value: ProyectilesSotrak){
            int contVikings=0;
            for(auto value1: Vikings){
                if(value->collidesWithItem(value1)){

                    value1->setMyVelX(-value1->getMyVelX());

                    value1->setMyLife(value1->getMyLife()-BjornSotrack->getMyMagic());

                    scene->removeItem(value);

                    ProyectilesSotrak.removeAt(contProyectil);

                }if(value1->getMyLife()<=0){
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

                   Vikings.removeAt(contVikings);
                }

                  contVikings++;

            }
            contProyectil++;
        }
        }

    //Proyectiles Sotrak vs gods

    if(!ProyectilesSotrak.empty()){
        int contProyectil=0;
        for(auto value: ProyectilesSotrak){
            int contVikings=0;
            for(auto value1: Gods){
                if(value->collidesWithItem(value1)){

                    value1->setMyVelX(-value1->getMyVelX());

                    value1->setMyLife(value1->getMyLife()-BjornSotrack->getMyMagic());

                    scene->removeItem(value);

                    ProyectilesSotrak.removeAt(contProyectil);

                }if(value1->getMyLife()<=0){
                    if(value1->getMyType()!=0){
                    if(BjornSotrack->getMyDirection()==2){
                    MyRunes.push_back(new Runes(value1->getMyPosX()+3, value1->getMyPosY()-10, value1->getMyType()) );
                    }else{
                         MyRunes.push_back(new Runes(value1->getMyPosX()-3, value1->getMyPosY()-10, value1->getMyType()) );
                    }
                    }
                    scene->removeItem(value1);
                    scene->addItem(MyRunes.back());
                    if(value1->getMyType()==1){
                    BjornSotrack->setMyScore(BjornSotrack->getMyScore()+1000);
                    }else if(value1->getMyType()==2){
                        BjornSotrack->setMyScore(BjornSotrack->getMyScore()+1500);
                    }if(value1->getMyType()==3){
                        BjornSotrack->setMyScore(BjornSotrack->getMyScore()+2000);
                    }

                    QString ScoreBS=QString::number(BjornSotrack->getMyScore());
                    ui->MyScoreValue->setText(ScoreBS);

                    delete value1;

                    Gods.removeAt(contVikings);
                }
                contVikings++;


            }
            contProyectil++;
        }
        }

    //Quitar proyectiles Sotrak

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

   //Update Marcadores

   if(BjornSotrack->getMyLife()<=0){

       // ChangeLevel();
    }

   QString LiFeBS=QString::number(BjornSotrack->getMyLife());
   ui->MyLevelValue->setText(LiFeBS);

   QString ScoreBS=QString::number(BjornSotrack->getMyScore());
   ui->MyScoreValue->setText(ScoreBS);

   if(BjornSotrack->getMyPosX()>=1200){

      ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX()-600, 0, 1240, 680);

      }else{

          ui->graphicsView->setSceneRect(0, 0, 1240, 680);

      }

}

void LevelWindow::SaveMatch()
{
    QString posX=QString::number(BjornSotrack->getMyPosX());

    QString posY=QString::number(BjornSotrack->getMyPosY());

    QString velX=QString::number(VelXpersonaje);

    QString velY=QString::number(VelYpersonaje);

    QString Level=QString::number(MyLevel);

    QString Magic=QString::number(BjornSotrack->getMyMagic());

    QString Damage=QString::number(BjornSotrack->getMyDamage());

    QString Life=QString::number(BjornSotrack->getMyLife());

    QString Score=QString::number(BjornSotrack->getMyScore());

    QSqlQuery update;

    QString Consulta;


    qDebug()<<"PosX: "<<posX<<", PosY: "<<posY;
    qDebug()<<"VelX: "<<VelXpersonaje<<", VelY: "<<VelYpersonaje;
    qDebug()<<"Score: "<<Score;
    qDebug()<<"Life: "<<Life;
    qDebug()<<"Magic: "<<Magic;
    qDebug()<<"Damage: "<<Damage;
    qDebug()<<"Level: "<<Level;

    Consulta.append(" UPDATE usuario set PosX='"+posX+"', PosY='"+posY+"', VelX='"+velX+"', VelY='"+velY+"', Score='"+Score+"', Life='"+Life+"', Magic='"+Magic+"', Damage='"+Damage+"',Level='"+Level+"' where user='"+MyName+"'");

    update.prepare(Consulta);

    if(update.exec()){

        qDebug()<<"UPDATE realizada.";

    }else{

        qDebug()<<"Error de UPDATE";

        QMessageBox::critical(this, tr("ERROR"), tr("No se hizo la UPDATE."));

    }


}

void LevelWindow::keyPressEvent(QKeyEvent *event)
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

     }else if(event->key() == Qt::Key_O){


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


     }else if(event->key() == Qt::Key_P && FlagSwordAttack==false){


        espada->play();

        BjornSotrack->setMyWidht(BjornSotrack->getMyWidht()+20);

        FlagSwordAttackActive=true;

        FlagSwordAttack=true;

      }


}

void LevelWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

       BjornSotrack->setMyVelX(0);


    }else if(event->key() == Qt::Key_D){

       BjornSotrack->setMyVelX(0);

    }

    else if(event->key() == Qt::Key_P){

           //espada->stop();

        }

}

void LevelWindow::closeMe()
{
     SaveMatch();

     //this->close();

     emit fin(3);
}

void LevelWindow::CreateMyFloor(int level)
{

   string mapa;
   fstream text;
   string temporal;

   // int prb=50;
    //unsigned long long int tam;
        if(level==1){
        text.open("mapa.txt",fstream::in);
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

       /* for(int i=0, j=0; i<=4000; i+=120, j++){

            if(j%2==0){

            MyFloor.push_back(new Floor(i,50, 7));
            }else{

                 MyFloor.push_back(new Floor(i,50, 8));

            }
            scene->addItem(MyFloor.back());

        }

        for(int i=0, j=0; i<=700; i+=50, j++){

            qDebug()<<i%2;

            if(j%2==0){

            MyFloor.push_back(new Floor(0,i, 7));
            }else{

                 MyFloor.push_back(new Floor(0,i, 8));

            }
            scene->addItem(MyFloor.back());

        }*/


}

void LevelWindow::putEnemys()
{
    string Arena;
    fstream text;
    string temporal;
    string atributoagregar;
    string tipo;

    string atributesfinal[10];
    int k=-1;

        text.open("enemys1.txt",fstream::in);
        if(text.is_open()){

            for(int j=1; !text.eof();j+=1){

                getline(text,Arena);

                qDebug() << QString::fromStdString(Arena);

            for(int i=0,cuenta=2;cuenta<int(Arena.size());cuenta++,i++){

                tipo=Arena[0];

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


       if(tipo.compare("1")==0){

          Vikings.push_back(new VikingsArena(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5]),stof(atributesfinal[6]),stof(atributesfinal[7]),stof(atributesfinal[8])));

          scene->addItem(Vikings.back());
       }

       if(tipo.compare("2")==0){

            MyAxes.push_back(new Axe(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5]),stof(atributesfinal[6])));

            scene->addItem(MyAxes.back());

       }

       if(tipo.compare("3")==0){

           Gods.push_back(new God(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5]),stof(atributesfinal[6]),stof(atributesfinal[7]),stof(atributesfinal[8]),stof(atributesfinal[9])));

           scene->addItem(Gods.back());

       }

       k=-1;
       atributoagregar.clear();

      }

    }

       text.close();
}

void LevelWindow::ChangeLevel()
{
    MyLevel++;

    if(MyLevel==1){

        BjornSotrack->setMyPosX(20);

        BjornSotrack->setMyPosY(500);


    }else if(MyLevel==2){

        BjornSotrack->setMyPosX(20);

        BjornSotrack->setMyPosY(550);

    }else if(MyLevel==3){

        BjornSotrack->setMyPosX(20);

        BjornSotrack->setMyPosY(500);


    }

    BjornSotrack->setMyLife(2000);

    SaveMatch();

    emit ChangeLevelSignal(1);

}

unsigned int LevelWindow::getConTProyectilesMap() const
{
    return ConTProyectilesMap;
}

void LevelWindow::setConTProyectilesMap(unsigned int value)
{
    ConTProyectilesMap = value;
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


