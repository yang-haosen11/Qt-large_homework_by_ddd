/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QAction *actionLightTheme;
    QAction *actionDarkTheme;
    QAction *actionSeparator;
    QAction *actionLogout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *incomeExpenseRecordButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *incomeExpenseAnalysisButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *achievementSystemButton;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuTheme;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(600, 400);
        Menu->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"    background-color: #FFF8E7;\n"
"            background-position: center;\n"
"            background-repeat: no-repeat;\n"
"            background-attachment: fixed;\n"
"    }\n"
"\n"
"QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                     stop:0 #F4A460, stop:1 #D2691E);\n"
"    color: #000000;\n"
"    border-radius: 10px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    min-height: 60px;\n"
"    padding-left: 20px; /* \344\270\272\345\233\276\346\240\207\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"    text-align: left; /* \346\226\207\345\255\227\345\267\246\345\257\271\351\275\220 */\n"
"    border: 1px solid #CD853F;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                     stop:0 #D2B48C, stop:1 #CD853F);\n"
"    border: 1px solid #8B4513;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlinea"
                        "rgradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                     stop:0 #CD853F, stop:1 #8B4513);\n"
"}\n"
"\n"
"    QLabel {\n"
"        color: #000000;\n"
"        font-family: \"Microsoft YaHei\", \"SimHei\", \"WenQuanYi Micro Hei\";\n"
"    }\n"
"\n"
"    #welcomeLabel {\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"    }\n"
"\n"
"    QMenuBar {\n"
"        background-color: #FFF8E7;\n"
"        color: #000000;\n"
"    }\n"
"\n"
"    QMenuBar::item:selected {\n"
"        background-color: #F4A460;\n"
"    }\n"
"\n"
"    QMenu {\n"
"        background-color: #FFF8E7;\n"
"        color: #000000;\n"
"    }\n"
"\n"
"    QMenu::item:selected {\n"
"        background-color: #F4A460;\n"
"    }\n"
"\n"
"    /* \350\207\252\345\256\232\344\271\211\346\266\210\346\201\257\346\241\206\346\240\267\345\274\217 */\n"
"    QMessageBox {\n"
"        background-color: #FFF8E7;\n"
"    }\n"
"\n"
"    QMessageBox QLabel {\n"
"        color: #000000;\n"
"        font-size: 16px;\n"
"    }\n"
"\n"
""
                        "    QMessageBox QPushButton {\n"
"        background-color: #F4A460;\n"
"        color: #000000;\n"
"        border-radius: 6px;\n"
"        padding: 8px 15px;\n"
"    }\n"
"   "));
        actionLightTheme = new QAction(Menu);
        actionLightTheme->setObjectName("actionLightTheme");
        actionDarkTheme = new QAction(Menu);
        actionDarkTheme->setObjectName("actionDarkTheme");
        actionSeparator = new QAction(Menu);
        actionSeparator->setObjectName("actionSeparator");
        actionSeparator->setSeparator(true);
        actionLogout = new QAction(Menu);
        actionLogout->setObjectName("actionLogout");
        centralWidget = new QWidget(Menu);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        welcomeLabel = new QLabel(centralWidget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(welcomeLabel);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        incomeExpenseRecordButton = new QPushButton(centralWidget);
        incomeExpenseRecordButton->setObjectName("incomeExpenseRecordButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/record.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        incomeExpenseRecordButton->setIcon(icon);
        incomeExpenseRecordButton->setIconSize(QSize(32, 32));
        incomeExpenseRecordButton->setMaximumWidth(500);

        verticalLayout->addWidget(incomeExpenseRecordButton, 0, Qt::AlignLeft);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        incomeExpenseAnalysisButton = new QPushButton(centralWidget);
        incomeExpenseAnalysisButton->setObjectName("incomeExpenseAnalysisButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/analysis.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        incomeExpenseAnalysisButton->setIcon(icon1);
        incomeExpenseAnalysisButton->setIconSize(QSize(32, 32));
        incomeExpenseAnalysisButton->setMaximumWidth(500);

        verticalLayout->addWidget(incomeExpenseAnalysisButton, 0, Qt::AlignLeft);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        achievementSystemButton = new QPushButton(centralWidget);
        achievementSystemButton->setObjectName("achievementSystemButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/achievement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        achievementSystemButton->setIcon(icon2);
        achievementSystemButton->setIconSize(QSize(32, 32));
        achievementSystemButton->setMaximumWidth(500);

        verticalLayout->addWidget(achievementSystemButton, 0, Qt::AlignLeft);

        Menu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Menu);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName("menuSettings");
        menuTheme = new QMenu(menuSettings);
        menuTheme->setObjectName("menuTheme");
        Menu->setMenuBar(menuBar);

        menuBar->addAction(menuSettings->menuAction());
        menuSettings->addAction(menuTheme->menuAction());
        menuSettings->addAction(actionSeparator);
        menuSettings->addAction(actionLogout);
        menuTheme->addAction(actionLightTheme);
        menuTheme->addAction(actionDarkTheme);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "\350\264\246\346\234\254\347\263\273\347\273\237 - \344\270\273\350\217\234\345\215\225", nullptr));
        actionLightTheme->setText(QCoreApplication::translate("Menu", "\344\272\256\350\211\262\344\270\273\351\242\230", nullptr));
        actionDarkTheme->setText(QCoreApplication::translate("Menu", "\346\232\227\350\211\262\344\270\273\351\242\230", nullptr));
        actionLogout->setText(QCoreApplication::translate("Menu", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("Menu", "\346\254\242\350\277\216\345\233\236\346\235\245\357\274\214\347\224\250\346\210\267", nullptr));
        incomeExpenseRecordButton->setText(QCoreApplication::translate("Menu", "\346\224\266\346\224\257\350\256\260\345\275\225", nullptr));
        incomeExpenseAnalysisButton->setText(QCoreApplication::translate("Menu", "\346\224\266\346\224\257\345\210\206\346\236\220", nullptr));
        achievementSystemButton->setText(QCoreApplication::translate("Menu", "\346\210\220\345\260\261\347\263\273\347\273\237", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("Menu", "\350\256\276\347\275\256", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("Menu", "\344\270\273\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
