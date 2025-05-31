/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName("Start");
        Start->resize(524, 392);
        Start->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 0);\n"
"color: rgb(170, 170, 255);\n"
"background-color: rgb(219, 255, 254);"));
        centralwidget = new QWidget(Start);
        centralwidget->setObjectName("centralwidget");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 270, 81, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Tempus Sans ITC\";\n"
"background-color: rgb(255, 85, 0);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 270, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 9pt \"Tempus Sans ITC\";\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"font: 12pt \"Tempus Sans ITC\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 190, 121, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font1.setPointSize(20);
        label_3->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 110, 131, 61));
        label_2->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 70, 71, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font2.setPointSize(22);
        label->setFont(font2);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 130, 121, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(270, 200, 121, 21));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        Start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Start);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 524, 18));
        Start->setMenuBar(menubar);
        statusbar = new QStatusBar(Start);
        statusbar->setObjectName("statusbar");
        Start->setStatusBar(statusbar);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QMainWindow *Start)
    {
        Start->setWindowTitle(QCoreApplication::translate("Start", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Start", "Confirm", nullptr));
        pushButton->setText(QCoreApplication::translate("Start", "Create new", nullptr));
        label_3->setText(QCoreApplication::translate("Start", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("Start", "Your name:", nullptr));
        label->setText(QCoreApplication::translate("Start", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
