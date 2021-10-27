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
#include <QMediaPlayer>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlQuery>//Acceso
#include <QtSql/QSqlError>//Errores
#include <QDebug>
#include <QMessageBox>
#include "proyectilbase.h"
#include "god.h"
#include <iostream>
#include <fstream>

#define VEL 30

using namespace std;

namespace Ui {
class LevelWindow;
}

class LevelWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit LevelWindow(QWidget *parent = nullptr);

     LevelWindow(QWidget *parent, QString User, float MyPosX, int MyPosY, float MyVelX, int MyVelY,int Score, int level, float damage, float magic, float life);
    // PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX, float MyVelX, float MyDamage, float MyMagic, float MyLife_,int MyScore_,QGraphicsScene *MyScene_);

    ~LevelWindow();

    QGraphicsScene *scene;

    QTimer *GlobalTime;

    QTimer *AuxTime;

    void OnStartGame();

    void advance(int phase);

    void OnUpdate();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

    void putVikingsArena();

    void ChangeLevel();

public slots:

    void closeMe();

    void SaveMatch();

private:

    Ui::LevelWindow *ui;

    PersonajeSotrak *BjornSotrack;

    QVector <PlataformRandI*> Plataforms;

    QVector <Floor*> MyFloor;

    QVector <PowerUpItems*> Items;

    QVector <Runes*> MyRunes;

    PlataformRandI *Plataform;

    QVector<VikingsArena*> Vikings;

    QVector <God*> Gods;

    QVector <Axe*> MyAxes;

    QVector <ProyectilBase*> ProyectilesGod;

    QString MyName;

    unsigned int ContSwordAttack;

    unsigned int ConTProyectiles;

    unsigned int ContSpriteAttack;

    unsigned int ContProyectilKill;

    unsigned int VelXpersonaje;

    unsigned int VelYpersonaje;

    unsigned int MyLevel;

    bool FlagSwordAttack;

    bool FlagSwordAttackActive;

    bool FlagWindow;

    void CreateMyFloor(int);

    QMediaPlayer *player;

    QMediaPlayer *espada;
signals:

    void fin(int x);
};

#endif // LEVELWINDOW_H
