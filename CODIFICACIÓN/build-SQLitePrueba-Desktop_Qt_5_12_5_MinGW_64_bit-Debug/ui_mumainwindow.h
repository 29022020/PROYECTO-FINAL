/********************************************************************************
** Form generated from reading UI file 'mumainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUMAINWINDOW_H
#define UI_MUMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MuMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AddNameushButton;
    QTableWidget *tableDates;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *userLE;
    QLineEdit *passwordLE;
    QLineEdit *posXLE;
    QLineEdit *posYLE;
    QLineEdit *scoreLE;
    QLineEdit *lifeLE;
    QLineEdit *damageLE;
    QLineEdit *levelLE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MuMainWindow)
    {
        if (MuMainWindow->objectName().isEmpty())
            MuMainWindow->setObjectName(QString::fromUtf8("MuMainWindow"));
        MuMainWindow->setWindowModality(Qt::ApplicationModal);
        MuMainWindow->resize(1095, 600);
        centralwidget = new QWidget(MuMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AddNameushButton = new QPushButton(centralwidget);
        AddNameushButton->setObjectName(QString::fromUtf8("AddNameushButton"));
        AddNameushButton->setGeometry(QRect(440, 510, 211, 31));
        tableDates = new QTableWidget(centralwidget);
        if (tableDates->columnCount() < 8)
            tableDates->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableDates->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableDates->setObjectName(QString::fromUtf8("tableDates"));
        tableDates->setGeometry(QRect(10, 10, 1001, 401));
        tableDates->verticalHeader()->setVisible(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 430, 971, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userLE = new QLineEdit(layoutWidget);
        userLE->setObjectName(QString::fromUtf8("userLE"));

        horizontalLayout->addWidget(userLE);

        passwordLE = new QLineEdit(layoutWidget);
        passwordLE->setObjectName(QString::fromUtf8("passwordLE"));
        passwordLE->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(passwordLE);

        posXLE = new QLineEdit(layoutWidget);
        posXLE->setObjectName(QString::fromUtf8("posXLE"));

        horizontalLayout->addWidget(posXLE);

        posYLE = new QLineEdit(layoutWidget);
        posYLE->setObjectName(QString::fromUtf8("posYLE"));

        horizontalLayout->addWidget(posYLE);

        scoreLE = new QLineEdit(layoutWidget);
        scoreLE->setObjectName(QString::fromUtf8("scoreLE"));

        horizontalLayout->addWidget(scoreLE);

        lifeLE = new QLineEdit(layoutWidget);
        lifeLE->setObjectName(QString::fromUtf8("lifeLE"));

        horizontalLayout->addWidget(lifeLE);

        damageLE = new QLineEdit(layoutWidget);
        damageLE->setObjectName(QString::fromUtf8("damageLE"));

        horizontalLayout->addWidget(damageLE);

        levelLE = new QLineEdit(layoutWidget);
        levelLE->setObjectName(QString::fromUtf8("levelLE"));

        horizontalLayout->addWidget(levelLE);

        MuMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MuMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1095, 25));
        MuMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MuMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MuMainWindow->setStatusBar(statusbar);

        retranslateUi(MuMainWindow);

        QMetaObject::connectSlotsByName(MuMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MuMainWindow)
    {
        MuMainWindow->setWindowTitle(QApplication::translate("MuMainWindow", "MuMainWindow", nullptr));
        AddNameushButton->setText(QApplication::translate("MuMainWindow", "ADD USER", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableDates->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MuMainWindow", "user", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDates->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MuMainWindow", "password", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDates->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MuMainWindow", "PosX", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableDates->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MuMainWindow", "PosY", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableDates->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MuMainWindow", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableDates->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MuMainWindow", "Life", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableDates->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MuMainWindow", "Damage", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableDates->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MuMainWindow", "Level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MuMainWindow: public Ui_MuMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUMAINWINDOW_H
