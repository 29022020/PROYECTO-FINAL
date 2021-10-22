#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

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

private:
    Ui::Login *ui;

signals:

    void fin(int x);
};

#endif // LOGIN_H
