/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        Login->setStyleSheet(QString::fromUtf8("\n"
"      QMainWindow {\n"
"        background-color: #FFF8E7;\n"
"        background-image: url(:/resources/background/light_bg.png);\n"
"        background-position: center;\n"
"        background-repeat: no-repeat;\n"
"        background-attachment: fixed;\n"
"      }\n"
"\n"
"      /* \344\277\235\346\214\201\346\202\250\345\216\237\346\234\211\347\232\204\346\216\247\344\273\266\346\240\267\345\274\217 */\n"
"      QLabel[objectName=\"titleLabel\"] {\n"
"        color: orange;\n"
"        font-weight: bold;\n"
"        font-size: 24px;\n"
"      }\n"
"\n"
"      QLabel[objectName=\"usernameLabel\"],\n"
"      QLabel[objectName=\"passwordLabel\"] {\n"
"        color: orange;\n"
"        font-weight: bold;\n"
"        font-size: 18px;\n"
"      }\n"
"\n"
"      QPushButton[objectName=\"loginButton\"],\n"
"      QPushButton[objectName=\"registerButton\"] {\n"
"        color: orange;\n"
"        font-weight: bold;\n"
"        font-size: 18px;\n"
"        background-color: qlineargradient(x1:0, y1:0, x2:0, y2"
                        ":1, stop:0 #F4A460, stop:1 #D2691E);\n"
"        border-radius: 5px;\n"
"        padding: 8px 15px;\n"
"        border: 1px solid #CD853F;\n"
"      }\n"
"\n"
"      QPushButton[objectName=\"loginButton\"]:hover,\n"
"      QPushButton[objectName=\"registerButton\"]:hover {\n"
"        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D2B48C, stop:1 #CD853F);\n"
"      }\n"
"\n"
"      QLineEdit {\n"
"        background-color: white;\n"
"        border: 1px solid #D2B48C;\n"
"        border-radius: 3px;\n"
"        padding: 5px;\n"
"        color: black;\n"
"      }\n"
"     "));
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formWidget = new QWidget(centralWidget);
        formWidget->setObjectName("formWidget");
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(formWidget);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(formWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(formWidget);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(formWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordLineEdit);


        verticalLayout->addWidget(formWidget);

        buttonWidget = new QWidget(centralWidget);
        buttonWidget->setObjectName("buttonWidget");
        horizontalLayout = new QHBoxLayout(buttonWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        loginButton = new QPushButton(buttonWidget);
        loginButton->setObjectName("loginButton");

        horizontalLayout->addWidget(loginButton);

        registerButton = new QPushButton(buttonWidget);
        registerButton->setObjectName("registerButton");

        horizontalLayout->addWidget(registerButton);


        verticalLayout->addWidget(buttonWidget);

        Login->setCentralWidget(centralWidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\350\264\246\346\234\254\347\263\273\347\273\237\347\231\273\345\275\225", nullptr));
        titleLabel->setText(QCoreApplication::translate("Login", "<h1>\350\264\246\346\234\254\347\263\273\347\273\237</h1>", nullptr));
        titleLabel->setStyleSheet(QCoreApplication::translate("Login", "color: orange; font-weight: bold; font-size: 24px;", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        usernameLabel->setStyleSheet(QCoreApplication::translate("Login", "color: orange; font-weight: bold; font-size: 18px;", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        passwordLabel->setStyleSheet(QCoreApplication::translate("Login", "color: orange; font-weight: bold; font-size: 18px;", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        loginButton->setStyleSheet(QCoreApplication::translate("Login", "color: orange; font-weight: bold; font-size: 18px;", nullptr));
        registerButton->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        registerButton->setStyleSheet(QCoreApplication::translate("Login", "color: orange; font-weight: bold; font-size: 18px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
