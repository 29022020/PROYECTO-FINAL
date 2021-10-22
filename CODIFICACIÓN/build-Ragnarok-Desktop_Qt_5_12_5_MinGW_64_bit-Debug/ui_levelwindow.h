/********************************************************************************
** Form generated from reading UI file 'levelwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELWINDOW_H
#define UI_LEVELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LevelWindow)
    {
        if (LevelWindow->objectName().isEmpty())
            LevelWindow->setObjectName(QString::fromUtf8("LevelWindow"));
        LevelWindow->resize(1300, 823);
        centralwidget = new QWidget(LevelWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 50, 1240, 680));
        LevelWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LevelWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 25));
        LevelWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LevelWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LevelWindow->setStatusBar(statusbar);

        retranslateUi(LevelWindow);

        QMetaObject::connectSlotsByName(LevelWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LevelWindow)
    {
        LevelWindow->setWindowTitle(QApplication::translate("LevelWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelWindow: public Ui_LevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELWINDOW_H
