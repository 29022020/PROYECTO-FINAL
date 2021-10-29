/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *LineEditUsernameR;
    QLineEdit *LineEditPassWordR;
    QPushButton *registerPushButton;
    QPushButton *closePushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sprites/LOGO/LOGO.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Register->setWindowIcon(icon);
        centralwidget = new QWidget(Register);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(150, 40, 541, 441));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LineEditUsernameR = new QLineEdit(widget);
        LineEditUsernameR->setObjectName(QString::fromUtf8("LineEditUsernameR"));

        verticalLayout_3->addWidget(LineEditUsernameR);

        LineEditPassWordR = new QLineEdit(widget);
        LineEditPassWordR->setObjectName(QString::fromUtf8("LineEditPassWordR"));
        LineEditPassWordR->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(LineEditPassWordR);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        registerPushButton = new QPushButton(widget);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));
        registerPushButton->setFont(font1);

        gridLayout->addWidget(registerPushButton, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        closePushButton = new QPushButton(widget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setFont(font1);

        gridLayout_2->addWidget(closePushButton, 2, 0, 1, 1);

        Register->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Register);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Register->setMenuBar(menubar);
        statusbar = new QStatusBar(Register);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Register->setStatusBar(statusbar);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QMainWindow *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Ragnarok", nullptr));
        label_3->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" color:#0000ff;\">REGISTER USER</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("Register", "USERNAME:", nullptr));
        label_2->setText(QApplication::translate("Register", "PASSWORD:", nullptr));
        registerPushButton->setText(QApplication::translate("Register", "REGISTER", nullptr));
        closePushButton->setText(QApplication::translate("Register", "CLOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
