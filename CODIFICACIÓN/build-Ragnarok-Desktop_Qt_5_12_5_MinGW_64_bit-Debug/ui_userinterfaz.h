/********************************************************************************
** Form generated from reading UI file 'userinterfaz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFAZ_H
#define UI_USERINTERFAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterfaz
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserInterfaz)
    {
        if (UserInterfaz->objectName().isEmpty())
            UserInterfaz->setObjectName(QString::fromUtf8("UserInterfaz"));
        UserInterfaz->resize(800, 600);
        menubar = new QMenuBar(UserInterfaz);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        UserInterfaz->setMenuBar(menubar);
        centralwidget = new QWidget(UserInterfaz);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        UserInterfaz->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserInterfaz);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserInterfaz->setStatusBar(statusbar);

        retranslateUi(UserInterfaz);

        QMetaObject::connectSlotsByName(UserInterfaz);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterfaz)
    {
        UserInterfaz->setWindowTitle(QApplication::translate("UserInterfaz", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInterfaz: public Ui_UserInterfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFAZ_H
