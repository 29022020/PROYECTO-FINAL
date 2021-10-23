#include "mumainwindow.h"
#include "ui_mumainwindow.h"


MuMainWindow::MuMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MuMainWindow)
{
    ui->setupUi(this);

     qDebug()<<"Start";

     QString nombre;

     nombre.append("BaseDeDatos3.sqlite");

     db = QSqlDatabase ::addDatabase("QSQLITE");

     db.setDatabaseName(nombre);

     if(db.open()){

         qDebug()<<"Se ha conectado a la base de datos.";

     }else{
         qDebug()<<"No se ha conectado a la base de datos.";
     }

     crearTablaUsaurio();


}

MuMainWindow::~MuMainWindow()
{
    delete ui;
}

void MuMainWindow::crearTablaUsaurio()
{
    QString consulta;

    consulta.append("CREATE TABLE IF NOT EXISTS users( "
                    "user VARCHAR(100),"
                    "password VARCHAR(100),"
                    "PosX INTEGER NOT NULL,"
                    "PosY INTEGER NOT NULL,"
                    "Score INTEGER NOT NULL,"
                    "Life INTEGER NOT NULL,"
                    "Damage INTEGER NOT NULL,"
                    "Level INTEGER NOT NULL"
                    ");");
     QSqlQuery crear;

     crear.prepare(consulta);

     if(crear.exec()){

         qDebug()<<"TABLA usuarios existe o se ha creado correctamente.";

     }else{

         qDebug()<<"TABLA usuarios NO existe o NO se ha creado correctamente.";
         qDebug()<<"ERROR!: "<<crear.lastError();
     }
     mostrarDatos();

}

void MuMainWindow::insertarUsuario()
{
    QString consulta;

    consulta.append("INSERT INTO users("
                    "user,"
                    "password,"
                    "PosX,"
                    "PosY,"
                    "Score,"
                    "Life,"
                    "Damage,"
                    "Level)"
                    "VALUES("
                    "'"+ui->userLE->text()+"',"
                    "'"+ui->passwordLE->text()+"',"
                    "'"+ui->posXLE->text()+"',"
                    "'"+ui->posYLE->text()+"',"
                    "'"+ui->scoreLE->text()+"',"
                    "'"+ui->lifeLE->text()+"',"
                    "'"+ui->damageLE->text()+"',"
                    "'"+ui->levelLE->text()+"'"
                    ");");

     QSqlQuery insertar;

     insertar.prepare(consulta);

     if(insertar.exec()){

         qDebug()<<"El USER ha sido insertado.";

     }else{

         qDebug()<<"El USER no se ha insertado correctamente.";
         qDebug()<<"ERROR!: "<<insertar.lastError();
     }

     mostrarDatos();

}

void MuMainWindow::mostrarDatos()
{
    QString consulta;

    consulta.append("SELECT * FROM users;");

     QSqlQuery consultar;

     consultar.prepare(consulta);

     if(consultar.exec()){

         qDebug()<<"Se ha consultado correctamente.";

     }else{

         qDebug()<<"NO se ha consultado correctamente.";
         qDebug()<<"ERROR!: "<<consultar.lastError();
     }

     int fila=0;

     ui->tableDates->setRowCount(0);

     while(consultar.next()){

         ui->tableDates->insertRow(fila);

         ui->tableDates->setItem(fila, 0, new QTableWidgetItem(consultar.value(0).toByteArray().constData()));

         ui->tableDates->setItem(fila, 1, new QTableWidgetItem(consultar.value(1).toByteArray().constData()));

         ui->tableDates->setItem(fila, 2, new QTableWidgetItem(consultar.value(2).toByteArray().constData()));

         ui->tableDates->setItem(fila, 3, new QTableWidgetItem(consultar.value(3).toByteArray().constData()));

         ui->tableDates->setItem(fila, 4, new QTableWidgetItem(consultar.value(4).toByteArray().constData()));

         ui->tableDates->setItem(fila, 5, new QTableWidgetItem(consultar.value(5).toByteArray().constData()));

         ui->tableDates->setItem(fila, 6, new QTableWidgetItem(consultar.value(6).toByteArray().constData()));

         ui->tableDates->setItem(fila, 7, new QTableWidgetItem(consultar.value(7).toByteArray().constData()));


         fila++;

     }



}




void MuMainWindow::on_AddNameushButton_clicked()
{
    insertarUsuario();
}
