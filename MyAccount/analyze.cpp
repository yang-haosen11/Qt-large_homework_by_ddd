#include "analyze.h"
#include "ui_analyze.h"
#include <QEvent>
#include<QDebug>
#include<QDate>
#include<QBarSet>
#include<QBarSeries>


Analyze::Analyze(QWidget *parent):QMainWindow(parent),ui(new Ui::Analyze),file("text.txt"),currentSeries(nullptr),currentChartView(nullptr),scrollArea(nullptr),label(nullptr)
{
    AIresult = nullptr;
    question.clear();
    ui->setupUi(this);

    //以下设置图表显示布局
    QVBoxLayout *layout = new QVBoxLayout(ui->ChartContainer);
    layout->setContentsMargins(0, 0, 0, 0); // 左、上、右、下边距
    layout->setSpacing(0); // 部件间距
    ui->ChartContainer->setLayout(layout);

    QVBoxLayout *layouttext = new QVBoxLayout(ui->AItextcontainer);
    layouttext->setContentsMargins(0, 0, 0, 0);
    layouttext->setSpacing(0);
    ui->AItextcontainer->setLayout(layouttext);


    //以下是信号槽的实现
    connect(ui->exitBtn, &QPushButton::clicked, this, &Analyze::close);
    connect(ui->ChartChooseBtn, &QComboBox::activated, this, &Analyze::MakeCharts);
    connect(ui->AIptn,&QPushButton::clicked,this,&Analyze::AItext);
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
        qDebug() << "数据库未打开";
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
            qDebug() << "插入数据失败:" ;
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
    //实现具体内容
    qDebug()<<"finish to make the weekly tree chart."<<'\n';
}
void Analyze::MakeWeekPieChart()
{
    qDebug()<<"finish to make the weekly pie chart."<<'\n';
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
    // // 向前推一个月30天
    // int flag = 0;
    // for(const QSqlRecord &record : result_month)
    // {
    //     QDate date = record.value("date").toDate();
    //     for(;flag<31;flag++)
    //     {
    //         if(date == startDate.addDays(flag))
    //             break;
    //     }
    //     int value1 = record.value("value1").toInt();
    //     double value2 = record.value("value2").toDouble();
    //     if(value1 == 1)
    //         income[flag] += value2;
    //     else
    //         Costs[flag] += value2;
    // }




    for(int i = 0;i < 31; i++)
    {
        Costs[i] = 225.0 - (15-i)*(15-i);
        income[i] = Costs[i] + i;
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
        if(value1==1)
            income[value3-1] += value2;
        else
            Costs[value3-1] += value2;
    }
    QPieSeries *CostsSeries = new QPieSeries();
    CostsSeries->append("餐饮消费",Costs[0]);
    CostsSeries->append("娱乐消费",Costs[1]);
    CostsSeries->append("通勤消费",Costs[2]);
    CostsSeries->append("日用消费",Costs[3]);
    CostsSeries->append("医疗消费",Costs[4]);
    CostsSeries->append("书籍消费",Costs[5]);
    CostsSeries->append("礼品消费",Costs[6]);
    CostsSeries->append("旅行消费",Costs[7]);
    CostsSeries->append("服化消费",Costs[8]);
    CostsSeries->append("电子产品消费",Costs[9]);
    CostsSeries->append("订阅消费",Costs[10]);
    CostsSeries->setHoleSize(0.35);
    QChart *chart = new QChart();
    chart->addSeries(CostsSeries);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setTitle("月度消费构成分析");
    foreach(QPieSlice *slice, CostsSeries->slices()){
        slice->setLabelVisible(true);  // 强制显示标签
        connect(slice, &QPieSlice::hovered, [=](bool hover){
            slice->setExploded(hover);  // 悬停时弹出分块
        });
    }
    currentChartView = new QChartView(chart);
    currentChartView->setRenderHint(QPainter::Antialiasing);
    ui->ChartContainer->layout()->addWidget(currentChartView);

    qDebug()<<"finish to make the monthly pie chart."<<'\n';
}



void Analyze::MakeQuestion()
{
    //需要与FileInfro联动，暂未实现
    std::string income = "income:2000 ";
    std::string FoodCosts = "food costs:1200 ";
    std::string EntertainCosts = "entertainment costs:400 ";
    std::string TransportCosts = "transportation costs:30 ";
    std::string NecessityCosts = "necessity costs:250 ";
    //需要根据实际情况修改
    std::string Ster = "I am living in Beijing, please give me some advice";
    question = income + FoodCosts + EntertainCosts + TransportCosts + NecessityCosts;
}



/*int Analyze::AIAnalyze()
{
    SetConsoleOutputCP(CP_UTF8);
    Py_SetPythonHome(L"C:/Users/yhs19/Desktop/Qt_large_homework_localrepo/python_used");
    // 初始化Python解释器
    Py_Initialize();

    // 执行Python代码
    PyRun_SimpleString("import sys\n"
                       "sys.path.append('C:/Users/yhs19/Desktop/Qt_large_homework_localrepo/MyAccount')\n");//添加当前目录
    PyObject* pModule = PyImport_ImportModule("analyse_test");
    if (!pModule) {
        std::cout<< "Cant open python file!" << std::endl;
        return -1;
    }
    PyObject* pTalk = PyObject_GetAttrString(pModule,"get_coze_response");//python函数调用
    if(!pTalk){
        std::cout<< "Get func Talk failed!" << std::endl;
    }
    const char*question_c = question.c_str();//string转char*,方便传参
    PyObject* response = PyObject_CallFunction(pTalk,"sii",question_c,30,1);
    //打印返回值->之后根据实际进行位置修改
    if (response == NULL) {
        // 处理调用失败的情况
        PyErr_Print();
        std::cout << u8"函数调用失败" << std::endl;
    }
    else {
        // 检查返回值类型是否为字符串
        if (PyUnicode_Check(response)) {
            // 转换为C字符串并打印
            AIresult = PyUnicode_AsUTF8(response);
            std::cout << AIresult << std::endl;
        }
        else {
            std::cout<<u8"返回值非字符串"<<std::endl;
        }

        // 释放引用计数
        Py_DECREF(response);
    }
    // 清理解释器
    Py_Finalize();
    return 0;
}
*/
void Analyze::AItext()
{
    if(label != nullptr)
    {
        ui->AItextcontainer->layout()->removeWidget(label);
        delete label;
        label = nullptr;
    }
    /*int a = AIAnalyze();
    if(a == 0)
    {
        label = new QLabel();
        label->setText(AIresult);
        ui->AItextcontainer->layout()->addWidget(label);
        ui->AItextcontainer->layout()->setAlignment(Qt::AlignCenter);
    }*/
}




bool Analyze::initDatabase()
{
    // 使用特定的连接名称
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
    db.setDatabaseName("mydata.db");
    if (!db.open()) {
        qDebug() << "数据库连接失败";
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
