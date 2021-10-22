#include "mymainwindow.h"
#include "levelwindow.h"
#include "startmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LevelWindow w;
   // StartMenu w;
    w.show();
    return a.exec();
}
