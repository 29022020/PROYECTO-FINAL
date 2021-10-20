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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *easyRadioButton;
    QRadioButton *hardRadioButton;
    QPushButton *registerPushButton;
    QLabel *label_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *LineEditUsernameR;
    QLineEdit *LineEditPassWordR;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(800, 600);
        centralwidget = new QWidget(Register);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 360, 271, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        easyRadioButton = new QRadioButton(layoutWidget);
        easyRadioButton->setObjectName(QString::fromUtf8("easyRadioButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        easyRadioButton->setFont(font);

        verticalLayout->addWidget(easyRadioButton);

        hardRadioButton = new QRadioButton(layoutWidget);
        hardRadioButton->setObjectName(QString::fromUtf8("hardRadioButton"));
        hardRadioButton->setFont(font);

        verticalLayout->addWidget(hardRadioButton);

        registerPushButton = new QPushButton(centralwidget);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));
        registerPushButton->setGeometry(QRect(290, 480, 161, 51));
        registerPushButton->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 60, 551, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(150, 170, 471, 171));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LineEditUsernameR = new QLineEdit(layoutWidget_2);
        LineEditUsernameR->setObjectName(QString::fromUtf8("LineEditUsernameR"));

        verticalLayout_3->addWidget(LineEditUsernameR);

        LineEditPassWordR = new QLineEdit(layoutWidget_2);
        LineEditPassWordR->setObjectName(QString::fromUtf8("LineEditPassWordR"));

        verticalLayout_3->addWidget(LineEditPassWordR);


        horizontalLayout->addLayout(verticalLayout_3);

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
        Register->setWindowTitle(QApplication::translate("Register", "MainWindow", nullptr));
        easyRadioButton->setText(QApplication::translate("Register", "EASY", nullptr));
        hardRadioButton->setText(QApplication::translate("Register", "HARD", nullptr));
        registerPushButton->setText(QApplication::translate("Register", "REGISTER", nullptr));
        label_3->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" color:#0000ff;\">REGISTER USER</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("Register", "USERNAME:", nullptr));
        label_2->setText(QApplication::translate("Register", "PASSWORD:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
