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
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
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
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(290, 210, 411, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito Black"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        verticalLayout->addWidget(pushButton_2);

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
        pushButton->setText(QApplication::translate("UserInterfaz", "LOGIN", nullptr));
        pushButton_2->setText(QApplication::translate("UserInterfaz", "REGISTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInterfaz: public Ui_UserInterfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFAZ_H
