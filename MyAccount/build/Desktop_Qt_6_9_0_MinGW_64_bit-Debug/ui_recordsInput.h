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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

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

    void setupUi(QMainWindow *recordsInput)
    {
        if (recordsInput->objectName().isEmpty())
            recordsInput->setObjectName("recordsInput");
        recordsInput->resize(463, 363);
        recordsInput->setStyleSheet(QString::fromUtf8("\n"
"  /* === \345\274\272\345\210\266\351\207\215\347\275\256\346\211\200\346\234\211\345\205\203\347\264\240 === */\n"
"  * {\n"
"      color: black !important;\n"
"      font-family: \"Microsoft YaHei\" !important;\n"
"  }\n"
"\n"
"  /* \344\270\273\347\252\227\345\217\243\350\203\214\346\231\257 */\n"
"  QMainWindow {\n"
"      background-color: #f5fff0;\n"
"  }\n"
"\n"
"  /* \350\276\223\345\205\245\346\216\247\344\273\266\345\274\272\345\210\266\346\240\267\345\274\217 */\n"
"  QDateEdit, QComboBox, QDoubleSpinBox {\n"
"      background-color: white !important;\n"
"      border: 1px solid #81c784 !important;\n"
"      border-radius: 4px !important;\n"
"      padding: 5px !important;\n"
"      min-height: 25px !important;\n"
"      color: black !important;\n"
"  }\n"
"\n"
"  /* \346\225\260\345\255\227\350\276\223\345\205\245\346\241\206\347\211\271\345\210\253\345\244\204\347\220\206 */\n"
"  QDoubleSpinBox {\n"
"      background-color: white !important;\n"
"  }\n"
"\n"
"  /* \344\270\213\346\213\211\346"
                        "\241\206\351\200\211\351\241\271 */\n"
"  QComboBox QAbstractItemView {\n"
"      background-color: white !important;\n"
"      color: black !important;\n"
"  }\n"
"\n"
"  /* \346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"  QPushButton:not(#AlipayButton) {\n"
"      background-color: #66bb6a !important;\n"
"      color: white !important;\n"
"      border: none !important;\n"
"      border-radius: 4px !important;\n"
"      padding: 8px 12px !important;\n"
"      min-width: 80px !important;\n"
"  }\n"
"\n"
"  /* \346\240\207\351\242\230\346\240\267\345\274\217 */\n"
"  #label {\n"
"      font-size: 20px !important;\n"
"      font-weight: bold !important;\n"
"      qproperty-alignment: AlignCenter;\n"
"  }\n"
"\n"
"  /* \346\224\257\344\273\230\345\256\235\346\214\211\351\222\256\344\277\235\346\214\201\345\216\237\346\240\267 */\n"
"  #AlipayButton {\n"
"      background-color: transparent !important;\n"
"      border: none !important;\n"
"      image: url(:/new/prefix1/images/alipay.png);\n"
"  }\n"
" "
                        " "));
        label = new QLabel(recordsInput);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 211, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(18);
        label->setFont(font);
        recordsInput->setCentralWidget(label);
        AlipayButton = new QPushButton(recordsInput);
        AlipayButton->setObjectName("AlipayButton");
        AlipayButton->setGeometry(QRect(340, 230, 51, 41));
        AlipayButton->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/images/alipay.png);"));
        recordsInput->setCentralWidget(AlipayButton);
        label_2 = new QLabel(recordsInput);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 90, 71, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(16);
        label_2->setFont(font1);
        recordsInput->setCentralWidget(label_2);
        dateEdit = new QDateEdit(recordsInput);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(200, 90, 110, 31));
        dateEdit->setDateTime(QDateTime(QDate(2025, 4, 29), QTime(16, 0, 0)));
        recordsInput->setCentralWidget(dateEdit);
        label_3 = new QLabel(recordsInput);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 130, 81, 31));
        label_3->setFont(font1);
        recordsInput->setCentralWidget(label_3);
        income = new QRadioButton(recordsInput);
        income->setObjectName("income");
        income->setGeometry(QRect(210, 140, 72, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setPointSize(14);
        income->setFont(font2);
        recordsInput->setCentralWidget(income);
        cost = new QRadioButton(recordsInput);
        cost->setObjectName("cost");
        cost->setGeometry(QRect(300, 140, 72, 16));
        cost->setFont(font2);
        recordsInput->setCentralWidget(cost);
        recordType = new QComboBox(recordsInput);
        recordType->addItem(QString());
        recordType->addItem(QString());
        recordType->setObjectName("recordType");
        recordType->setGeometry(QRect(190, 170, 81, 22));
        recordsInput->setCentralWidget(recordType);
        label_4 = new QLabel(recordsInput);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 170, 51, 31));
        label_4->setFont(font1);
        recordsInput->setCentralWidget(label_4);
        label_5 = new QLabel(recordsInput);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 210, 81, 31));
        label_5->setFont(font1);
        recordsInput->setCentralWidget(label_5);
        recordAmount = new QDoubleSpinBox(recordsInput);
        recordAmount->setObjectName("recordAmount");
        recordAmount->setGeometry(QRect(190, 220, 81, 22));
        recordAmount->setMaximum(9999999.990000000223517);
        recordsInput->setCentralWidget(recordAmount);
        label_6 = new QLabel(recordsInput);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 280, 141, 41));
        label_6->setFont(font2);
        recordsInput->setCentralWidget(label_6);
        recordConfirm = new QPushButton(recordsInput);
        recordConfirm->setObjectName("recordConfirm");
        recordConfirm->setGeometry(QRect(105, 270, 61, 21));
        recordConfirm->setFont(font2);
        recordsInput->setCentralWidget(recordConfirm);
        recordBack = new QPushButton(recordsInput);
        recordBack->setObjectName("recordBack");
        recordBack->setGeometry(QRect(200, 270, 61, 21));
        recordBack->setFont(font2);
        recordsInput->setCentralWidget(recordBack);

        retranslateUi(recordsInput);

        QMetaObject::connectSlotsByName(recordsInput);
    } // setupUi

    void retranslateUi(QMainWindow *recordsInput)
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
