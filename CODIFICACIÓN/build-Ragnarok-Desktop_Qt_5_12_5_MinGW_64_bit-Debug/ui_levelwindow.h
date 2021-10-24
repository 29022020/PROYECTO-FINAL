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
#include <QtWidgets/QLabel>
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
    QLabel *MyLevel;
    QLabel *MyScore;
    QLabel *MyLevelValue;
    QLabel *MyScoreValue;
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
        MyLevel = new QLabel(centralwidget);
        MyLevel->setObjectName(QString::fromUtf8("MyLevel"));
        MyLevel->setGeometry(QRect(10, 0, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        MyLevel->setFont(font);
        MyScore = new QLabel(centralwidget);
        MyScore->setObjectName(QString::fromUtf8("MyScore"));
        MyScore->setGeometry(QRect(270, 0, 131, 41));
        MyScore->setFont(font);
        MyLevelValue = new QLabel(centralwidget);
        MyLevelValue->setObjectName(QString::fromUtf8("MyLevelValue"));
        MyLevelValue->setGeometry(QRect(120, 0, 101, 41));
        MyLevelValue->setFont(font);
        MyScoreValue = new QLabel(centralwidget);
        MyScoreValue->setObjectName(QString::fromUtf8("MyScoreValue"));
        MyScoreValue->setGeometry(QRect(400, 0, 101, 41));
        MyScoreValue->setFont(font);
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
        MyLevel->setText(QApplication::translate("LevelWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">My LIFE:</span></p></body></html>", nullptr));
        MyScore->setText(QApplication::translate("LevelWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">My SCORE:</span></p></body></html>", nullptr));
        MyLevelValue->setText(QApplication::translate("LevelWindow", "0", nullptr));
        MyScoreValue->setText(QApplication::translate("LevelWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelWindow: public Ui_LevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELWINDOW_H
