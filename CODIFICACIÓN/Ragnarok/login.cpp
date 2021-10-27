#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);

    connect(ui->loginPushButtom, &QPushButton::clicked, this, &Login::LoginAction);

    connect(ui->closePushButton, &QPushButton::clicked, this, &Login::closeMe);

}

Login::~Login()
{
    delete ui;
}
void Login::closeMe()
{
    emit fin(3);

}

void Login::LoginAction()
{

    QString user=ui->LineEditUsernameL->text();

    QString pass=ui->LineEditPassWordL->text();

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
    }else{

        qDebug()<<"Error de Inicio";

        QMessageBox::critical(this, tr("ERROR"), tr("El Usuario no existe."));

    }
    if(pass2==pass){

         qDebug()<<"User: "<<user2;
         qDebug()<<"PosX: "<<PosX<<", PosY: "<<PosY;
         qDebug()<<"VelX: "<<VelX<<", VelY: "<<VelY;
         qDebug()<<"Score: "<<Score;
         qDebug()<<"Life: "<<Life;
         qDebug()<<"Magic: "<<Magic;
         qDebug()<<"Damage: "<<Damage;
         qDebug()<<"Level: "<<Level;

        QMessageBox::information(this, tr("Bienvenid@"), tr("Bienvenido: %1").arg(user2));

        this->hide();

        //LevelWindow(QWidget *parent, QString User, float MyPosX, int MyPosY, float MyVelX, int MyVelY,int Score, int level, float damage, float magic, float life);

        QWidget *parent=nullptr;

        Game=new LevelWindow(parent, user2, PosX.toFloat(), PosY.toFloat(), VelX.toFloat(), VelY.toFloat(), Score.toInt(), Level.toInt(), Damage.toInt(), Magic.toFloat(), Life.toFloat());

        Game->show();

        connect(Game,&LevelWindow::fin,this,&Login::CloseWindownOpenMe);

    }else{

        QMessageBox::critical(this, tr("ERROR"), tr("Contraseña incorrecta."));
    }

}

void Login::CloseWindownOpenMe()
{

    Game->close();

    this->show();

}
