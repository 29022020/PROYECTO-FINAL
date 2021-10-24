#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include "login.h"
#include "mumainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlQuery>//Acceso
#include <QtSql/QSqlError>//Errores
#include <QDebug>

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:

    void on_RegisterpushButton_clicked();

    void on_LoginpushButton_clicked();

private:
    Ui::Register *ui;

    QSqlDatabase db;
};

#endif // REGISTER_H
