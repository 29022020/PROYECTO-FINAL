#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H
/*
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include "personajesotrak.h"
#include "plataformrandi.h"
#include "powerupitems.h"
#include "proyectilbase.h"
#include "runes.h"
#include "floor.h"
#include "vikingsarena.h"

#define VEL 30

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

    void keyReleaseEvent(QKeyEvent *event);

private:

    Ui::MyMainWindow *ui;

    PersonajeSotrak *BjornSotrack;

    QVector <PlataformRandI*> Plataforms;

    QVector <Floor*> MyFloor;

    PlataformRandI *Plataform;

    QVector<VikingsArena*> Vikings;

    unsigned int ContSwordAttack;

    unsigned int ContSpriteAttack;

    bool FlagSwordAttack;

    bool FlagSwordAttackActive;

    bool FlagWindow;

    void CreateMyFloor(void);

};*/
#endif // MYMAINWINDOW_H
