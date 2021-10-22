#include "mumainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MuMainWindow w;
    w.show();
    return a.exec();
}
