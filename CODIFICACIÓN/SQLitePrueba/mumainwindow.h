#ifndef MUMAINWINDOW_H
#define MUMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MuMainWindow; }
QT_END_NAMESPACE

class MuMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MuMainWindow(QWidget *parent = nullptr);
    ~MuMainWindow();

private:
    Ui::MuMainWindow *ui;
};
#endif // MUMAINWINDOW_H
