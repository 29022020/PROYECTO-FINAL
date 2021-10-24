#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{

}

void Login::on_LoginpushButton_clicked()
{
    QString user=ui->UserlineEdit->text();

    QString pass=ui->PasslineEdit->text();

    QSqlQuery buscar;

    QString pass2;
    QString user2;

    QString PosX;
    QString PosY;




    QString Consulta;

    Consulta.append("SELECT * FROM usuario where user='"+user+"'");

    buscar.prepare(Consulta);

    if(buscar.exec()){

        qDebug()<<"Consulta realizada.";

        while(buscar.next()){

            pass2=buscar.value(1).toByteArray().constData();
            user2=buscar.value(0).toByteArray().constData();
            PosX=buscar.value(2).toByteArray().constData();
            PosY=buscar.value(3).toByteArray().constData();
        }
    }else{

        qDebug()<<"Error de consulta";

        QMessageBox::critical(this, tr("ERROR"), tr("El Usuario no existe."));

    }
    if(pass2==pass){

        float X=PosX.toFloat();
        float Y=PosY.toFloat();
        qDebug()<<"PosX: "<<X<<" ,PosY: "<<Y;
        QMessageBox::information(this, tr("Bienvenido"), tr("Bienvenido: %1").arg(user2));

    }else{

        QMessageBox::critical(this, tr("ERROR"), tr("Contraseña incorrecta."));
    }
}

void Login::on_UpdatepushButton_clicked()
{

    QString posX="234";

    QString posY="500";

    QString Level=QString::number(6);

    QSqlQuery update;

    QString user="Juan1";
    QString user2;

    QString Consulta;

    Consulta.append(" UPDATE usuario set PosX='"+posX+"', PosY='"+posY+"',Level='"+Level+"' where user='"+user+"'");

    update.prepare(Consulta);

    if(update.exec()){

        qDebug()<<"UPDATE realizada.";

    }else{

        qDebug()<<"Error de UPDATE";

        QMessageBox::critical(this, tr("ERROR"), tr("No se hizo la UPDATE."));

    }

}
