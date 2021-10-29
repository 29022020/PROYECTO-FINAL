/********************************************************************************
** Form generated from reading UI file 'multiplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAYER_H
#define UI_MULTIPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multiplayer
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *CSpushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *MyLevel_4;
    QLabel *MyLevel_2;
    QLabel *MyLevelValue_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *MyLevel_3;
    QLabel *MyLevel;
    QLabel *MyLevelValue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Multiplayer)
    {
        if (Multiplayer->objectName().isEmpty())
            Multiplayer->setObjectName(QString::fromUtf8("Multiplayer"));
        Multiplayer->resize(1300, 790);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sprites/LOGO/LOGO.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Multiplayer->setWindowIcon(icon);
        centralwidget = new QWidget(Multiplayer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 60, 1240, 761));
        CSpushButton = new QPushButton(centralwidget);
        CSpushButton->setObjectName(QString::fromUtf8("CSpushButton"));
        CSpushButton->setGeometry(QRect(550, 0, 191, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        CSpushButton->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(970, 0, 431, 51));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        MyLevel_4 = new QLabel(widget);
        MyLevel_4->setObjectName(QString::fromUtf8("MyLevel_4"));
        MyLevel_4->setFont(font);

        horizontalLayout_3->addWidget(MyLevel_4);

        MyLevel_2 = new QLabel(widget);
        MyLevel_2->setObjectName(QString::fromUtf8("MyLevel_2"));
        MyLevel_2->setFont(font);

        horizontalLayout_3->addWidget(MyLevel_2);

        MyLevelValue_2 = new QLabel(widget);
        MyLevelValue_2->setObjectName(QString::fromUtf8("MyLevelValue_2"));
        MyLevelValue_2->setFont(font);

        horizontalLayout_3->addWidget(MyLevelValue_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 0, 391, 61));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MyLevel_3 = new QLabel(widget1);
        MyLevel_3->setObjectName(QString::fromUtf8("MyLevel_3"));
        MyLevel_3->setFont(font);

        horizontalLayout->addWidget(MyLevel_3);

        MyLevel = new QLabel(widget1);
        MyLevel->setObjectName(QString::fromUtf8("MyLevel"));
        MyLevel->setFont(font);

        horizontalLayout->addWidget(MyLevel);

        MyLevelValue = new QLabel(widget1);
        MyLevelValue->setObjectName(QString::fromUtf8("MyLevelValue"));
        MyLevelValue->setFont(font);

        horizontalLayout->addWidget(MyLevelValue);

        Multiplayer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Multiplayer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 25));
        Multiplayer->setMenuBar(menubar);
        statusbar = new QStatusBar(Multiplayer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Multiplayer->setStatusBar(statusbar);

        retranslateUi(Multiplayer);

        QMetaObject::connectSlotsByName(Multiplayer);
    } // setupUi

    void retranslateUi(QMainWindow *Multiplayer)
    {
        Multiplayer->setWindowTitle(QApplication::translate("Multiplayer", "Ragnarok", nullptr));
        CSpushButton->setText(QApplication::translate("Multiplayer", "CLOSE MATCH", nullptr));
        MyLevel_4->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#ff0000;\">PLAYER 2-</span></p></body></html>", nullptr));
        MyLevel_2->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#ff0000;\">My LIFE:</span></p></body></html>", nullptr));
        MyLevelValue_2->setText(QApplication::translate("Multiplayer", "0", nullptr));
        MyLevel_3->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#0000ff;\">PLAYER 1-</span></p></body></html>", nullptr));
        MyLevel->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#0000ff;\">My LIFE:</span></p></body></html>", nullptr));
        MyLevelValue->setText(QApplication::translate("Multiplayer", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multiplayer: public Ui_Multiplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYER_H
