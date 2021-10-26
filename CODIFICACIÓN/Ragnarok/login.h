#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlQuery>//Acceso
#include <QtSql/QSqlError>//Errores
#include <QDebug>
#include <QMessageBox>
#include "levelwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:

    void closeMe();

    void LoginAction();

    void CloseWindownOpenMe(void);

private:
    Ui::Login *ui;

    LevelWindow *Game;

signals:

    void fin(int x);
};

#endif // LOGIN_H
