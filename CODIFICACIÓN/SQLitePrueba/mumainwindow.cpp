#include "mumainwindow.h"
#include "ui_mumainwindow.h"

MuMainWindow::MuMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MuMainWindow)
{
    ui->setupUi(this);
}

MuMainWindow::~MuMainWindow()
{
    delete ui;
}

