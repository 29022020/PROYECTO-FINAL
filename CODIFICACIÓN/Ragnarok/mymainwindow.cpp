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

    BjornSotrack = new PersonajeSotrak(0, 500, 0, 0);

    scene->addItem(BjornSotrack);

    GlobalTime=new QTimer();

    connect(GlobalTime, &QTimer::timeout, this, &MyMainWindow::OnUpdate);

}

MyMainWindow::~MyMainWindow()
{

    delete scene;

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

}

void MyMainWindow::keyPressEvent(QKeyEvent *event)
{
    //BjornSotrack->setPx1(BjornSotrack->getPx());

   // BjornSotrack->setPy1(BjornSotrack->getPy());


     if(event->key() == Qt::Key_A){

         BjornSotrack->setMyVelX(-16);
         BjornSotrack->setMyVelY(0);
       //  BjornSotrack->ChangeMySprite(event->key());
       //  band=true;

     }else if(event->key() == Qt::Key_D){


         BjornSotrack->setMyVelX(16);
         BjornSotrack->setMyVelY(0);
        // personaje->ChangeMySprite(event->key());
       //  band=true;



     }else if(event->key() == Qt::Key_W){

         BjornSotrack->setMyVelY(-16);
         BjornSotrack->setMyVelX(0);
       //  BjornSotrack->ChangeMySprite(event->key());
      //   band=true;



     }else if(event->key() == Qt::Key_S){

         BjornSotrack->setMyVelY(16);
         BjornSotrack->setMyVelX(0);
        // BjornSotrack->ChangeMySprite(event->key());
       //  band=true;


     }else if(event->key() == Qt::Key_P ){
       // if(band){
       // BjornSotrack->addBomb();
      }



}

