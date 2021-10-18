#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "personajesotrak.h"
#include <QKeyEvent>
#include <QTimer>

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


};
#endif // MYMAINWINDOW_H
