#include "analyze.h"
#include "ui_analyze.h"
#include <QEvent>
#include<QDebug>
#include<QDate>
#include<QBarSet>
#include<QBarSeries>
#include<cmath>
#include <vector>
Analyze::Analyze(QWidget *parent,Menu* menu,QString username):QMainWindow(parent),ui(new Ui::Analyze),currentSeries(nullptr),currentChartView(nullptr),scrollArea(nullptr),label(nullptr),menuWindow(menu)
{

    ui->setupUi(this);
    this->username = username;
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/" + username + "_record.txt";

    // 设置文件路径
    file.setFileName(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        // 处理错误
    }

    //以下设置图表显示布局
    QVBoxLayout *layout = new QVBoxLayout(ui->ChartContainer);
    layout->setContentsMargins(0, 0, 0, 0); // 左、上、右、下边距
    layout->setSpacing(0); // 部件间距
    ui->ChartContainer->setLayout(layout);

    //以下是信号槽的实现
    connect(ui->exitBtn, &QPushButton::clicked, this, &Analyze::close);
    connect(ui->ChartChooseBtn, &QComboBox::activated, this, &Analyze::MakeCharts);
    connect(ui->backBtn, &QPushButton::clicked, this, &Analyze::onBackButtonClicked);
}

void Analyze::onBackButtonClicked()
{
    if (menuWindow) {
        menuWindow->show(); // 显示 Menu 界面
        this->hide(); // 隐藏 Analyze 界面
    }
}


void Analyze::closeEvent(QCloseEvent *event)
{
    emit closed(); // 发出关闭信号
    event->accept();
}

void Analyze::FileToDB()
{
    // 通过名称获取同一连接
    QSqlDatabase db = QSqlDatabase::database("my_connection");
    if (!db.isOpen()) {
        qDebug() << "db not open";
        return;
    }

    db.transaction(); // 开启事务
    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList parts = in.readLine().split('-');
        if (parts.size() < 6) continue;

        QString date = parts[0] + "-" + parts[1] + "-" + parts[2];
        QSqlQuery query(db); // 使用指定连接的数据库
        query.prepare("INSERT INTO records (date, value1, value2, value3) "
                      "VALUES (?, ?, ?, ?)");
        query.addBindValue(date);
        query.addBindValue(parts[3].toInt());
        query.addBindValue(parts[4].toDouble());
        query.addBindValue(parts[5].toInt());
        if (!query.exec()) { // 执行插入操作
            qDebug() << "fail to insert" ;
        }
    }
    db.commit(); // 提交事务
    file.close();
}
void Analyze::MakeCharts(int flag)
{
    if(flag == 0)
        MakeWeekPieChart();
    else if(flag == 1)
        MakeWeekTreeChart();
    else if(flag == 2)
        MakeMonthPieChart();
    else if(flag == 3)
        MakeMonthTreeChart();
}


void Analyze::DeletePreChart()
{
    if (scrollArea != nullptr) {
        ui->ChartContainer->layout()->removeWidget(scrollArea);
        delete scrollArea;//会自动删除关联的 QChart 和 QPieSeries
        currentChartView = nullptr;
        scrollArea = nullptr;
        //currentSeries = nullptr;好像没用
    }
    if(currentChartView != nullptr)
    {
        ui->ChartContainer->layout()->removeWidget(currentChartView);
        delete currentChartView;
        currentChartView = nullptr;
    }
}


