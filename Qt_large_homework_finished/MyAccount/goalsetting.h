#ifndef GOALSETTING_H
#define GOALSETTING_H


#include <QEvent>
#include <QApplication>
#include <QMainWindow>
#include <QScrollArea>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QMessageBox>
#include <QDebug>
#include <QProgressBar>
#include <QVector>
#include <QMap>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class
    GoalSetting;
}
QT_END_NAMESPACE

enum LoginStatus {
    FirstLogin,    // 当天首次登录
    AlreadyLogged  // 当天已登录
};

enum AchievementStatus {
    Locked,     // 未达成
    Unlocked,   // 已达成
};

struct Achievement {
    QString id;
    QString title;
    QString description;
    int currentProgress;
    int targetProgress;
    AchievementStatus status;
    QString achievedTime;
    // 新增：图标路径
    QString lockedIconPath;    // 锁定状态图标 (如":/icons/locked.png")
    QString unlockedIconPath;  // 解锁后显示的成就图标 (如":/icons/xingyunsanyecao.png")
};

class AchievementDetailDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AchievementDetailDialog(const Achievement &achievement, QWidget *parent = nullptr);
};

class GoalSetting : public QMainWindow
{
    Q_OBJECT

public:
    GoalSetting(QWidget *parent = nullptr,const QString &username = "");
    ~GoalSetting();
    void updateAchievementProgress(const QString& achievementId, int increment = 1);//更新进度
    void checkAllAchievements(); // 检查所有成就状态

    void checkLoginAchievements();     // 登录相关成就检测
    void checkFirstIncomeAchievement();// 第一笔收入成就检测
    void checkFirstExpenseAchievement();// 第一笔支出成就检测

    LoginStatus handleUserLogin();//处理登录事件

    int incomeCount;
    int costCount;
signals:
    void backToMenuRequested();

public slots:
    void onAchievementClicked(); // 成就按钮点击槽函数
    void onBackButtonClicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    QString username;
    Ui::GoalSetting *ui;
    // QVBoxLayout *m_achievementLayout;

    QVector<Achievement> achievements;
    QMap<QPushButton*, QString> buttonAchievementMap;

    void initializeAchievementMetadata();

    void loadUserAchievements();//加载用户成就数据
    void saveUserAchievements();//保存用户成就数据

    void refreshAchievementDisplay();//ui显示

    Achievement* findAchievementById(const QString& id);

    //void checkConsecutiveLogin();

    // 登录状态管理
    void loadLoginStats();
    void saveLoginStats();

    // 登录统计信息
    int m_totalLoginDays = 0;      // 累计登录天数
    int m_consecutiveLoginDays = 0;// 连续登录天数
    QDate m_lastLoginDate;         // 上次登录日期

    QPushButton *backButton;
};

#endif // GOALSETTING_H
