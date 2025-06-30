#include "goalsetting.h"
#include "ui_goalsetting.h"
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QStyle>
#include <QRegularExpression>

// ================= AchievementDetailDialog 实现 =================
AchievementDetailDialog::AchievementDetailDialog(const Achievement &achievement, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(achievement.title);
    setFixedSize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    // 成就图标
    QLabel *iconLabel = new QLabel();
    QString iconPath = achievement.status == Unlocked ?
                           ":/resources/icons/unlocked.png" : ":/resources/icons/locked.png";
    iconLabel->setPixmap(QPixmap(iconPath).scaled(80, 80));
    iconLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(iconLabel);

    // 成就描述
    QLabel *descLabel = new QLabel(achievement.description);
    descLabel->setAlignment(Qt::AlignCenter);
    descLabel->setWordWrap(true);
    layout->addWidget(descLabel);

    // 进度信息
    QString progressText;
    if (achievement.targetProgress > 1) {
        progressText = QString("进度: %1/%2")
                           .arg(achievement.currentProgress)
                           .arg(achievement.targetProgress);
    } else {
        progressText = achievement.status == Unlocked ? "已达成" : "未达成";
    }

    QLabel *progressLabel = new QLabel(progressText);
    progressLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(progressLabel);

    // 达成时间
    QString timeText = "达成时间: ";
    if (achievement.achievedTime == "0000-00-00") {
        timeText += "未达成";
    } else {
        timeText += achievement.achievedTime;
    }

    QLabel *timeLabel = new QLabel(timeText);
    timeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(timeLabel);

    // 关闭按钮
    QPushButton *closeButton = new QPushButton("关闭");
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeButton);
}

// ================= GoalSetting 实现 =================
GoalSetting::GoalSetting(QWidget *parent, const QString &username)
    : QMainWindow(parent),
    ui(new Ui::GoalSetting),
    username(username)
{
    this->incomeCount = 0;
    this->costCount = 0;
    ui->setupUi(this);

    backButton = findChild<QPushButton*>("backButton"); // 通过ui设计器中设置的objectName查找
    if (!backButton) {
        backButton = new QPushButton("返回主菜单", this);
        backButton->setObjectName("backButton");
        backButton->setGeometry(20, 20, 100, 30); // 设置位置和大小
    }

    // 连接按钮点击信号到自定义槽函数
    connect(backButton, &QPushButton::clicked, this, &GoalSetting::onBackButtonClicked);

    // 初始化成就系统
    initializeAchievementMetadata();
    loadLoginStats();
    loadUserAchievements();

    // 确保滚动区域设置正确
    if (ui->scrollArea) {
        // 设置滚动区域可调整大小
        ui->scrollArea->setWidgetResizable(true);

        // 确保内容部件有足够的垂直空间
        if (ui->scrollArea->widget()) {
            ui->scrollArea->widget()->setMinimumHeight(1000);
        }
    }

    // 刷新UI
    refreshAchievementDisplay();

    // 设置窗口关闭时自动保存
    setAttribute(Qt::WA_DeleteOnClose);
}

GoalSetting::~GoalSetting()
{
    saveLoginStats();
    saveUserAchievements();
    delete ui;
}

// 添加路径处理函数
static QString sanitizeFilename(const QString &username) {
    QString safeName = username;
    // 替换特殊字符
    safeName.replace(':', '_');
    safeName.replace('/', '_');
    safeName.replace('\\', '_');
    safeName.replace('*', '_');
    safeName.replace('?', '_');
    safeName.replace('"', '_');
    safeName.replace('<', '_');
    safeName.replace('>', '_');
    safeName.replace('|', '_');
    return safeName + "_achievements.txt";
}

static QString getSafeFilename(const QString &username, const QString &suffix) {
    QString safeName = username;
    // 替换所有可能引起问题的特殊字符
    safeName.replace(QRegularExpression("[^a-zA-Z0-9_]"), "_");
    return safeName + suffix;
}

void GoalSetting::closeEvent(QCloseEvent *event)
{
    saveLoginStats();
    saveUserAchievements();
    event->accept();
}

