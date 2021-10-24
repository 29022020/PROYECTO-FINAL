#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    connect(ui->registerPushButton, &QPushButton::clicked, this, &Register::RegisterAction);

    connect(ui->closePushButton, &QPushButton::clicked, this, &Register::closeMe);

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

    QString Score="0";

    QString Life="1000";

    QString Damage="20";

    QString Level="1";

    consulta.append("INSERT INTO usuario("
                    "user,"
                    "password,"
                    "PosX,"
                    "PosY,"
                    "Score,"
                    "Life,"
                    "Damage,"
                    "Level)"
                    "VALUES("
                    "'"+ui->LineEditUsernameR->text()+"',"
                    "'"+ui->LineEditPassWordR->text()+"',"
                    "'"+PosX+"',"
                    "'"+PosY+"',"
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
