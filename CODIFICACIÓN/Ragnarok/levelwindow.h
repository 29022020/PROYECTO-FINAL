#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

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
#include "axe.h"

#define VEL 30

namespace Ui {
class LevelWindow;
}

class LevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelWindow(QWidget *parent = nullptr);

    ~LevelWindow();

    QGraphicsScene *scene;

    QTimer *GlobalTime;

    void OnStartGame();

    void advance(int phase);

    void OnUpdate();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::LevelWindow *ui;

    PersonajeSotrak *BjornSotrack;

    QVector <PlataformRandI*> Plataforms;

    QVector <Floor*> MyFloor;

    QVector <PowerUpItems*> Items;

    QVector <Runes*> MyRunes;

    PlataformRandI *Plataform;

    QVector<VikingsArena*> Vikings;

    Axe *MyAxe;

    unsigned int ContSwordAttack;

    unsigned int ContSpriteAttack;

    unsigned int VelXpersonaje;

    unsigned int VelYpersonaje;

    bool FlagSwordAttack;

    bool FlagSwordAttackActive;

    bool FlagWindow;

    void CreateMyFloor(void);

};

#endif // LEVELWINDOW_H
