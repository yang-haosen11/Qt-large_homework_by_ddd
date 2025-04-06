#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include"analyze.h"
#include"ui_analyze.h"
Menu::Menu(QWidget *parent, QString username) :
    QMainWindow(parent),
    ui(new Ui::Menu),
    currentUsername(username),
    analyzeWindow(nullptr)
{
    ui->setupUi(this);

    // 设置欢迎标签
    ui->welcomeLabel->setText("欢迎回来，" + currentUsername);

    setupButtonAnimations();

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(15);
    shadow->setColor(QColor(0, 0, 0, 100));
    shadow->setOffset(0, 5);
    ui->centralWidget->setGraphicsEffect(shadow);

    // 连接按钮信号和槽
    connect(ui->incomeExpenseRecordButton, &QPushButton::clicked, this, &Menu::onIncomeExpenseRecordClicked);
    connect(ui->incomeExpenseAnalysisButton, &QPushButton::clicked, this, &Menu::onIncomeExpenseAnalysisClicked);
    connect(ui->achievementSystemButton, &QPushButton::clicked, this, &Menu::onAchievementSystemClicked);

    // 连接菜单项信号和槽
    connect(ui->actionLogout, &QAction::triggered, this, &Menu::onLogoutTriggered);
    connect(ui->actionLightTheme, &QAction::triggered, this, &Menu::onLightThemeTriggered);
    connect(ui->actionDarkTheme, &QAction::triggered, this, &Menu::onDarkThemeTriggered);
}

Menu::~Menu()
{
    delete ui;
    if (analyzeWindow) {
        delete analyzeWindow;
    }
}

void Menu::setupButtonAnimations()
{
    // 为按钮添加悬停动画效果
    QList<QPushButton*> allButtons = findChildren<QPushButton*>();
    foreach (QPushButton* button, allButtons) {
        button->setAttribute(Qt::WA_Hover, true);

        // 创建按钮悬停效果
        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(button);
        effect->setBlurRadius(10);
        effect->setColor(QColor(0, 0, 0, 80));
        effect->setOffset(0, 0);
        button->setGraphicsEffect(effect);

        // 存储原始大小
        button->setProperty("originalSize", button->size());
    }
}

void Menu::onIncomeExpenseRecordClicked()
{
QMessageBox::information(this, "功能", "成就系统功能即将推出");

}

void Menu::onIncomeExpenseAnalysisClicked()
{
    if (!analyzeWindow) {
        analyzeWindow = new Analyze(this); // 创建 Analyze 类的对象指针
        connect(analyzeWindow, &QObject::destroyed, this, &Menu::onAnalyzeWindowClosed);
    }
    this->hide(); // 隐藏 Menu 界面
    analyzeWindow->show(); // 显示 Analyze 界面
}

void Menu::onAchievementSystemClicked()
{
    QMessageBox::information(this, "功能", "成就系统功能即将推出");
}

void Menu::onLogoutTriggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "退出登录", "确定要退出登录吗？",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit logoutRequested();
    }
}

void Menu::onAnalyzeWindowClosed()
{
    this->show(); // 显示 Menu 界面
    analyzeWindow = nullptr; // 重置指针
}

void Menu::onLightThemeTriggered()
{
    // 设置亮色主题
    this->setStyleSheet("QMainWindow { background-color: #FFF8E7; }"
                        "QPushButton { background-color: #F4A460; color: #000000; border-radius: 8px; }"
                        "QPushButton:hover { background-color: #D2B48C; }"
                        "QPushButton:pressed { background-color: #CD853F; }"
                        "QLabel { color: #000000; }"
                        "QMenuBar { background-color: #FFF8E7; color: #000000; }"
                        "QMenuBar::item:selected { background-color: #F4A460; }"
                        "QMenu { background-color: #FFF8E7; color: #000000; }"
                        "QMenu::item:selected { background-color: #F4A460; }");
    emit themeChanged("light");
}

void Menu::onDarkThemeTriggered()
{
    // 设置暗色主题
    this->setStyleSheet("QMainWindow { background-color: #333333; }"
                        "QPushButton { background-color: #555555; color: #FFFFFF; border-radius: 8px; }"
                        "QPushButton:hover { background-color: #777777; }"
                        "QPushButton:pressed { background-color: #999999; }"
                        "QLabel { color: #FFFFFF; }"
                        "QMenuBar { background-color: #333333; color: #FFFFFF; }"
                        "QMenuBar::item:selected { background-color: #555555; }"
                        "QMenu { background-color: #333333; color: #FFFFFF; }"
                        "QMenu::item:selected { background-color: #555555; }");
    emit themeChanged("dark");
}
