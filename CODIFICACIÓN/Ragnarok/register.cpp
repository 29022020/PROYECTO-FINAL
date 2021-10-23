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

}

void Register::closeMe()
{
    emit fin(3);
}
