#ifndef MUMAINWINDOW_H
#define MUMAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlQuery>//Acceso
#include <QtSql/QSqlError>//Errores
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MuMainWindow; }
QT_END_NAMESPACE

class MuMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MuMainWindow(QWidget *parent = nullptr);
    ~MuMainWindow();

    void crearTablaUsaurio();

    void insertarUsuario();

    void mostrarDatos();

private slots:
    void on_AddNameushButton_clicked();

private:
    Ui::MuMainWindow *ui;

    QSqlDatabase db;

};
#endif // MUMAINWINDOW_H
