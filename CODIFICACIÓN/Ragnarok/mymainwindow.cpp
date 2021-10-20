#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{

    ui->setupUi(this);

    scene = new QGraphicsScene(this); //Motor del aparado grafico

    scene->setSceneRect(0,0,1240,680);

    //scene->setStyle(QStyle )

    ui->graphicsView->setScene(scene); //Enviar escena a la parte gráfica

  //  scene->setBackgroundBrush(Qt::darkGreen);

    BjornSotrack = new PersonajeSotrak(0, 350, 0, 0, scene);

    //Plataform =new PlataformRandI(200, 500, 0, 0, 2);

    Plataforms.push_back(new PlataformRandI(200, 500, 0, 0, 2));

    scene->addItem(BjornSotrack);

    scene->addItem(Plataforms.back());

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &MyMainWindow::OnUpdate);

    CreateMyFloor();

    OnStartGame();



}

MyMainWindow::~MyMainWindow()
{

    delete scene;

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

    GlobalTime->start(10);

}

void MyMainWindow::OnUpdate()
{
    scene->advance();

    for(auto value: MyFloor){

        if(value->collidesWithItem(BjornSotrack) && (BjornSotrack->getMyDirection() == 1 ||BjornSotrack->getMyDirection() == 2)){

           // BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
            //BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

          //  BjornSotrack->setMyVelY(-0.1*BjornSotrack->getMyVelY());
//            BjornSotrack->setMyVelX(-0.1*BjornSotrack->getMyVelX());


        }

    }


    QList<QGraphicsItem *> colisiones = scene->collidingItems(BjornSotrack); //bloques
     if(!colisiones.isEmpty()){
         Floor *item = dynamic_cast<Floor *>(colisiones[0]);
         if(item){

         Floor *muros = dynamic_cast<Floor *>(colisiones[0]);
         if(muros){
             if(muros->getMyType()==1){
                // muros->setTipo(3);
                 BjornSotrack->setMyPosX(BjornSotrack->getMyLastPosX());
                 BjornSotrack->setMyPosY(BjornSotrack->getMyLastPosY());

                 BjornSotrack->setMyVelY(-0.1*BjornSotrack->getMyVelY());
                 BjornSotrack->setMyAceY(-0.1*BjornSotrack->getMyAceY());

                 BjornSotrack->setFlagJump(false);

              //   BjornSotrack->setMyAceY(0);


             }


             /*else if(muros->getTipo()==3 || muros->getTipo()==0){
                 pj1->setPx(inix);
                 pj1->setPy(iniy);
                 pj1->setVidas(pj1->getVidas()-1);


                 if(pj1->getVidas()==0){scene->removeItem(pj1);}
             }

             else if(muros->getTipo()==1 || muros->getTipo()==2){

                 pj1->setVy(-2*pj1->getVy());
                 pj1->setAy(-2*pj1->getAy());

             */}
         }

     }
     else{
         BjornSotrack->setMyAceY(10);
     }
}

void MyMainWindow::keyPressEvent(QKeyEvent *event)
{


     if(event->key() == Qt::Key_A){

         BjornSotrack->setMyVelX(-VEL);
         BjornSotrack->setMyDirection(1);
         BjornSotrack->ChangeMySprite(event->key());
       //  band=true;

     }else if(event->key() == Qt::Key_D){


         BjornSotrack->setMyVelX(VEL);
         BjornSotrack->setMyDirection(2);
         BjornSotrack->ChangeMySprite(event->key());
       //  band=true;


     }else if(event->key() == Qt::Key_W && BjornSotrack->getFlagJump()==false){

         BjornSotrack->setMyVelY(-50);

         BjornSotrack->ChangeMySprite(event->key());

         BjornSotrack->setFlagJump(true);

         BjornSotrack->setMyDirection(0);

      //   band=true;



     }else if(event->key() == Qt::Key_S){

         //BjornSotrack->setMyVelY(VEL);
        // BjornSotrack->setMyVelX(0);
       //  BjornSotrack->ChangeMySprite(event->key());
       //  band=true;


     }else if(event->key() == Qt::Key_P ){

        // if(band){
       // BjornSotrack->addBomb();

      }



}

void MyMainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

       BjornSotrack->setMyVelX(0);
       qDebug()<<"MYVel=0"<<endl;


    }else if(event->key() == Qt::Key_D){

       BjornSotrack->setMyVelX(0);
        qDebug()<<"MYVel=0"<<endl;


    }else if(event->key() == Qt::Key_W){



    }else if(event->key() == Qt::Key_S){



    }
}

void MyMainWindow::CreateMyFloor()
{
    for(int i=0; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,500, 1));
        scene->addItem(MyFloor.back());

    }

    for(int i=400; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,450, 1));
        scene->addItem(MyFloor.back());

    }

    for(int i=600; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,400, 1));
        scene->addItem(MyFloor.back());

    }
    for(int i=800; i<1240; i+=120){

        MyFloor.push_back(new Floor(i,350, 1));
        scene->addItem(MyFloor.back());

    }

}

