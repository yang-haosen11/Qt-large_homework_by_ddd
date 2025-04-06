/********************************************************************************
** Form generated from reading UI file 'recordsInput.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDSINPUT_H
#define UI_RECORDSINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordsInput
{
public:
    QLabel *label;
    QPushButton *AlipayButton;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QRadioButton *income;
    QRadioButton *cost;
    QComboBox *recordType;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *recordAmount;
    QLabel *label_6;
    QPushButton *recordConfirm;
    QPushButton *recordBack;

    void setupUi(QWidget *recordsInput)
    {
        if (recordsInput->objectName().isEmpty())
            recordsInput->setObjectName("recordsInput");
        recordsInput->resize(463, 363);
        recordsInput->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 255, 217);"));
        label = new QLabel(recordsInput);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 211, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 127);"));
        AlipayButton = new QPushButton(recordsInput);
        AlipayButton->setObjectName("AlipayButton");
        AlipayButton->setGeometry(QRect(340, 230, 51, 41));
        AlipayButton->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/images/alipay.png);"));
        label_2 = new QLabel(recordsInput);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 90, 71, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font1.setPointSize(16);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
                                                 "color: rgb(0, 0, 0);"));
        dateEdit = new QDateEdit(recordsInput);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(200, 90, 110, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("gridline-color: rgb(255, 59, 20);\n"
                                                  "background-color: rgb(255, 255, 127);"));
        dateEdit->setDateTime(QDateTime(QDate(2025, 4, 30), QTime(0, 0, 0)));
        label_3 = new QLabel(recordsInput);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 130, 81, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font2.setPointSize(14);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 30, 0);"));
        income = new QRadioButton(recordsInput);
        income->setObjectName("income");
        income->setGeometry(QRect(210, 140, 72, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font3.setPointSize(12);
        income->setFont(font3);
        income->setStyleSheet(QString::fromUtf8("color: rgb(0, 51, 0);"));
        cost = new QRadioButton(recordsInput);
        cost->setObjectName("cost");
        cost->setGeometry(QRect(300, 140, 72, 16));
        cost->setFont(font3);
        cost->setStyleSheet(QString::fromUtf8("color: rgb(0, 43, 0);"));
        recordType = new QComboBox(recordsInput);
        recordType->addItem(QString());
        recordType->addItem(QString());
        recordType->setObjectName("recordType");
        recordType->setGeometry(QRect(190, 170, 81, 22));
        recordType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
                                                    "selection-color: rgb(0, 25, 0);"));
        label_4 = new QLabel(recordsInput);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 170, 51, 31));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 42, 0);"));
        label_5 = new QLabel(recordsInput);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 210, 81, 31));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(0,42,0);"));
        recordAmount = new QDoubleSpinBox(recordsInput);
        recordAmount->setObjectName("recordAmount");
        recordAmount->setGeometry(QRect(190, 220, 81, 22));
        recordAmount->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        recordAmount->setMaximum(9999999.990000000223517);
        label_6 = new QLabel(recordsInput);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 280, 141, 41));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        recordConfirm = new QPushButton(recordsInput);
        recordConfirm->setObjectName("recordConfirm");
        recordConfirm->setGeometry(QRect(105, 270, 61, 21));
        recordBack = new QPushButton(recordsInput);
        recordBack->setObjectName("recordBack");
        recordBack->setGeometry(QRect(200, 270, 61, 21));

        retranslateUi(recordsInput);

        QMetaObject::connectSlotsByName(recordsInput);
    } // setupUi

    void retranslateUi(QWidget *recordsInput)
    {
        recordsInput->setWindowTitle(QCoreApplication::translate("recordsInput", "Form", nullptr));
        label->setText(QCoreApplication::translate("recordsInput", "input your account record", nullptr));
        AlipayButton->setText(QString());
        label_2->setText(QCoreApplication::translate("recordsInput", "Time", nullptr));
        label_3->setText(QCoreApplication::translate("recordsInput", "categories", nullptr));
        income->setText(QCoreApplication::translate("recordsInput", "income", nullptr));
        cost->setText(QCoreApplication::translate("recordsInput", "cost", nullptr));
        recordType->setItemText(0, QCoreApplication::translate("recordsInput", "FoodCosts", nullptr));
        recordType->setItemText(1, QCoreApplication::translate("recordsInput", "EntertainCosts", nullptr));

        label_4->setText(QCoreApplication::translate("recordsInput", "type", nullptr));
        label_5->setText(QCoreApplication::translate("recordsInput", "amount", nullptr));
        label_6->setText(QCoreApplication::translate("recordsInput", "import from Alipay", nullptr));
        recordConfirm->setText(QCoreApplication::translate("recordsInput", "confirm", nullptr));
        recordBack->setText(QCoreApplication::translate("recordsInput", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
class recordsInput: public Ui_recordsInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDSINPUT_H
