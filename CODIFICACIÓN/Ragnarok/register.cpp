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

    delete Game;

    delete Game2;


}

void Register::RegisterAction()
{
    QString consulta;

    QString PosX="0";

    QString PosY="450";

    QString VelX="30";

    QString VelY="35";

    QString Score="0";

    QString Life="2000";

    QString Magic="20";

    QString Damage="20";

    QString Level="1";

    QString user=ui->LineEditUsernameR->text();

    consulta.append("INSERT INTO usuario("
                    "user,"
                    "password,"
                    "PosX,"
                    "PosY,"
                    "VelX,"
                    "VelY,"
                    "Score,"
                    "Life,"
                    "Magic,"
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
                    "'"+Magic+"',"
                    "'"+Damage+"',"
                    "'"+Level+"'"
                    ");");

     QSqlQuery insertar;

     insertar.prepare(consulta);

     if(insertar.exec()){

         qDebug()<<"El USER ha sido insertado.";

          QMessageBox::information(this, tr("Exito"), tr("Registro exitoso."));

          this->hide();

          QWidget *parent=nullptr;

          //Game=new LevelWindow();

          Game=new LevelWindow(parent, user, PosX.toFloat(), PosY.toFloat(), VelX.toFloat(), VelY.toFloat(), Score.toInt(), Level.toInt(), Damage.toInt(), Magic.toFloat(), Life.toFloat());

          Game->show();

          connect(Game,&LevelWindow::fin,this,&Register::CerrarVentanaOpenMe);

          connect(Game,&LevelWindow::ChangeLevelSignal,this,&Register::UpdateLevel);


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
                    "Magic INTEGER NOT NULL,"
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

void Register::UpdateLevel()
{
    Game->close();

    disconnect(Game,&LevelWindow::ChangeLevelSignal,this,&Register::UpdateLevel);

   // this->show();

    qDebug()<<"Update Level";

    QString user=ui->LineEditUsernameR->text();

    QSqlQuery buscar;

    QString pass2;
    QString user2;
    QString PosX;
    QString PosY;
    QString VelX;
    QString VelY;
    QString Score;
    QString Life;
    QString Magic;
    QString Damage;
    QString Level;

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
            VelX=buscar.value(4).toByteArray().constData();
            VelY=buscar.value(5).toByteArray().constData();
            Score=buscar.value(6).toByteArray().constData();
            Life=buscar.value(7).toByteArray().constData();
            Magic=buscar.value(8).toByteArray().constData();
            Damage=buscar.value(9).toByteArray().constData();
            Level=buscar.value(10).toByteArray().constData();
        }
    }
    QWidget *parent=nullptr;

    Game=new LevelWindow(parent, user2, PosX.toFloat(), PosY.toFloat(), VelX.toFloat(), VelY.toFloat(), Score.toInt(), Level.toInt(), Damage.toInt(), Magic.toFloat(), Life.toInt());

    Game->show();

    connect(Game,&LevelWindow::fin,this,&Register::CerrarVentanaOpenMe);

    connect(Game,&LevelWindow::ChangeLevelSignal,this,&Register::UpdateLevel);
}

void Register::CerrarVentanaOpenMe()
{

    Game->close();

    this->show();

   // delete Game;

}
