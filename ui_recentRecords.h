/********************************************************************************
** Form generated from reading UI file 'recentRecords.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECENTRECORDS_H
#define UI_RECENTRECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recentRecords
{
public:
    QLabel *label;
    QListView *listView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *recentRecords)
    {
        if (recentRecords->objectName().isEmpty())
            recentRecords->setObjectName("recentRecords");
        recentRecords->resize(397, 321);
        recentRecords->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 244, 255);"));
        label = new QLabel(recentRecords);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 10, 121, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font.setPointSize(14);
        font.setBold(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        listView = new QListView(recentRecords);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(70, 60, 256, 192));
        listView->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 255, 229);"));
        pushButton = new QPushButton(recentRecords);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 260, 56, 18));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font1.setPointSize(11);
        font1.setBold(true);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 255, 198);\n"
"alternate-background-color: rgb(255, 170, 255);"));
        pushButton_2 = new QPushButton(recentRecords);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 260, 56, 18));
        pushButton_2->setFont(font1);
        radioButton = new QRadioButton(recentRecords);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(80, 40, 72, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        radioButton->setFont(font2);
        radioButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 127);"));
        radioButton_2 = new QRadioButton(recentRecords);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(160, 40, 81, 16));
        radioButton_2->setFont(font2);
        radioButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 127);"));
        radioButton_3 = new QRadioButton(recentRecords);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(240, 40, 72, 16));
        radioButton_3->setFont(font2);
        radioButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 127);"));

        retranslateUi(recentRecords);

        QMetaObject::connectSlotsByName(recentRecords);
    } // setupUi

    void retranslateUi(QWidget *recentRecords)
    {
        recentRecords->setWindowTitle(QCoreApplication::translate("recentRecords", "Form", nullptr));
        label->setText(QCoreApplication::translate("recentRecords", "Recent account", nullptr));
        pushButton->setText(QCoreApplication::translate("recentRecords", "Analyse", nullptr));
        pushButton_2->setText(QCoreApplication::translate("recentRecords", "back", nullptr));
        radioButton->setText(QCoreApplication::translate("recentRecords", "Recent a week", nullptr));
        radioButton_2->setText(QCoreApplication::translate("recentRecords", "Recent a month", nullptr));
        radioButton_3->setText(QCoreApplication::translate("recentRecords", "Recent a year", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recentRecords: public Ui_recentRecords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECENTRECORDS_H
