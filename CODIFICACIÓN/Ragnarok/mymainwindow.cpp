#include "mymainwindow.h"
#include "ui_mymainwindow.h"

/*MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{

    ui->setupUi(this);

    scene = new QGraphicsScene(this); //Motor del aparado grafico

    scene->setSceneRect(0,0,4000,680);

    ui->graphicsView->setSceneRect(0, 0, 1240, 680);

    //scene->setStyle(QStyle )


    ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

  //  scene->setBackgroundBrush(Qt::darkGreen);


    scene->setBackgroundBrush(QImage(":/sprites/FONDOS/danheim-gealdyr-snow-snow-covered-ice-hd-wallpaper-preview.jpg").scaled(1240, 680));

    BjornSotrack = new PersonajeSotrak(0, 350, 0, 0, 20, 0,200,scene);


    Vikings.push_back(new VikingsArena(900, 320,  800, 1200,20, 0,2, 200, 15));

    Vikings.push_back(new VikingsArena(700, 420,  600, 800,20, 0,2, 200, 15));

    //Plataform =new PlataformRandI(200, 500, 0, 0, 2);

    Plataforms.push_back(new PlataformRandI(200, 500, 0, 0, 2));

    scene->addItem(BjornSotrack);

   // scene->addItem(Plataforms.back());

    for(auto value: Vikings){

        scene->addItem(value);
    }

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &MyMainWindow::OnUpdate);

    CreateMyFloor();

    OnStartGame();

    ContSwordAttack=0;

    ContSpriteAttack=0;

    FlagSwordAttack=false;

    FlagWindow=false;

    FlagSwordAttackActive=false;

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);





}

MyMainWindow::~MyMainWindow()
{

    delete scene;

    for(auto value: Vikings){

        delete  value;
    }


    for(auto value: MyFloor){

       delete value;

    }

    delete  Plataform;

    delete BjornSotrack;

    delete GlobalTime;

    delete ui;

}

void MyMainWindow::OnStartGame()
{

    GlobalTime->start(5);

}

void MyMainWindow::OnUpdate()
{
    scene->advance();

    for(auto value: MyFloor){

        if(value->collidesWithItem(BjornSotrack)){

            if(BjornSotrack->getMyPosY()!=BjornSotrack->getMyLastPosY() || BjornSotrack->getMyPosY()!=BjornSotrack->getMyPosY()){

            //    qDebug()<<BjornSotrack->getMyPosX()<<"::"<<BjornSotrack->getMyPosY()<<" vs "<<value->getMyPosX()<<"::"<<value->getMyPosY();

            }
            if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()<value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelY(-80);

                                //     qDebug()<<"Bloque Colling1"<<endl;
                                     break;


           }
            if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<value->getMyPosY()+50&&BjornSotrack->getMyPosX()+60>=value->getMyPosX()+120){

                                     BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                     BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());

                                 //    qDebug()<<"Bloque Colling1"<<endl;
                                     break;

           }



           if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                     BjornSotrack->setMyVelY(-80);

                                    BjornSotrack->setFlagJump(true);

                                   // qDebug()<<"Bloque Colling2"<<endl;
                                    break;


          }
           if(BjornSotrack->getMyPosY()>=value->getMyPosY()+45 && BjornSotrack->getMyPosY()<value->getMyPosY()+50&&BjornSotrack->getMyPosX()<=value->getMyPosX()&&BjornSotrack->getMyPosX()+60<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                      BjornSotrack->setMyVelY(-80);

                                   // qDebug()<<"Bloque Colling5"<<endl;
                                    break;

           }

           if(BjornSotrack->getMyPosY()>=value->getMyPosY() && BjornSotrack->getMyPosY()<=value->getMyPosY()+50&&BjornSotrack->getMyPosX()>=value->getMyPosX()&&BjornSotrack->getMyPosX()<=value->getMyPosX()+120){

                                    BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                                    BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                                     BjornSotrack->setMyVelY(-80);
                                    BjornSotrack->setFlagJump(true);

                                  //  qDebug()<<"Bloque Colling3"<<endl;
                                    break;

          }


             if(BjornSotrack->getMyPosX()+60>=value->getMyPosX() && BjornSotrack->getMyPosY()+69>=value->getMyPosY() && BjornSotrack->getMyPosY()<=(value->getMyPosY()+50)){

                        BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                        BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                        BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                        break;

             }


            if(BjornSotrack->getMyPosX()>=value->getMyPosX()+120 && BjornSotrack->getMyPosY()+65>=value->getMyPosY() && BjornSotrack->getMyPosY()<=(value->getMyPosY()+50)){

                        BjornSotrack->setMyVelX(-BjornSotrack->getMyVelX());
                        BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                        BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                        break;

             }

        }
        else{

          BjornSotrack->setMyAceY(10);

        }
    }

    QList<QGraphicsItem *> colisiones = scene->collidingItems(BjornSotrack); //bloques

     if(!colisiones.isEmpty()){

         for(auto value: colisiones){



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

     int cont=0;
     for(auto value1: Vikings){

     if(value1->collidesWithItem(BjornSotrack) && FlagSwordAttackActive ){

         value1->setMyVelX(-value1->getMyVelX());

         value1->setMyLife(value1->getMyLife()-BjornSotrack->getMyDamage());

         FlagSwordAttackActive=false;

     }

     if(value1->collidesWithItem(BjornSotrack) && value1->getFlagAttack() ){

          BjornSotrack->EnemyAttackMe(value1->getMyDamage(),1);
     }

     if(value1->getMyLife()<=0){

         scene->removeItem(value1);

         delete value1;

        Vikings.removeAt(cont);

     }

     cont++;

     }

}

void MyMainWindow::keyPressEvent(QKeyEvent *event)
{


     if(event->key() == Qt::Key_A){

         BjornSotrack->setMyVelX(-VEL);

         BjornSotrack->setMyDirection(1);

         BjornSotrack->setMyWidht(60);

         BjornSotrack->setMyHeight(70);

         BjornSotrack->ChangeMySprite(event->key());

         BjornSotrack->setContSprites(BjornSotrack->getContSprites()+1);

         if(BjornSotrack->getContSprites()>2)BjornSotrack->setContSprites(0);

     }else if(event->key() == Qt::Key_D){

         BjornSotrack->setMyVelX(VEL);

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

        FlagSwordAttackActive=true;

      //  BjornSotrack->setMyHeight(BjornSotrack->getMyHeight()+10);

        FlagSwordAttack=true;

      }
     if(BjornSotrack->getMyPosX()>=1200){

     ui->graphicsView->setSceneRect(BjornSotrack->getMyPosX()-600, 0, 1240, 680);

     }else{

          ui->graphicsView->setSceneRect(0, 0, 1240, 680);

     }

     if(BjornSotrack->getMyPosX()>=1240&&BjornSotrack->getMyPosX()<2480 && FlagWindow==false){

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
     }



}

void MyMainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

       BjornSotrack->setMyVelX(0);


    }else if(event->key() == Qt::Key_D){

       BjornSotrack->setMyVelX(0);

    }

}

void MyMainWindow::CreateMyFloor()
{
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

    for(int i=400; i<1300; i+=120){

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
    for(int i=800; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,300, 7));
        scene->addItem(MyFloor.back());

    }
    for(int i=800; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,250, 7));
        scene->addItem(MyFloor.back());

    }

}

*/
