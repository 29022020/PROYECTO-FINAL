#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include "userinterfaz.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

private:
    Ui::StartMenu *ui;
    UserInterfaz *Interfaz;
};

#endif // STARTMENU_H