void Analyze::MakeWeekTreeChart()
{
    DeletePreChart();//先删除

    std::vector<double> Costs(7);
    std::vector<double> income(7);

    QBarSet *incomeSet = new QBarSet("总收入");
    QBarSet *CostsSet = new QBarSet("总支出");

    incomeSet->setColor(QColor(67, 133, 244));  // 蓝色系
    CostsSet->setColor(QColor(240, 101, 67)); // 橙色系

    // //填充数据
    QDate currentDate = QDate::currentDate();
    QDate startDate = currentDate.addDays(-6);
    // 向前推7天
    for (const QSqlRecord &record : result_week) {
        QDate date = record.value("date").toDate();
        int daysOffset = startDate.daysTo(date);  // 直接计算日期差
        if (daysOffset >= 0 && daysOffset < 7) {
            double value2 = record.value("value2").toDouble();
            if (record.value("value1").toInt() == 1)
                income[daysOffset] += value2;  // 累加到对应天
            else
                Costs[daysOffset] += value2;
        }
    }

    for(int i=0;i<7;i++)
    {
        *incomeSet << income[i];
        *CostsSet << Costs[i];
    }

    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(incomeSet);
    series->append(CostsSet);
    series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);


    // 连接悬停信号以显示工具提示
    QObject::connect(series, &QStackedBarSeries::hovered, [=](bool status, int index, QBarSet *barSet) {
        if (status && index >= 0 && index < 7) {
            QDate date = startDate.addDays(index);
            double incomeVal = incomeSet->at(index);
            double costVal = CostsSet->at(index);
            QString toolTip = QString("日期: %1\n收入: %2 元\n支出: %3 元\n总计: %4 元")
                                  .arg(date.toString("MM-dd"))
                                  .arg(incomeVal, 0, 'f', 2)
                                  .arg(costVal, 0, 'f', 2)
                                  .arg(incomeVal - costVal, 0, 'f', 2);
            QToolTip::showText(QCursor::pos(), toolTip);
        } else {
            QToolTip::hideText();
        }
    });


    QStringList dateLabels;
    for (int i = 0; i < 7; ++i) {
        QDate date = startDate.addDays(i);
        dateLabels << date.toString("MM-dd");
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("近30天每日收支综合分析");
    chart->setAnimationOptions(QChart::AllAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(dateLabels);
    axisX->setLabelsAngle(45);
    axisX->setTitleText("日期 (日)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    double maxValue = 0;
    for(int i = 0; i < 7; i++)
    {
        maxValue = qMax(maxValue, income[i]+Costs[i]);
    }
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue * 1.2); // 自动缩放留白
    axisY->setTitleText("金额 (元)");
    axisY->setLabelFormat("%.0f");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setBarWidth(0.8);

    chart->setPlotArea(QRectF(0, 0, 1500, 500));
    currentChartView = new QChartView(chart);
    currentChartView->setRenderHint(QPainter::Antialiasing, false);
    currentChartView->setMinimumSize(1500, 611); // 设置足够大的最小尺寸
    currentChartView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // 固定尺寸策略
    // 创建滚动区域并设置
    scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(false); // 关键：禁用自动调整，允许滚动
    scrollArea->setWidget(currentChartView); // 将图表视图放入滚动区域

    ui->ChartContainer->layout()->addWidget(scrollArea);
    //实现具体内容
    qDebug()<<"finish to make the weekly tree chart."<<'\n';
}
void Analyze::MakeWeekPieChart()
{
    DeletePreChart(); // 先删除之前的图表

    std::vector<double> Costs(11);
    std::vector<double> income(5);
    for (const QSqlRecord& record : result_week) {
        int value1 = record.value("value1").toInt();
        double value2 = record.value("value2").toDouble();
        int value3 = record.value("value3").toInt();
        if (value1 == 1)
            income[value3 - 1] += value2;
        else
            Costs[value3 - 1] += value2;
    }

    QPieSeries* CostsSeries = new QPieSeries();
    // 定义分类名称
    QStringList categories = {
        "餐饮消费", "娱乐消费", "通勤消费", "日用消费", "医疗消费",
        "书籍消费", "礼品消费", "旅行消费", "服化消费", "电子产品消费", "订阅消费"
    };

    // 添加数据切片并设置标签格式
    double totalCosts = 0.0;
    for (double cost : Costs) {
        totalCosts += cost;
    }

    for (int i = 0; i < Costs.size(); ++i) {
        if (Costs[i] > 0.001) {
            double percentageValue = (totalCosts > 0.001) ? (Costs[i] * 100.0 / totalCosts) : 0.0;
            QPieSlice* slice = new QPieSlice(categories[i], Costs[i]);

            // 设置标签：使用手动计算的百分比
            slice->setLabel(QString("%1: %2%")
                                .arg(categories[i])
                                .arg(percentageValue, 0, 'f', 1));

            // 设置标签可见性：同样使用手动计算的百分比
            slice->setLabelVisible(percentageValue > 3.0); // 大于3%才显示

            // 悬停效果
            connect(slice, &QPieSlice::hovered, [=](bool hover) {
                slice->setExploded(hover);
            });
            CostsSeries->append(slice);
        }
    }

    CostsSeries->setHoleSize(0.35); // 中心空洞大小
    CostsSeries->setLabelsPosition(QPieSlice::LabelOutside); // 标签显示在外部

    // 创建图表
    QChart* chart = new QChart();
    chart->addSeries(CostsSeries);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setTitle("一周消费构成分析");
    chart->legend()->setAlignment(Qt::AlignRight); // 图例居右显示

    // 配置图表视图
    currentChartView = new QChartView(chart);
    currentChartView->setRenderHint(QPainter::Antialiasing);
    ui->ChartContainer->layout()->addWidget(currentChartView);

    qDebug() << "finish to make the weekly pie chart." << '\n';
}
void Analyze::MakeMonthTreeChart()
{
    DeletePreChart();//先删除

    std::vector<double> Costs(31);
    std::vector<double> income(31);

    QBarSet *incomeSet = new QBarSet("总收入");
    QBarSet *CostsSet = new QBarSet("总支出");

    incomeSet->setColor(QColor(67, 133, 244));  // 蓝色系
    CostsSet->setColor(QColor(240, 101, 67)); // 橙色系

    // //填充数据
    QDate currentDate = QDate::currentDate();
    QDate startDate = currentDate.addDays(-30);
    // 向前推一个月30天
    for (const QSqlRecord &record : result_month) {
        QDate date = record.value("date").toDate();
        int daysOffset = startDate.daysTo(date);  // 直接计算日期差
        if (daysOffset >= 0 && daysOffset < 31) {
            double value2 = record.value("value2").toDouble();
            if (record.value("value1").toInt() == 1)
                income[daysOffset] += value2;  // 累加到对应天
            else
                Costs[daysOffset] += value2;
        }
    }




    for(int i = 0;i < 31; i++)
    {
        // Costs[i] = 225.0 - (15-i)*(15-i);
        // income[i] = Costs[i] + i;
        //test
        *incomeSet << income[i];
        *CostsSet << Costs[i];
    }

    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(incomeSet);
    series->append(CostsSet);
    series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);


    // 连接悬停信号以显示工具提示
    QObject::connect(series, &QStackedBarSeries::hovered, [=](bool status, int index, QBarSet *barSet) {
        if (status && index >= 0 && index < 31) {
            QDate date = startDate.addDays(index);
            double incomeVal = incomeSet->at(index);
            double costVal = CostsSet->at(index);
            QString toolTip = QString("日期: %1\n收入: %2 元\n支出: %3 元\n总计: %4 元")
                                  .arg(date.toString("MM-dd"))
                                  .arg(incomeVal, 0, 'f', 2)
                                  .arg(costVal, 0, 'f', 2)
                                  .arg(incomeVal - costVal, 0, 'f', 2);
            QToolTip::showText(QCursor::pos(), toolTip);
        } else {
            QToolTip::hideText();
        }
    });


    QStringList dateLabels;
    for (int i = 0; i < 31; ++i) {
        QDate date = startDate.addDays(i);
        dateLabels << date.toString("MM-dd");
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("近30天每日收支综合分析");
    chart->setAnimationOptions(QChart::AllAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(dateLabels);
    axisX->setLabelsAngle(45);
    axisX->setTitleText("日期 (日)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    double maxValue = 0;
    for(int i = 0; i < 31; i++)
    {
        maxValue = qMax(maxValue, income[i]+Costs[i]);
    }
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue * 1.2); // 自动缩放留白
    axisY->setTitleText("金额 (元)");
    axisY->setLabelFormat("%.0f");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setBarWidth(0.8);

    chart->setPlotArea(QRectF(0, 0, 1500, 500));
    currentChartView = new QChartView(chart);
    currentChartView->setRenderHint(QPainter::Antialiasing, false);
    currentChartView->setMinimumSize(1500, 611); // 设置足够大的最小尺寸
    currentChartView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // 固定尺寸策略
    // 创建滚动区域并设置
    scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(false); // 关键：禁用自动调整，允许滚动
    scrollArea->setWidget(currentChartView); // 将图表视图放入滚动区域

    ui->ChartContainer->layout()->addWidget(scrollArea);

    //实现具体内容
    qDebug()<<"finish to make the monthly tree chart."<<'\n';
}
void Analyze::MakeMonthPieChart()
{
    DeletePreChart();//先删除

    std::vector<double> Costs(11);
    std::vector<double> income(5);
    for(const QSqlRecord &record : result_month)
    {
        int value1 = record.value("value1").toInt();
        double value2 = record.value("value2").toDouble();
        int value3 = record.value("value3").toInt();
        if (value1 == 1) {
            // 收入类别，value3应在1-5
            if (value3 >= 1 && value3 <= 5) {
                income[value3-1] += value2;
            } else {
                qWarning() << "Invalid income category:" << value3;
            }
        } else {
            // 支出类别，value3应在1-11
            if (value3 >= 1 && value3 <= 11) {
                Costs[value3-1] += value2;
            } else {
                qWarning() << "Invalid cost category:" << value3;
            }
        }
    }
    QPieSeries *CostsSeries = new QPieSeries();
    QStringList categories = {
        "餐饮消费", "娱乐消费", "通勤消费", "日用消费", "医疗消费",
        "书籍消费", "礼品消费", "旅行消费", "服化消费", "电子产品消费", "订阅消费"
    };

    double totalCosts = 0.0;
    for (double cost : Costs) {
        totalCosts += cost;
    }

    for (int i = 0; i < Costs.size(); ++i) {
        if (Costs[i] > 0.001) {
            double percentageValue = (totalCosts > 0.001) ? (Costs[i] * 100.0 / totalCosts) : 0.0;
            QPieSlice* slice = new QPieSlice(categories[i], Costs[i]);

            // 设置标签：使用手动计算的百分比
            slice->setLabel(QString("%1: %2%")
                                .arg(categories[i])
                                .arg(percentageValue, 0, 'f', 1));

            // 设置标签可见性：同样使用手动计算的百分比
            slice->setLabelVisible(percentageValue > 3.0); // 大于3%才显示

            // 悬停效果
            connect(slice, &QPieSlice::hovered, [=](bool hover) {
                slice->setExploded(hover);
            });
            CostsSeries->append(slice);
        }
    }

    CostsSeries->setHoleSize(0.35); // 中心空洞大小
    CostsSeries->setLabelsPosition(QPieSlice::LabelOutside); // 标签显示在外部

    // 创建图表
    QChart* chart = new QChart();
    chart->addSeries(CostsSeries);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setTitle("月度消费构成分析");
    chart->legend()->setAlignment(Qt::AlignRight); // 图例居右显示
    currentChartView = new QChartView(chart);
    currentChartView->setRenderHint(QPainter::Antialiasing);
    ui->ChartContainer->layout()->addWidget(currentChartView);

    qDebug()<<"finish to make the monthly pie chart."<<'\n';
}



bool Analyze::initDatabase()
{
    // 使用特定的连接名称
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
    db.setDatabaseName("mydata.db");
    if (!db.open()) {
        qDebug() << "db connect wrong";
        return false;
    }
    // 创建表（如果不存在）
    QSqlQuery query(db); // 使用指定连接的数据库
    query.exec("CREATE TABLE IF NOT EXISTS records ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "date TEXT,"
               "value1 INTEGER,"
               "value2 REAL,"
               "value3 INTEGER)");

    // 清空表内容（删除所有记录）
    if (!query.exec("DELETE FROM records")) {
        qDebug() << "清除表内容失败：";
        return false;
    }

    // 可选：重置自增计数器（下次插入id从1开始）
    query.exec("DELETE FROM sqlite_sequence WHERE name='records'");

    return true;
}


void Analyze::GetLastMonthData()
{
    QSqlDatabase db = QSqlDatabase::database("my_connection");
    if (!db.isOpen()) {
        qDebug() << "数据库未打开";
    }

    // 计算日期范围
    QDate currentDate = QDate::currentDate();
    QDate startDate = currentDate.addDays(-30); // 向前推一个月30天

    QSqlQuery query(db);
    query.prepare("SELECT * FROM records WHERE date BETWEEN ? AND ?");
    query.addBindValue(startDate.toString("yyyy-MM-dd"));
    query.addBindValue(currentDate.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "查询失败:" ;
    }

    // 遍历结果集
    while (query.next()) {
        result_month.append(query.record());
    }
}

void Analyze::GetLastWeekData()
{
    QSqlDatabase db = QSqlDatabase::database("my_connection");
    if (!db.isOpen()) {
        qDebug() << "数据库未打开";
    }

    // 计算日期范围
    QDate currentDate = QDate::currentDate();
    QDate startDate = currentDate.addDays(-7); // 向前推一周7天

    QSqlQuery query(db);
    query.prepare("SELECT * FROM records WHERE date BETWEEN ? AND ?");
    query.addBindValue(startDate.toString("yyyy-MM-dd"));
    query.addBindValue(currentDate.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "查询失败:" ;
    }

    // 遍历结果集
    while (query.next()) {
        result_week.append(query.record());
    }
}

