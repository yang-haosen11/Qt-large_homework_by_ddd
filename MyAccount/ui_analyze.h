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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Analyze
{
public:
    QPushButton *backBtn;
    QPushButton *exitBtn;
    QComboBox *ChartChooseBtn;
    QWidget *ChartContainer;
    QPushButton *AIptn;
    QWidget *AItextcontainer;

    void setupUi(QWidget *Analyze)
    {
        if (Analyze->objectName().isEmpty())
            Analyze->setObjectName("Analyze");
        Analyze->resize(1133, 768);
        backBtn = new QPushButton(Analyze);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(1050, 710, 61, 31));
        QFont font;
        font.setPointSize(14);
        backBtn->setFont(font);
        exitBtn = new QPushButton(Analyze);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(980, 20, 80, 21));
        exitBtn->setFont(font);
        ChartChooseBtn = new QComboBox(Analyze);
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->addItem(QString());
        ChartChooseBtn->setObjectName("ChartChooseBtn");
        ChartChooseBtn->setGeometry(QRect(70, 20, 141, 22));
        ChartContainer = new QWidget(Analyze);
        ChartContainer->setObjectName("ChartContainer");
        ChartContainer->setGeometry(QRect(60, 90, 611, 611));
        AIptn = new QPushButton(Analyze);
        AIptn->setObjectName("AIptn");
        AIptn->setGeometry(QRect(870, 120, 91, 31));
        AItextcontainer = new QWidget(Analyze);
        AItextcontainer->setObjectName("AItextcontainer");
        AItextcontainer->setGeometry(QRect(780, 190, 271, 171));

        retranslateUi(Analyze);

        QMetaObject::connectSlotsByName(Analyze);
    } // setupUi

    void retranslateUi(QWidget *Analyze)
    {
        Analyze->setWindowTitle(QCoreApplication::translate("Analyze", "Form", nullptr));
        backBtn->setText(QCoreApplication::translate("Analyze", "\350\277\224\345\233\236\344\270\212\347\272\247", nullptr));
        exitBtn->setText(QCoreApplication::translate("Analyze", "\351\200\200\345\207\272\345\272\224\347\224\250", nullptr));
        ChartChooseBtn->setItemText(0, QCoreApplication::translate("Analyze", "\346\234\254\345\221\250\351\245\274\347\212\266\345\233\276\345\210\206\346\236\220->\345\220\204\351\241\271\345\215\240\346\257\224", nullptr));
        ChartChooseBtn->setItemText(1, QCoreApplication::translate("Analyze", "\346\234\254\345\221\250\346\240\221\347\212\266\345\233\276\345\210\206\346\236\220->\346\257\217\345\244\251\345\257\271\346\257\224", nullptr));
        ChartChooseBtn->setItemText(2, QCoreApplication::translate("Analyze", "\346\234\210\345\272\246\351\245\274\347\212\266\345\233\276\345\210\206\346\236\220->\345\220\204\351\241\271\345\215\240\346\257\224", nullptr));
        ChartChooseBtn->setItemText(3, QCoreApplication::translate("Analyze", "\346\234\210\345\272\246\346\240\221\347\212\266\345\233\276\345\210\206\346\236\220->\346\257\217\345\221\250\345\257\271\346\257\224", nullptr));

        AIptn->setText(QCoreApplication::translate("Analyze", "AI\346\231\272\346\205\247\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
class Analyze: public Ui_Analyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_H
