/********************************************************************************
** Form generated from reading UI file 'userinterfaz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFAZ_H
#define UI_USERINTERFAZ_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterfaz
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *LoginPushButton;
    QPushButton *registerPushButton;
    QPushButton *CloseMepushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserInterfaz)
    {
        if (UserInterfaz->objectName().isEmpty())
            UserInterfaz->setObjectName(QString::fromUtf8("UserInterfaz"));
        UserInterfaz->resize(956, 593);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sprites/LOGO/LOGO.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        UserInterfaz->setWindowIcon(icon);
        centralwidget = new QWidget(UserInterfaz);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 90, 561, 401));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        LoginPushButton = new QPushButton(widget);
        LoginPushButton->setObjectName(QString::fromUtf8("LoginPushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        LoginPushButton->setFont(font1);

        verticalLayout->addWidget(LoginPushButton);

        registerPushButton = new QPushButton(widget);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));
        registerPushButton->setFont(font1);

        verticalLayout->addWidget(registerPushButton);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        CloseMepushButton = new QPushButton(widget);
        CloseMepushButton->setObjectName(QString::fromUtf8("CloseMepushButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nunito Black"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        CloseMepushButton->setFont(font2);

        gridLayout->addWidget(CloseMepushButton, 2, 0, 1, 1);

        UserInterfaz->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserInterfaz);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 956, 25));
        UserInterfaz->setMenuBar(menubar);
        statusbar = new QStatusBar(UserInterfaz);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserInterfaz->setStatusBar(statusbar);

        retranslateUi(UserInterfaz);

        QMetaObject::connectSlotsByName(UserInterfaz);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterfaz)
    {
        UserInterfaz->setWindowTitle(QApplication::translate("UserInterfaz", "Ragnarok", nullptr));
        label->setText(QApplication::translate("UserInterfaz", "<html><head/><body><p><span style=\" font-size:48pt; color:#0000ff;\">RAGNAROK</span></p></body></html>", nullptr));
        LoginPushButton->setText(QApplication::translate("UserInterfaz", "LOGIN", nullptr));
        registerPushButton->setText(QApplication::translate("UserInterfaz", "REGISTER", nullptr));
        CloseMepushButton->setText(QApplication::translate("UserInterfaz", "CLOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInterfaz: public Ui_UserInterfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFAZ_H
