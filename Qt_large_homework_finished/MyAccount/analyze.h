#ifndef ANALYZE_H
#define ANALYZE_H


#include <QEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include<QFile>
#include <QChart>
#include <QPieSeries>
#include<QAbstractSeries>
#include <QPieSlice>
#include <QChartView>
#include <QTextStream>
#include <windows.h>
#include"menu.h"
#include<QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class
    Analyze;
}
QT_END_NAMESPACE

class Menu;

class Analyze : public QMainWindow
{
    Q_OBJECT
    QFile file;
    Ui::Analyze *ui;
    QList<QSqlRecord> result_month;
    QList<QSqlRecord> result_week;
    QAbstractSeries *currentSeries;
    QChartView *currentChartView;
    QScrollArea *scrollArea;
    QLabel *label;
    Menu* menuWindow;
    QString username;
public:
    Analyze(QWidget *parent = nullptr , Menu* menu=nullptr, QString username = "");//构造函数，实现分析类
    void FileToDB();//存储文件读取
    void MakeWeekTreeChart();
    void MakeWeekPieChart();
    void MakeMonthTreeChart();
    void MakeMonthPieChart();
    void DeletePreChart();
    //制表：每周、每月树状、饼状图，共计四张
    bool initDatabase();//数据库创建
    void GetLastMonthData();
    void GetLastWeekData();
public slots:
    void MakeCharts(int flag);
    void onBackButtonClicked();
signals:
    void closed(); // 关闭信号
    void backToMenu();

protected:
    void closeEvent(QCloseEvent *event) override; // 重写关闭事件
};

#endif // ANALYZE_H
