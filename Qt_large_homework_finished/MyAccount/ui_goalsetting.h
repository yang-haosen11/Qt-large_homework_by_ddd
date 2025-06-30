/********************************************************************************
** Form generated from reading UI file 'goalsetting.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOALSETTING_H
#define UI_GOALSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoalSetting
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");

        const int scrollAreaWidth = 321;
        const int scrollAreaHeight = 200;
        const int padding = 10;           // 边距

        MainWindow->resize(
            scrollAreaWidth + 2 * padding,  // 窗口宽度 = 表格宽度 + 左右边距
            scrollAreaHeight + 100          // 窗口高度 = 表格高度 + 标题栏和底部空间
            );

        MainWindow->setStyleSheet(QString::fromUtf8(
            "QMainWindow {"
            "    background-position: center;"
            "    background-repeat: no-repeat;"
            "    background-size: cover;"
            "}"
            "QPlainTextEdit, QScrollArea {"
            "    background: rgba(255, 255, 255, 0.8);"
            "    border: 1px solid rgba(0, 0, 0, 0.2);"
            "}"
            ));

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet("background: transparent;");

        // 标题输入框（居中显示）
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(
            (MainWindow->width() - 81) / 2,  // 水平居中
            10,
            81,
            31
            ));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217")});
        font.setPointSize(18);
        plainTextEdit->setFont(font);

        // 表格区域（调整位置和大小）
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(
            padding,                            // 左边距
            plainTextEdit->y() + plainTextEdit->height() + 10,  // 标题下方
            scrollAreaWidth,
            scrollAreaHeight
            ));
        scrollArea->setWidgetResizable(true);

        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        scrollArea->setWidget(scrollAreaWidgetContents);

        MainWindow->setCentralWidget(centralwidget);

        // 菜单栏和状态栏（隐藏以节省空间）
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setVisible(false);  // 隐藏菜单栏
        MainWindow->setMenuBar(menubar);

        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setVisible(false); // 隐藏状态栏
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QMetaObject::connectSlotsByName(MainWindow);
    }

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "目标设置", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "\346\210\220\345\260\261\346\240\217", nullptr));
    }
};

namespace Ui {
class GoalSetting: public Ui_GoalSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOALSETTING_H
