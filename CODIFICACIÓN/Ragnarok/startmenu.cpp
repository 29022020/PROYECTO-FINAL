#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartMenu)
{

    ui->setupUi(this);

    connect(ui->singlePushButton, &QPushButton::clicked, this, &StartMenu::CreateInterfaz);

    connect(ui->multiPushButton, &QPushButton::clicked, this, &StartMenu::MultiPlayer);

    connect(ui->closePushButton, &QPushButton::clicked, this, &StartMenu::CloseMe);

    FlagI=false;

    FlagM=false;

}

StartMenu::~StartMenu()
{

    if(FlagI){

    delete Interfaz;

    }

    delete ui;

}

void StartMenu::CloseMe()
{

    this->close();

}

void StartMenu::CreateInterfaz()
{
    this->hide();

    Interfaz=new UserInterfaz();

    Interfaz->show();

    connect(Interfaz,&UserInterfaz::fin,this,&StartMenu::CloseWindownOpenMe);

    FlagI=true;

}

void StartMenu::MultiPlayer()
{
    this->hide();

    MultiGame=new Multiplayer();

    MultiGame->show();

    connect(MultiGame,&Multiplayer::fin,this,&StartMenu::CloseWindownOpenMe);

    FlagM=true;

}

void StartMenu::CloseWindownOpenMe()
{

    if(FlagI){

        this->show();

        Interfaz->close();

       // delete Interfaz;

    }
    if(FlagM){

        this->show();

        MultiGame->close();

        //delete MultiGame;

    }

    FlagI=false;

    FlagM=false;

}
