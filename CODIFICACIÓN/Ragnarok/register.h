#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlQuery>//Acceso
#include <QtSql/QSqlError>//Errores
#include <QDebug>
#include <QMessageBox>
#include "levelwindow.h"

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:

    explicit Register(QWidget *parent = nullptr);
    ~Register();

public slots:

    void RegisterAction();

    void closeMe();

    void crearTabla();

    void CerrarVentanaOpenMe(void);

private:

    Ui::Register *ui;

    LevelWindow *Game;

signals:

    void fin(int x);
};

#endif // REGISTER_H
