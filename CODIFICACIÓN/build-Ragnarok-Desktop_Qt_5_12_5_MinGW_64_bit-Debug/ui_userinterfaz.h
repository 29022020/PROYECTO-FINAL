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
#include <QtWidgets/QApplication>
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
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
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
        centralwidget = new QWidget(UserInterfaz);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 70, 521, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito Black"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 210, 411, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LoginPushButton = new QPushButton(layoutWidget);
        LoginPushButton->setObjectName(QString::fromUtf8("LoginPushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        LoginPushButton->setFont(font1);

        verticalLayout->addWidget(LoginPushButton);

        registerPushButton = new QPushButton(layoutWidget);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));
        registerPushButton->setFont(font1);

        verticalLayout->addWidget(registerPushButton);

        CloseMepushButton = new QPushButton(centralwidget);
        CloseMepushButton->setObjectName(QString::fromUtf8("CloseMepushButton"));
        CloseMepushButton->setGeometry(QRect(420, 430, 171, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nunito Black"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        CloseMepushButton->setFont(font2);
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
        UserInterfaz->setWindowTitle(QApplication::translate("UserInterfaz", "MainWindow", nullptr));
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
