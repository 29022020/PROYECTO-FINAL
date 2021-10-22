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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QWidget *centralwidget;
    QPushButton *closePushButton;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *singlePushButton;
    QPushButton *multiPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName(QString::fromUtf8("StartMenu"));
        StartMenu->resize(800, 600);
        centralwidget = new QWidget(StartMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        closePushButton = new QPushButton(centralwidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(280, 370, 151, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        closePushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 70, 451, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 190, 481, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        singlePushButton = new QPushButton(layoutWidget);
        singlePushButton->setObjectName(QString::fromUtf8("singlePushButton"));
        singlePushButton->setFont(font);

        verticalLayout->addWidget(singlePushButton);

        multiPushButton = new QPushButton(layoutWidget);
        multiPushButton->setObjectName(QString::fromUtf8("multiPushButton"));
        multiPushButton->setFont(font);

        verticalLayout->addWidget(multiPushButton);

        StartMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        StartMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(StartMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartMenu->setStatusBar(statusbar);

        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QMainWindow *StartMenu)
    {
        StartMenu->setWindowTitle(QApplication::translate("StartMenu", "MainWindow", nullptr));
        closePushButton->setText(QApplication::translate("StartMenu", "CLOSE", nullptr));
        label->setText(QApplication::translate("StartMenu", "<html><head/><body><p><span style=\" color:#0000ff;\">RAGNAROK</span></p></body></html>", nullptr));
        singlePushButton->setText(QApplication::translate("StartMenu", "SINGLE PLAYER", nullptr));
        multiPushButton->setText(QApplication::translate("StartMenu", "MULTIPLAYER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
