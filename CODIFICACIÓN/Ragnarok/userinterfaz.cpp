#include "userinterfaz.h"
#include "ui_userinterfaz.h"

UserInterfaz::UserInterfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterfaz)
{
    ui->setupUi(this);
}

UserInterfaz::~UserInterfaz()
{
    delete ui;
}
