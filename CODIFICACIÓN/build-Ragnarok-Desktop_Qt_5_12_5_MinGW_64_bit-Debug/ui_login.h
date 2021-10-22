/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QPushButton *loginPushButtom;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *LineEditUsernameL;
    QLineEdit *LineEditPassWordL;
    QPushButton *closePushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loginPushButtom = new QPushButton(centralwidget);
        loginPushButtom->setObjectName(QString::fromUtf8("loginPushButtom"));
        loginPushButtom->setGeometry(QRect(320, 410, 161, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        loginPushButtom->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 100, 561, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 220, 481, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LineEditUsernameL = new QLineEdit(layoutWidget);
        LineEditUsernameL->setObjectName(QString::fromUtf8("LineEditUsernameL"));

        verticalLayout_3->addWidget(LineEditUsernameL);

        LineEditPassWordL = new QLineEdit(layoutWidget);
        LineEditPassWordL->setObjectName(QString::fromUtf8("LineEditPassWordL"));

        verticalLayout_3->addWidget(LineEditPassWordL);


        horizontalLayout->addLayout(verticalLayout_3);

        closePushButton = new QPushButton(centralwidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(350, 490, 101, 41));
        closePushButton->setFont(font);
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "MainWindow", nullptr));
        loginPushButtom->setText(QApplication::translate("Login", "LOGIN", nullptr));
        label_3->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#0000ff;\">LOGIN USER</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("Login", "USERNAME:", nullptr));
        label_2->setText(QApplication::translate("Login", "PASSWORD:", nullptr));
        closePushButton->setText(QApplication::translate("Login", "CLOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
