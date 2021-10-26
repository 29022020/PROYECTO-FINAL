#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    connect(ui->registerPushButton, &QPushButton::clicked, this, &Register::RegisterAction);

    connect(ui->closePushButton, &QPushButton::clicked, this, &Register::closeMe);

    crearTabla();

}

Register::~Register()
{
    delete ui;
}

void Register::RegisterAction()
{
    QString consulta;

    QString PosX="0";

    QString PosY="450";

    QString VelX="30";

    QString VelY="35";

    QString Score="0";

    QString Life="1000";

    QString Damage="20";

    QString Level="1";

    consulta.append("INSERT INTO usuario("
                    "user,"
                    "password,"
                    "PosX,"
                    "PosY,"
                    "VelX,"
                    "VelY,"
                    "Score,"
                    "Life,"
                    "Damage,"
                    "Level)"
                    "VALUES("
                    "'"+ui->LineEditUsernameR->text()+"',"
                    "'"+ui->LineEditPassWordR->text()+"',"
                    "'"+PosX+"',"
                    "'"+PosY+"',"
                    "'"+VelX+"',"
                    "'"+VelY+"',"
                    "'"+Score+"',"
                    "'"+Life+"',"
                    "'"+Damage+"',"
                    "'"+Level+"'"
                    ");");

     QSqlQuery insertar;

     insertar.prepare(consulta);

     if(insertar.exec()){

         qDebug()<<"El USER ha sido insertado.";

          QMessageBox::information(this, tr("Exito"), tr("Registro exitoso."));

     }else{

         qDebug()<<"El USER no se ha insertado correctamente.";
         qDebug()<<"ERROR!: "<<insertar.lastError();
         QMessageBox::critical(this, tr("ERROR"), tr("El Usuario ya está en uso."));
     }

}

void Register::closeMe()
{
    emit fin(3);
}

void Register::crearTabla()
{
    QString consulta;

    consulta.append("CREATE TABLE IF NOT EXISTS usuario( "
                    "user VARCHAR(100) PRIMARY KEY,"
                    "password VARCHAR(100),"
                    "PosX INTEGER NOT NULL,"
                    "PosY INTEGER NOT NULL,"
                    "VelX INTEGER NOT NULL,"
                    "VelY INTEGER NOT NULL,"
                    "Score INTEGER NOT NULL,"
                    "Life INTEGER NOT NULL,"
                    "Damage INTEGER NOT NULL,"
                    "Level INTEGER NOT NULL"
                    ");");
     QSqlQuery crear;

     crear.prepare(consulta);

     if(crear.exec()){

         qDebug()<<"TABLA usuarios existe o se ha creado correctamente.";

     }else{

         qDebug()<<"TABLA usuarios NO existe o NO se ha creado correctamente.";
         qDebug()<<"ERROR!: "<<crear.lastError();
     }
}
