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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *LineEditUsernameL;
    QLineEdit *LineEditPassWordL;
    QPushButton *loginPushButtom;
    QPushButton *closePushButton;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sprites/LOGO/LOGO.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 70, 611, 401));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LineEditUsernameL = new QLineEdit(widget);
        LineEditUsernameL->setObjectName(QString::fromUtf8("LineEditUsernameL"));

        verticalLayout_3->addWidget(LineEditUsernameL);

        LineEditPassWordL = new QLineEdit(widget);
        LineEditPassWordL->setObjectName(QString::fromUtf8("LineEditPassWordL"));
        LineEditPassWordL->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(LineEditPassWordL);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        loginPushButtom = new QPushButton(widget);
        loginPushButtom->setObjectName(QString::fromUtf8("loginPushButtom"));
        loginPushButtom->setFont(font);

        gridLayout->addWidget(loginPushButtom, 2, 0, 1, 1);

        closePushButton = new QPushButton(widget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setFont(font);

        gridLayout->addWidget(closePushButton, 3, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

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
        Login->setWindowTitle(QApplication::translate("Login", "Ragnarok", nullptr));
        label->setText(QApplication::translate("Login", "USERNAME:", nullptr));
        label_2->setText(QApplication::translate("Login", "PASSWORD:", nullptr));
        loginPushButtom->setText(QApplication::translate("Login", "LOGIN", nullptr));
        closePushButton->setText(QApplication::translate("Login", "CLOSE", nullptr));
        label_3->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#0000ff;\">  LOGIN USER</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
