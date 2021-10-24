#include "register.h"
#include "ui_register.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    qDebug()<<"Start";

    QString nombre;

    nombre.append("BaseDeDatos6.sqlite");

    db = QSqlDatabase ::addDatabase("QSQLITE");

    db.setDatabaseName(nombre);

    if(db.open()){

        qDebug()<<"Se ha conectado a la base de datos.";

    }else{
        qDebug()<<"No se ha conectado a la base de datos.";
    }

}

Register::~Register()
{
    delete ui;
}



void Register::on_RegisterpushButton_clicked()
{

    MuMainWindow *registro=new MuMainWindow(0);

    registro->show();

}

void Register::on_LoginpushButton_clicked()
{

    Login *LoginW=new Login(0);

    LoginW->show();

}
