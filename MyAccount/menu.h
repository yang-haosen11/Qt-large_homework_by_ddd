#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QString>
#include <QWidget>
class Analyze;
class Record;
QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr, QString username = "");
    ~Menu();

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

private:
    Ui::Menu *ui;
    QString currentUsername;
    Analyze *analyzeWindow;
    Record *recordsInputWindow;
    void setupButtonAnimations();
    void showFeatureMessage(const QString &featureName);
    void setBackgroundImage(const QString &imagePath);
};
#endif // MENU_H
