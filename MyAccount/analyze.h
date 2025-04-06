#ifndef ANALYZE_H
#define ANALYZE_H

#include "function.h"
#include <QEvent>
#include <vector>
#include <string>
#include <QSqlDatabase>
#include <iostream>
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
#include<menu.h>
#pragma push_macro("slots")
#undef slots //用于由于slots在Qt和Python都是关键字，互相冲突
//#include <Python.h>
#pragma pop_macro("slots")


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
    std::string question;
    Ui::Analyze *ui;
    QList<QSqlRecord> result_month;
    QAbstractSeries *currentSeries;
    QChartView *currentChartView;
    QScrollArea *scrollArea;
    QLabel *label;
    const char* AIresult;
    Menu* menuWindow;
public:
    Analyze(QWidget *parent = nullptr , Menu* menu=nullptr);//构造函数，实现分析类
    void FileToDB();//存储文件读取
    void MakeQuestion();//将文件信息转化可以投给大模型的问题
    int AIAnalyze();//调用API分析账单并提供建议
    void MakeWeekTreeChart();
    void MakeWeekPieChart();
    void MakeMonthTreeChart();
    void MakeMonthPieChart();
    void DeletePreChart();
    //制表：每周、每月树状、饼状图，共计四张
    bool initDatabase();//数据库创建
    void GetLastMonthData();
public slots:
    void MakeCharts(int flag);
    void AItext();
    void onBackButtonClicked();
signals:
    void closed(); // 关闭信号
    void backToMenu();

protected:
    void closeEvent(QCloseEvent *event) override; // 重写关闭事件
};

#endif // ANALYZE_H
