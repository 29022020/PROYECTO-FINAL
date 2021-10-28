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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multiplayer
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *MyLevel_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MyLevel_2;
    QLabel *MyLevelValue_2;
    QLabel *MyScore_2;
    QLabel *MyScoreValue_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *MyLevel_3;
    QHBoxLayout *horizontalLayout;
    QLabel *MyLevel;
    QLabel *MyLevelValue;
    QLabel *MyScore;
    QLabel *MyScoreValue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Multiplayer)
    {
        if (Multiplayer->objectName().isEmpty())
            Multiplayer->setObjectName(QString::fromUtf8("Multiplayer"));
        Multiplayer->resize(1300, 943);
        centralwidget = new QWidget(Multiplayer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 60, 1240, 700));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(870, 0, 411, 61));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        MyLevel_4 = new QLabel(layoutWidget);
        MyLevel_4->setObjectName(QString::fromUtf8("MyLevel_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        MyLevel_4->setFont(font);

        horizontalLayout_3->addWidget(MyLevel_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        MyLevel_2 = new QLabel(layoutWidget);
        MyLevel_2->setObjectName(QString::fromUtf8("MyLevel_2"));
        MyLevel_2->setFont(font);

        horizontalLayout_4->addWidget(MyLevel_2);

        MyLevelValue_2 = new QLabel(layoutWidget);
        MyLevelValue_2->setObjectName(QString::fromUtf8("MyLevelValue_2"));
        MyLevelValue_2->setFont(font);

        horizontalLayout_4->addWidget(MyLevelValue_2);

        MyScore_2 = new QLabel(layoutWidget);
        MyScore_2->setObjectName(QString::fromUtf8("MyScore_2"));
        MyScore_2->setFont(font);

        horizontalLayout_4->addWidget(MyScore_2);

        MyScoreValue_2 = new QLabel(layoutWidget);
        MyScoreValue_2->setObjectName(QString::fromUtf8("MyScoreValue_2"));
        MyScoreValue_2->setFont(font);

        horizontalLayout_4->addWidget(MyScoreValue_2);


        horizontalLayout_3->addLayout(horizontalLayout_4);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 0, 411, 61));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        MyLevel_3 = new QLabel(widget);
        MyLevel_3->setObjectName(QString::fromUtf8("MyLevel_3"));
        MyLevel_3->setFont(font);

        horizontalLayout_2->addWidget(MyLevel_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MyLevel = new QLabel(widget);
        MyLevel->setObjectName(QString::fromUtf8("MyLevel"));
        MyLevel->setFont(font);

        horizontalLayout->addWidget(MyLevel);

        MyLevelValue = new QLabel(widget);
        MyLevelValue->setObjectName(QString::fromUtf8("MyLevelValue"));
        MyLevelValue->setFont(font);

        horizontalLayout->addWidget(MyLevelValue);

        MyScore = new QLabel(widget);
        MyScore->setObjectName(QString::fromUtf8("MyScore"));
        MyScore->setFont(font);

        horizontalLayout->addWidget(MyScore);

        MyScoreValue = new QLabel(widget);
        MyScoreValue->setObjectName(QString::fromUtf8("MyScoreValue"));
        MyScoreValue->setFont(font);

        horizontalLayout->addWidget(MyScoreValue);


        horizontalLayout_2->addLayout(horizontalLayout);

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
        Multiplayer->setWindowTitle(QApplication::translate("Multiplayer", "MainWindow", nullptr));
        MyLevel_4->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#ff0000;\">PLAYER 2-</span></p></body></html>", nullptr));
        MyLevel_2->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#ff0000;\">My LIFE:</span></p></body></html>", nullptr));
        MyLevelValue_2->setText(QApplication::translate("Multiplayer", "0", nullptr));
        MyScore_2->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#ff0000;\">My SCORE:</span></p></body></html>", nullptr));
        MyScoreValue_2->setText(QApplication::translate("Multiplayer", "0", nullptr));
        MyLevel_3->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#0000ff;\">PLAYER 1-</span></p></body></html>", nullptr));
        MyLevel->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#0000ff;\">My LIFE:</span></p></body></html>", nullptr));
        MyLevelValue->setText(QApplication::translate("Multiplayer", "0", nullptr));
        MyScore->setText(QApplication::translate("Multiplayer", "<html><head/><body><p><span style=\" color:#0000ff;\">My SCORE:</span></p></body></html>", nullptr));
        MyScoreValue->setText(QApplication::translate("Multiplayer", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multiplayer: public Ui_Multiplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYER_H
