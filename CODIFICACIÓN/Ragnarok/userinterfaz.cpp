#include "userinterfaz.h"
#include "ui_userinterfaz.h"

UserInterfaz::UserInterfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterfaz)
{
    ui->setupUi(this);

    connect(ui->LoginPushButton, &QPushButton::clicked, this, &UserInterfaz::LoginS);

    connect(ui->registerPushButton, &QPushButton::clicked, this, &UserInterfaz::RegisterS);

    connect(ui->CloseMepushButton, &QPushButton::clicked, this, &UserInterfaz::closeMe);

    FlagL=false;

    FlagR=false;

    qDebug()<<"Start";

    QString nombre;

    nombre.append("BaseDeDatos1.sqlite");

    db = QSqlDatabase ::addDatabase("QSQLITE");

    db.setDatabaseName(nombre);

    if(db.open()){

        qDebug()<<"Se ha conectado a la base de datos.";

    }else{
        qDebug()<<"No se ha conectado a la base de datos.";
    }

}

UserInterfaz::~UserInterfaz()
{

    if(FlagL){

    delete LoginWindow;

    }
    if(FlagR){

    delete RegisterWindow;

    }
    delete ui;


}

void UserInterfaz::LoginS()
{

    this->hide();

    LoginWindow=new Login();

    LoginWindow->show();

    connect(LoginWindow,&Login::fin,this,&UserInterfaz::CloseWindownOpenMe);

    FlagL=true;

}

void UserInterfaz::RegisterS()
{

    this->hide();

    RegisterWindow=new Register();

    RegisterWindow->show();

    connect(RegisterWindow,&Register::fin,this,&UserInterfaz::CloseWindownOpenMe);

    FlagR=true;

}

void UserInterfaz::CloseWindownOpenMe()
{
    if(FlagL){

        this->show();

        LoginWindow->close();

        delete LoginWindow;

    }
    if(FlagR){

        this->show();

        RegisterWindow->close();

        delete RegisterWindow;

    }

    FlagL=false;

    FlagR=false;

}

void UserInterfaz::closeMe()
{
    emit fin(3);

}
