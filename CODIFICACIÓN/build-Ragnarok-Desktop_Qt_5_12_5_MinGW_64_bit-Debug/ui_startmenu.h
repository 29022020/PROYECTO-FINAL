/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName(QString::fromUtf8("StartMenu"));
        StartMenu->resize(800, 600);
        menubar = new QMenuBar(StartMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        StartMenu->setMenuBar(menubar);
        centralwidget = new QWidget(StartMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        StartMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StartMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartMenu->setStatusBar(statusbar);

        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QMainWindow *StartMenu)
    {
        StartMenu->setWindowTitle(QApplication::translate("StartMenu", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
