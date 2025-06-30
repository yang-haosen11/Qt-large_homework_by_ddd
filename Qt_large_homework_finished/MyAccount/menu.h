#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QString>
#include <QWidget>
#include "goalsetting.h"
class Analyze;
class Record;
class GoalSetting;
QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr, QString username = "",
                  GoalSetting *achievementSystem = nullptr);
    ~Menu();
    QString currentUsername;
    GoalSetting *achievementSystem; // 存储成就系统引用
signals:
    void logoutRequested();
    void themeChanged(const QString &theme);
    void showMenu(); // 用于在 Analyze 界面返回 Menu 界面的信号

private slots:
    void onIncomeExpenseRecordClicked();
    void onIncomeExpenseAnalysisClicked();
    void onAchievementSystemClicked();
    void onLogoutTriggered();
    void onLightThemeTriggered();
    void onDarkThemeTriggered();
    void onAnalyzeWindowClosed(); // 处理 Analyze 界面关闭的槽函数
    void onrecordsInputWindowClosed();
    void ongoalsettingWindowClosed();
    void handleBackFromAchievement();
private:
    Ui::Menu *ui;

    Analyze *analyzeWindow;
    Record *recordsInputWindow;
    GoalSetting *goalsettingWindow;

    void setupButtonAnimations();
    void showFeatureMessage(const QString &featureName);
    void setBackgroundImage(const QString &imagePath);
};
#endif // MENU_H
