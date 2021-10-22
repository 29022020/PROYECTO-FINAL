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

}
