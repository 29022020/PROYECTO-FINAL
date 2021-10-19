#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "personajesotrak.h"
#include "plataformrandi.h"
#include "powerupitems.h"
#include "proyectilbase.h"
#include "runes.h"
#include "vikingsarena.h"

#define VEL 20

QT_BEGIN_NAMESPACE
namespace Ui { class MyMainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

    QGraphicsScene *scene;

    QTimer *GlobalTime;

    void OnStartGame();

    void advance(int phase);

    void OnUpdate();

    void keyPressEvent(QKeyEvent *event);

private:

    Ui::MyMainWindow *ui;

    PersonajeSotrak *BjornSotrack;

    QVector <PlataformRandI*> Plataforms;

    PlataformRandI *Plataform;


};
#endif // MYMAINWINDOW_H
