#ifndef USERINTERFAZ_H
#define USERINTERFAZ_H

#include <QMainWindow>

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
};

#endif // USERINTERFAZ_H
