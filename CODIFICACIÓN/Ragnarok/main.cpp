#include "mymainwindow.h"
#include "startmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
   // StartMenu w;
    w.show();
    return a.exec();
}