void GoalSetting::initializeAchievementMetadata()
{
    // 清空现有成就
    achievements.clear();

    // 添加所有5个成就
    achievements.append({
        "lucky_clover",
        "幸运三叶草",
        "新人第一天登录",
        0,
        1,
        Locked,
        "0000-00-00",
        ":/resources/icons/locked.png",
        ":/resources/icons/xingyunsanyecao.png"
    });

    achievements.append({
        "splash_of_finance",
        "理财小水花",
        "连续登录三天",
        0,
        3,
        Locked,
        "0000-00-00",
        ":/resources/icons/locked.png",
        ":/resources/icons/licaixiaoshuihua.png"
    });

    achievements.append({
        "perseverance",
        "持之以恒",
        "累计登录一周",
        0,
        7,
        Locked,
        "0000-00-00",
        ":/resources/icons/locked.png",
        ":/resources/icons/chizhiyiheng.png"
    });

    achievements.append({
        "first_gold",
        "第一桶金",
        "记录第一笔收入",
        0,
        1,
        Locked,
        "0000-00-00",
        ":/resources/icons/locked.png",
        ":/resources/icons/diyitongjin.png"
    });

    achievements.append({
        "well_organized",
        "井井有条",
        "记录第一笔支出",
        0,
        1,
        Locked,
        "0000-00-00",
        ":/resources/icons/locked.png",
        ":/resources/icons/jingjingyoutiao.png"
    });
}

void GoalSetting::loadUserAchievements()
{
    if (username.isEmpty()) return;

    QString filename = sanitizeFilename(username);
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "成就文件不存在，将创建新文件";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if (parts.size() < 3) continue;

        QString id = parts[0];
        int currentProgress = parts[1].toInt();
        int isUnlocked = parts[2].toInt();
        QString achievedTime = (parts.size() > 3) ? parts[3] : "0000-00-00";

        // 更新成就数据
        Achievement* achievement = findAchievementById(id);
        if (achievement) {
            achievement->currentProgress = currentProgress;
            achievement->status = (isUnlocked == 1) ? Unlocked : Locked;
            achievement->achievedTime = achievedTime;
        }
    }
    file.close();
}

void GoalSetting::saveUserAchievements()
{
    if (username.isEmpty()) return;

    QString filename = sanitizeFilename(username);
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法保存成就文件";
        return;
    }

    QTextStream out(&file);
    for (const Achievement &achievement : achievements) {
        out << achievement.id << ","
            << achievement.currentProgress << ","
            << ((achievement.status == Unlocked) ? 1 : 0) << ","
            << achievement.achievedTime << "\n";
    }
    file.close();
}

void GoalSetting::loadLoginStats()
{
    if (username.isEmpty()) return;

    QString filename = getSafeFilename(username, "_login_stats.txt");
    QFile file(filename);

    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString statsData = in.readLine();
        QStringList parts = statsData.split(',');

        if (parts.size() >= 3) {
            m_totalLoginDays = parts[0].toInt();
            m_consecutiveLoginDays = parts[1].toInt();
            m_lastLoginDate = QDate::fromString(parts[2], "yyyy-MM-dd");
            qDebug() << "加载登录统计:"
                     << m_totalLoginDays << "天, 连续"
                     << m_consecutiveLoginDays << "天, 最后登录:"
                     << m_lastLoginDate.toString("yyyy-MM-dd");
        }
        file.close();
    } else {
        // 初始化默认值
        m_totalLoginDays = 0;
        m_consecutiveLoginDays = 0;
        m_lastLoginDate = QDate();
    }
}

void GoalSetting::saveLoginStats()
{
    if (username.isEmpty()) return;

    QString filename = getSafeFilename(username, "_login_stats.txt");
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << m_totalLoginDays << ","
            << m_consecutiveLoginDays << ","
            << m_lastLoginDate.toString("yyyy-MM-dd");
        file.close();
        qDebug() << "保存登录统计:"
                 << m_totalLoginDays << "天, 连续"
                 << m_consecutiveLoginDays << "天, 最后登录:"
                 << m_lastLoginDate.toString("yyyy-MM-dd");
    }
}

