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

public slots:

    void CloseMe();

    void CreateInterfaz();

    void MultiPlayer();

    void CloseWindownOpenMe(void);


private:

    Ui::StartMenu *ui;

    UserInterfaz *Interfaz;

    bool FlagI;

    bool FlagM;

};

#endif // STARTMENU_H
