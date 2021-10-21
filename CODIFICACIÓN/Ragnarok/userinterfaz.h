#ifndef USERINTERFAZ_H
#define USERINTERFAZ_H

#include <QMainWindow>
#include "login.h"
#include "register.h"

namespace Ui {
class UserInterfaz;
}

class UserInterfaz : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterfaz(QWidget *parent = nullptr);
    ~UserInterfaz();

private:

    Ui::UserInterfaz *ui;

    Login *LoginWindow;

    Register *RegisterWindow;

    bool FlagL;

    bool FlagR;

public slots:

    void LoginS();

    void RegisterS();

    void CloseWindownOpenMe();

    void closeMe();

signals:

    void fin(int x);

};

#endif // USERINTERFAZ_H
