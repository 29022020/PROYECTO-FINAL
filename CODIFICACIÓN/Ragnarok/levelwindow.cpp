#include "levelwindow.h"
#include "ui_levelwindow.h"

LevelWindow::LevelWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelWindow)
{

    ui->setupUi(this);

    scene = new QGraphicsScene(this); //Motor del aparado grafico

    scene->setSceneRect(0,0,4000,700);

    ui->graphicsView->setSceneRect(0, 0, 1240, 680);

    //scene->setStyle(QStyle )


    ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

  //  scene->setBackgroundBrush(Qt::darkGreen);


    scene->setBackgroundBrush(QImage(":/sprites/FONDOS/danheim-gealdyr-snow-snow-covered-ice-hd-wallpaper-preview.jpg").scaled(1240, 680));

    BjornSotrack = new PersonajeSotrak(0, 350, 0, 0, 20, 0,2000,0,scene);

    Vikings.push_back(new VikingsArena(900, 320,  800, 1200,20, 0,2, 200, 15));

    Items.push_back(new PowerUpItems(900, 320, 1));

    Items.push_back(new PowerUpItems(700, 420, 5));

    MyRunes.push_back(new Runes(740, 420, 2));

    MyRunes.push_back(new Runes(940, 300, 1));

    Vikings.push_back(new VikingsArena(700, 420,  600, 800,20, 0,2, 200, 15));

    //Plataform =new PlataformRandI(200, 500, 0, 0, 2);

   // Plataforms.push_back(new PlataformRandI(200, 500, 0, 0, 2));

    scene->addItem(BjornSotrack);

    scene->setFocusItem(BjornSotrack);

    VelXpersonaje=30;

    VelYpersonaje=35;

   // scene->addItem(Plataforms.back());

    for(auto value: Vikings){

        scene->addItem(value);
    }

    for(auto value: Items){

        scene->addItem(value);
    }

    for(auto value1: MyRunes){

        scene->addItem(value1);
    }

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &LevelWindow::OnUpdate);

    CreateMyFloor();

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

    ///Axe
    MyAxes.push_back( new Axe(20, 200, 0, 0, 20));

    scene->addItem(MyAxes.back());

    /////////////////Audio
    ///
    player = new QMediaPlayer();
    // ...
    player->setMedia(QUrl::fromLocalFile("../Ragnarok/music/mario.mp3"));
    player->setVolume(10);
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


    for(auto value: MyFloor){

       delete value;

    }

    for(auto value: Items){

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
            //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho (medio).
            if(BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                     qDebug()<<"Bloque Colling1"<<endl;
                                     break;
           }
                //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho (medio).
                if(BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosY()+70>=value->getMyPosY()+50&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                         BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                         BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                          BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                         qDebug()<<"Bloque Colling1"<<endl;
                                         break;
               }


            if(BjornSotrack->getMyPosY()!=BjornSotrack->getMyLastPosY() || BjornSotrack->getMyPosY()!=BjornSotrack->getMyPosY()){

            //    qDebug()<<BjornSotrack->getMyPosX()<<"::"<<BjornSotrack->getMyPosY()<<" vs "<<value->getMyPosX()<<"::"<<value->getMyPosY();

            }

            ////Colision por la parte de izquierda del bloque si el personaje esta saltando.
            if(BjornSotrack->getMyPosY()>=value->getMyPosY()+49 && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelY(-80);

                                //     qDebug()<<"Bloque Colling1"<<endl;
                                     break;


           }
            //Colision por la parte de abajo del bloque si el personaje esta saltando pico derecho.
            if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                 //    qDebug()<<"Bloque Colling1"<<endl;
                                     break;
           }
           //Colision por la parte de abajo del bloque si el personaje esta saltando pico izquierdo.
           if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                     BjornSotrack->setMyVelY(-80);

                                    BjornSotrack->setFlagJump(true);

                                   // qDebug()<<"Bloque Colling2"<<endl;
                                    break;


          }
          //Colision por la parte de derecha del bloque si el personaje esta saltando.
          if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelY(-80);

                                   // qDebug()<<"Bloque Colling5"<<endl;
                                    break;

           }
           //Colision por la parte de izquierda del bloque si el personaje esta saltando.
           if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                     BjornSotrack->setMyVelY(-80);
                                    BjornSotrack->setFlagJump(true);

                                  //  qDebug()<<"Bloque Colling3"<<endl;
                                    break;

          }
          //Colision por la parte de izquierda del bloque si el personaje esta en el suelo.
          if(BjornSotrack->getMyPosX()+60>=value->getMyPosX() && BjornSotrack->getMyPosY()+69>=value->getMyPosY() && BjornSotrack->getMyPosY()<=(value->getMyPosY()+50)){

                        BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                        BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                        BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                        break;

             }
            //Colision por la parte de derecha del bloque si el personaje esta en el suelo.
            if(BjornSotrack->getMyPosX()>=value->getMyPosX()+120 && BjornSotrack->getMyPosY()+69>=value->getMyPosY() && BjornSotrack->getMyPosY()<=(value->getMyPosY()+50)){

                        BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                        BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                        BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                        break;

             }

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

     if(ContSwordAttack<=400){

         ContSwordAttack+=5;

         if(ContSwordAttack==100){

             ContSpriteAttack++;

         }
         if(ContSwordAttack==200){

             ContSpriteAttack++;

         }
         if(ContSwordAttack==300){

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
     //Colision de Ataque Axe vs Personaje.

     for(auto value1: MyAxes){

     if(value1->collidesWithItem(BjornSotrack) && value1->getFlagAttack() ){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(), 20);
          QString LiFeBS=QString::number(BjornSotrack->getMyLife());
          ui->MyLevelValue->setText(LiFeBS);
     }

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

     }else if(event->key() == Qt::Key_S){

         //BjornSotrack->setMyVelY(VEL);
        // BjornSotrack->setMyVelX(0);
       //  BjornSotrack->ChangeMySprite(event->key());
       //  band=true;

     }else if(event->key() == Qt::Key_P && FlagSwordAttack==false){

        BjornSotrack->setMyWidht(BjornSotrack->getMyWidht()+20);

        espada->play();

        FlagSwordAttackActive=true;

      //  BjornSotrack->setMyHeight(BjornSotrack->getMyHeight()+10);

        FlagSwordAttack=true;

      }
     if(BjornSotrack->getMyPosX()>=1200){

     //ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX()-600, 0, 1240, 680);

     }else{

       //   ui->graphicsView->setSceneRect(0, 0, 1240, 680);

     }
       ui->graphicsView->centerOn(BjornSotrack);



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



}

void LevelWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

       BjornSotrack->setMyVelX(0);


    }else if(event->key() == Qt::Key_D){

       BjornSotrack->setMyVelX(0);

    }

}

void LevelWindow::CreateMyFloor()
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
    /*for(int i=0; i<1240; i+=120){

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
    MyFloor.push_back(new Floor(120,450, 7));
    scene->addItem(MyFloor.back());

    MyFloor.push_back(new Floor(240,300, 7));
    scene->addItem(MyFloor.back());

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
    for(int i=2000; i<3000; i+=120){

        MyFloor.push_back(new Floor(i,300, 7));
        scene->addItem(MyFloor.back());

    }
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

    }*/

}


void LevelWindow::putVikingsArena()
{

    string Arena;
    fstream text;
    string temporal;
    string atributoagregar;
    string tipo;

    string atributesfinal[10];
    int k=-1;

        text.open("D:/Desktop/juanfer ragnarok/Ragnarok/sprites/vikingsarena.txt",fstream::in);
        if(text.is_open()){

            for(int j=1; !text.eof();j+=1){

                getline(text,Arena);

                qDebug() << QString::fromStdString(Arena);

            for(int i=0,cuenta=2;cuenta<Arena.size();cuenta++,i++){

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

       }

       if(tipo.compare("2")==0){

           //hachas.push_back(new VikingsArena(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5])));

       }

       if(tipo.compare("3")==0){

           //Gods.push_back(new VikingsArena(stof(atributesfinal[0]), stof(atributesfinal[1]), stof(atributesfinal[2]), stof(atributesfinal[3]),stof(atributesfinal[4]), stof(atributesfinal[5]),stof(atributesfinal[6]),stof(atributesfinal[7]),stof(atributesfinal[8])));
       }
       k=-1;
       atributoagregar.clear();

      }

    }

       text.close();
}


