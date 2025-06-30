/********************************************************************************
** Form generated from reading UI file 'analyze.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZE_H
#define UI_ANALYZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE

class Ui_Analyze
{
public:
    QPushButton *backBtn;
    QPushButton *exitBtn;
    QComboBox *ChartChooseBtn;
    QWidget *ChartContainer;
    QLabel *label;

    void setupUi(QMainWindow *Analyze)
    {
        if (Analyze->objectName().isEmpty())
            Analyze->setObjectName("Analyze");
        Analyze->resize(1133, 768);
        backBtn = new QPushButton(Analyze);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(1010, 710, 91, 41));
        QFont font;
        font.setPointSize(14);
        backBtn->setFont(font);
        exitBtn = new QPushButton(Analyze);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(1020, 30, 91, 31));
        exitBtn->setFont(font);
        ChartChooseBtn = new QComboBox(Analyze);
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->setObjectName("ChartChooseBtn");
        ChartChooseBtn->setGeometry(QRect(210, 30, 251, 31));
        ChartContainer = new QWidget(Analyze);
        ChartContainer->setObjectName("ChartContainer");
        ChartContainer->setGeometry(QRect(30, 80, 961, 611));
        label = new QLabel(Analyze);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 30, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Analyze);

        QMetaObject::connectSlotsByName(Analyze);
    } // setupUi

    void retranslateUi(QMainWindow *Analyze)
    {
        Analyze->setWindowTitle(QCoreApplication::translate("Analyze", "Form", nullptr));
        backBtn->setText(QCoreApplication::translate("Analyze", "\350\277\224\345\233\236\344\270\212\347\272\247", nullptr));
        exitBtn->setText(QCoreApplication::translate("Analyze", "\351\200\200\345\207\272\345\272\224\347\224\250", nullptr));
        ChartChooseBtn->setItemText(0, QCoreApplication::translate("Analyze", "\346\234\254\345\221\250\351\245\274\347\212\266\345\233\276\345\210\206\346\236\220->\345\220\204\351\241\271\345\215\240\346\257\224", nullptr));
        ChartChooseBtn->setItemText(1, QCoreApplication::translate("Analyze", "\346\234\254\345\221\250\346\240\221\347\212\266\345\233\276\345\210\206\346\236\220->\346\257\217\345\244\251\345\257\271\346\257\224", nullptr));
        ChartChooseBtn->setItemText(2, QCoreApplication::translate("Analyze", "\346\234\210\345\272\246\351\245\274\347\212\266\345\233\276\345\210\206\346\236\220->\345\220\204\351\241\271\345\215\240\346\257\224", nullptr));
        ChartChooseBtn->setItemText(3, QCoreApplication::translate("Analyze", "\346\234\210\345\272\246\346\240\221\347\212\266\345\233\276\345\210\206\346\236\220->\346\257\217\345\221\250\345\257\271\346\257\224", nullptr));

        label->setText(QCoreApplication::translate("Analyze", "\350\257\267\351\200\211\346\213\251\346\211\200\350\246\201\347\224\237\346\210\220\347\232\204\345\233\276\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Analyze: public Ui_Analyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_H
