#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:

    explicit Register(QWidget *parent = nullptr);
    ~Register();

public slots:

    void RegisterAction();

    void closeMe();

private:

    Ui::Register *ui;

signals:

    void fin(int x);
};

#endif // REGISTER_H
