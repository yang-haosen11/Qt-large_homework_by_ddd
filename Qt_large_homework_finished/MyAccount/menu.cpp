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
#include"recordsInput.h"
#include"goalsetting.h"
#include"ui_goalsetting.h"
Menu::Menu(QWidget *parent, QString username,GoalSetting *achievementSystem) :
    QMainWindow(parent),
    ui(new Ui::Menu),
    currentUsername(username),
    analyzeWindow(nullptr),
    recordsInputWindow(nullptr),
    goalsettingWindow(nullptr),
    achievementSystem(achievementSystem)
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
    if (!achievementSystem) {
        this->achievementSystem = new GoalSetting(nullptr, username);
    }

    // 连接按钮信号和槽
    connect(ui->incomeExpenseRecordButton, &QPushButton::clicked, this, &Menu::onIncomeExpenseRecordClicked);
    connect(ui->incomeExpenseAnalysisButton, &QPushButton::clicked, this, &Menu::onIncomeExpenseAnalysisClicked);
    connect(ui->achievementSystemButton, &QPushButton::clicked, this, &Menu::onAchievementSystemClicked);
    connect(ui->achievementSystemButton, &QPushButton::clicked, this, &Menu::onAchievementSystemClicked);
    // 连接菜单项信号和槽
    connect(ui->actionLogout, &QAction::triggered, this, &Menu::onLogoutTriggered);
    connect(ui->actionLightTheme, &QAction::triggered, this, &Menu::onLightThemeTriggered);
    connect(ui->actionDarkTheme, &QAction::triggered, this, &Menu::onDarkThemeTriggered);

    onLightThemeTriggered();
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
    if (!recordsInputWindow) {
        recordsInputWindow = new Record(this,this,currentUsername);
        connect(recordsInputWindow, &Record::incomeRecorded,
                this->achievementSystem, &GoalSetting::checkFirstIncomeAchievement);
        connect(recordsInputWindow, &Record::expenseRecorded,
                this->achievementSystem, &GoalSetting::checkFirstExpenseAchievement);
        connect(recordsInputWindow, &QObject::destroyed, this, &Menu::onrecordsInputWindowClosed);
    }
    this->hide(); // 隐藏 Menu 界面
    recordsInputWindow->show(); // 显示 Analyze 界面
}

void Menu::onIncomeExpenseAnalysisClicked()
{
    if (!analyzeWindow) {
        analyzeWindow = new Analyze(this,this,currentUsername); // 创建 Analyze 类的对象指针
        connect(analyzeWindow, &QObject::destroyed, this, &Menu::onAnalyzeWindowClosed);
    }
    this->hide(); // 隐藏 Menu 界面
    analyzeWindow->initDatabase();
    analyzeWindow->FileToDB();
    analyzeWindow->GetLastMonthData();
    analyzeWindow->GetLastWeekData();
    analyzeWindow->show(); // 显示 Analyze 界面
}

void Menu::onAchievementSystemClicked()
{
    if (achievementSystem) {
        connect(achievementSystem, &GoalSetting::backToMenuRequested,
                this, &Menu::handleBackFromAchievement);

        this->hide();
        achievementSystem->show();
    }
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
void Menu::onrecordsInputWindowClosed()
{
    this->show(); // 显示 Menu 界面
    recordsInputWindow = nullptr; // 重置指针
}
void Menu::ongoalsettingWindowClosed()
{
    this->show(); // 显示 Menu 界面
    goalsettingWindow = nullptr; // 重置指针
}
void Menu::handleBackFromAchievement() {
    if (achievementSystem) {
        achievementSystem->hide();  // 隐藏成就界面
    }
    this->show();                   // 显示主菜单
    // 可选：断开连接避免重复触发
    //disconnect(achievementBackConnection);
}

void Menu::setBackgroundImage(const QString &imagePath)
{
    QString styleSheet = QString(
                             "QMainWindow {"
                             "    background-color: %1;"
                             "    background-image: url(%2);"
                             "    background-position: center;"
                             "    background-repeat: no-repeat;"
                             "    background-attachment: fixed;"
                             "}"
                             ).arg(imagePath.isEmpty() ? "#FFF8E7" : "transparent").arg(imagePath);

    this->setStyleSheet(styleSheet);
}

void Menu::onLightThemeTriggered()
{
    // 设置亮色主题
    setBackgroundImage(":/resources/background/light_bg.png");

    // 其他样式设置
    QString styleSheet =
        "QPushButton { background-color: #F4A460; color: #000000; border-radius: 8px; }"
        "QPushButton:hover { background-color: #D2B48C; }"
        "QPushButton:pressed { background-color: #CD853F; }"
        "QLabel { color: #000000; }"
        "QMenuBar { background-color: transparent; color: #000000; }"
        "QMenuBar::item:selected { background-color: #F4A460; }"
        "QMenu { background-color: #FFF8E7; color: #000000; }"
        "QMenu::item:selected { background-color: #F4A460; }";

    this->setStyleSheet(this->styleSheet() + styleSheet);
    emit themeChanged("light");
}

void Menu::onDarkThemeTriggered()
{
    // 设置暗色主题
    setBackgroundImage(":/resources/background/dark.png");

    // 其他样式设置
    QString styleSheet =
        "QPushButton { background-color: #555555; color: #FFFFFF; border-radius: 8px; }"
        "QPushButton:hover { background-color: #777777; }"
        "QPushButton:pressed { background-color: #999999; }"
        "QLabel { color: #FFFFFF; }"
        "QMenuBar { background-color: transparent; color: #FFFFFF; }"
        "QMenuBar::item:selected { background-color: #555555; }"
        "QMenu { background-color: #333333; color: #FFFFFF; }"
        "QMenu::item:selected { background-color: #555555; }";

    this->setStyleSheet(this->styleSheet() + styleSheet);
    emit themeChanged("dark");
}
