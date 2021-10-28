#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

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
#include <QMessageBox>
#include "proyectilbase.h"
#include "god.h"
#include <iostream>
#include <fstream>

#define VEL 30


using namespace std;
namespace Ui {
class Multiplayer;
}

class Multiplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = nullptr);
    ~Multiplayer();

    Multiplayer(QWidget *parent, QString User, float MyPosX, int MyPosY, float MyVelX, int MyVelY,int Score, int level, float damage, float magic, float life);
   // PersonajeSotrak(float MyPosX_, float MyPosY_, float MyVelX, float MyVelX, float MyDamage, float MyMagic, float MyLife_,int MyScore_,QGraphicsScene *MyScene_);

   QGraphicsScene *scene;

   QTimer *GlobalTime;

   QTimer *AuxTime;

   void OnStartGame();

   void advance(int phase);

   void OnUpdate();

   void OnUpdate2();

   void keyPressEvent(QKeyEvent *event);

   void keyReleaseEvent(QKeyEvent *event);

   void putVikingsArena();

public slots:

   void closeMe();

private:

   Ui::Multiplayer *ui;

   PersonajeSotrak *BjornSotrack;

   PersonajeSotrak *BjornSotrack2;

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
   //////

   unsigned int ContSwordAttack2;

   unsigned int ConTProyectiles2;

   unsigned int ContSpriteAttack2;

   unsigned int ContProyectilKill2;

   unsigned int VelXpersonaje2;

   unsigned int VelYpersonaje2;

   unsigned int MyLevel2;

   bool FlagSwordAttack2;

   bool FlagSwordAttackActive2;

   bool FlagWindow2;

   void CreateMyFloor(int);

   QMediaPlayer *player;

   QMediaPlayer *espada;
signals:

   void fin(int x);

   void ChangeLevelSignal(int x);
};

#endif // MULTIPLAYER_H
