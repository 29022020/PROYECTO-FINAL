#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlQuery>//Acceso
#include <QtSql/QSqlError>//Errores
#include <QDebug>
#include <QMessageBox>
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

private:

    Ui::Register *ui;

signals:

    void fin(int x);
};

#endif // REGISTER_H