void GoalSetting::refreshAchievementDisplay()
{
    // 清空按钮映射
    buttonAchievementMap.clear();

    // 获取滚动区域
    if (!ui->scrollArea) {
        qWarning() << "Scroll area not found!";
        return;
    }

    // 获取滚动区域的内容部件
    QWidget *scrollContent = ui->scrollArea->widget();
    if (!scrollContent) {
        qWarning() << "Scroll area content widget is null!";
        return;
    }

    // 获取或创建布局
    QLayout *baseLayout = scrollContent->layout();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(baseLayout);

    if (!layout) {
        // 如果不是 QVBoxLayout，则创建一个新的
        if (baseLayout) {
            delete baseLayout; // 删除现有布局
        }
        layout = new QVBoxLayout(scrollContent);
        layout->setAlignment(Qt::AlignTop);
        layout->setSpacing(15);
        scrollContent->setLayout(layout);
    }

    // 清空现有显示
    while (layout->count() > 0) {
        QLayoutItem *item = layout->takeAt(0);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    // 添加成就项
    for (const Achievement &achievement : achievements) {
        QWidget *achievementWidget = new QWidget();
        achievementWidget->setObjectName("achievementItem");
        QGridLayout *achievementLayout = new QGridLayout(achievementWidget);

        // 成就按钮（显示锁/开锁图标）
        QPushButton *iconButton = new QPushButton();
        iconButton->setObjectName("achievementButton");
        iconButton->setFixedSize(40, 40);
        iconButton->setFlat(true); // 扁平化按钮

        // 设置图标
        QString iconPath = achievement.status == Unlocked
                               ? achievement.unlockedIconPath
                               : achievement.lockedIconPath;
        iconButton->setIcon(QIcon(iconPath));
        iconButton->setIconSize(QSize(36, 36));

        // 连接点击信号
        connect(iconButton, &QPushButton::clicked, this, &GoalSetting::onAchievementClicked);

        // 存储按钮到成就的映射
        buttonAchievementMap.insert(iconButton, achievement.id);

        // 成就标题和描述
        QLabel *titleLabel = new QLabel("<b>" + achievement.title + "</b>");
        QLabel *descLabel = new QLabel(achievement.description);

        // 进度条（如果目标进度大于1）
        QProgressBar *progressBar = nullptr;
        if (achievement.targetProgress > 1) {
            progressBar = new QProgressBar();
            progressBar->setRange(0, achievement.targetProgress);
            progressBar->setValue(achievement.currentProgress);
            progressBar->setFormat(QString("%v/%1").arg(achievement.targetProgress));
        }

        // 成就时间
        QLabel *timeLabel = new QLabel("达成时间: " +
                                       (achievement.achievedTime == "0000-00-00" ?
                                            "未达成" : achievement.achievedTime));

        // 添加到布局
        achievementLayout->addWidget(iconButton, 0, 0, 2, 1);
        achievementLayout->addWidget(titleLabel, 0, 1);
        achievementLayout->addWidget(descLabel, 1, 1);

        if (progressBar) {
            achievementLayout->addWidget(progressBar, 2, 0, 1, 2);
        }

        achievementLayout->addWidget(timeLabel, 3, 0, 1, 2);

        // 设置成就项样式
        achievementWidget->setStyleSheet(
            "#achievementItem {"
            "   background-color: rgba(255, 255, 255, 200);"
            "   border-radius: 10px;"
            "   padding: 10px;"
            "   border: 1px solid #e0e0e0;"
            "}"
            ""
            "#achievementButton {"
            "   border: none;"
            "   background: transparent;"
            "}"
            );

        // 添加到主滚动区域布局
        layout->addWidget(achievementWidget);
    }

    // 添加伸缩空间，使内容顶部对齐
    layout->addStretch();
}

Achievement* GoalSetting::findAchievementById(const QString& id)
{
    for (int i = 0; i < achievements.size(); ++i) {
        if (achievements[i].id == id) {
            return &achievements[i];
        }
    }
    return nullptr;
}

void GoalSetting::updateAchievementProgress(const QString& achievementId, int increment)
{
    Achievement *achievement = findAchievementById(achievementId);
    if (!achievement) return;

    // 仅当成就未解锁时才更新进度
    if (achievement->status != Unlocked) {
        // 更新进度
        achievement->currentProgress += increment;

        // 检查是否达成成就
        if (achievement->currentProgress >= achievement->targetProgress) {
            achievement->status = Unlocked;
            achievement->achievedTime = QDate::currentDate().toString("yyyy-MM-dd");

            // 触发成就达成通知
            qDebug() << "成就达成:" << achievement->title;

            // 显示成就解锁通知
            QMessageBox::information(this, "成就解锁",
                                     QString("恭喜！您已解锁成就：\n%1\n%2")
                                         .arg(achievement->title)
                                         .arg(achievement->description));

            // 刷新UI
            refreshAchievementDisplay();
        }

        // 保存成就状态
        saveUserAchievements();
    }
}

// 登录事件处理
LoginStatus GoalSetting::handleUserLogin()
{
    QDate currentDate = QDate::currentDate();
    qDebug() << "处理用户登录, 当前日期:" << currentDate.toString("yyyy-MM-dd")
             << "上次登录日期:" << (m_lastLoginDate.isValid() ?
                                        m_lastLoginDate.toString("yyyy-MM-dd") : "无效");

    // 检查今天是否已经登录过
    if (m_lastLoginDate.isValid() && m_lastLoginDate == currentDate) {
        qDebug() << "用户今天已登录过";
        return AlreadyLogged;
    }

    // 更新连续登录天数
    if (m_lastLoginDate.isValid()) {
        int daysSinceLastLogin = m_lastLoginDate.daysTo(currentDate);
        qDebug() << "距上次登录天数:" << daysSinceLastLogin;

        if (daysSinceLastLogin == 1) {
            m_consecutiveLoginDays++;
            qDebug() << "连续登录天数增加为:" << m_consecutiveLoginDays;
        } else if (daysSinceLastLogin > 1) {
            qDebug() << "登录间隔超过1天, 重置连续登录天数";
            m_consecutiveLoginDays = 1;
        }
    } else {
        // 首次登录
        qDebug() << "用户首次登录或上次登录日期无效";
        m_consecutiveLoginDays = 1;
    }

    // 更新总登录天数
    m_totalLoginDays++;
    qDebug() << "总登录天数增加为:" << m_totalLoginDays;

    // 更新最后登录日期
    m_lastLoginDate = currentDate;
    qDebug() << "设置最后登录日期:" << m_lastLoginDate.toString("yyyy-MM-dd");

    // 保存登录统计
    saveLoginStats();

    // 检查登录相关成就
    checkLoginAchievements();

    return (m_totalLoginDays == 1) ? FirstLogin : FirstLogin; // 总是返回FirstLogin以触发提示
}

// 登录相关成就检测
void GoalSetting::checkLoginAchievements()
{
    qDebug() << "检查登录相关成就...";
    qDebug() << "当前统计 - 总登录:" << m_totalLoginDays
             << "连续登录:" << m_consecutiveLoginDays;

    // 1. 幸运三叶草（新人第一天登录）
    if (m_totalLoginDays == 1) {
        qDebug() << "触发'幸运三叶草'成就";
        updateAchievementProgress("lucky_clover");
    } else {
        qDebug() << "'幸运三叶草'成就未触发(总登录天数:" << m_totalLoginDays << ">1)";
    }

    // 2. 理财小水花（连续登录三天）
    if (m_consecutiveLoginDays >= 3) {
        Achievement* splash = findAchievementById("splash_of_finance");
        if (splash && splash->status != Unlocked) {
            qDebug() << "更新'理财小水花'进度:" << m_consecutiveLoginDays;
            splash->currentProgress = m_consecutiveLoginDays;
            // 直接调用update而不仅仅是设置进度
            updateAchievementProgress("splash_of_finance", 0);
        }
    }

    // 3. 持之以恒（累计登录一周）
    if (m_totalLoginDays >= 7) {
        Achievement* perseverance = findAchievementById("perseverance");
        if (perseverance && perseverance->status != Unlocked) {
            qDebug() << "更新'持之以恒'进度:" << m_totalLoginDays;
            perseverance->currentProgress = m_totalLoginDays;
            // 直接调用update而不仅仅是设置进度
            updateAchievementProgress("perseverance", 0);
        }
    }


}

// 收入记录成就检测
void GoalSetting::checkFirstIncomeAchievement()
{
    // 4. 第一桶金（记录第一笔收入）
    incomeCount++;
    // 如果这是第一笔收入，则解锁"第一桶金"成就
    if (incomeCount == 1) {
        Achievement* firstGold = findAchievementById("first_gold");
        if (firstGold && firstGold->status == Locked) {
            qDebug() << "触发'第一桶金'成就";
            firstGold->currentProgress = 1;
            updateAchievementProgress("first_gold", 0);
        }
    }
}

// 支出记录成就检测
void GoalSetting::checkFirstExpenseAchievement()
{
    // 5. 井井有条（记录第一笔支出）
    costCount++;
    // 如果这是第一笔支出，则解锁"井井有条"成就
    if (costCount == 1) {
        Achievement* wellOrganized = findAchievementById("well_organized");
        if (wellOrganized && wellOrganized->status == Locked) {
            qDebug() << "触发'井井有条'成就";
            wellOrganized->currentProgress = 1;
            updateAchievementProgress("well_organized", 0);
        }
    }
}

// 成就按钮点击处理
void GoalSetting::onAchievementClicked()
{
    // 获取发送信号的按钮
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // 查找对应的成就ID
    if (buttonAchievementMap.contains(button)) {
        QString achievementId = buttonAchievementMap[button];
        Achievement *achievement = findAchievementById(achievementId);
        if (achievement) {
            // 显示成就详情对话框
            AchievementDetailDialog dialog(*achievement, this);
            dialog.exec();
        }
    }
}

void GoalSetting::onBackButtonClicked() {
    emit backToMenuRequested();  // 发射返回信号
    this->hide();               // 可选：隐藏当前窗口
}
