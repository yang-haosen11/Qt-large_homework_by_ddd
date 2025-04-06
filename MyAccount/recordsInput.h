#ifndef RECORD_H
#define RECORD_H
#include<menu.h>
#include <QObject>
#include "function.h"
#include "qmainwindow.h"
#include <QEvent>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <QWidget>
#include <QDate>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <io.h>
#include<windows.h>
//using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class
    recordsInput;
class
    recentRecords;
}
QT_END_NAMESPACE

struct Time{
    int year;
    int month;
    int date;
};

#pragma region 支出
typedef enum{
    FoodCosts = 1,
    EntertainCosts = 2,
    TransportCosts = 3,
    NecessityCosts = 4,
    MedicalCosts = 5,
    BookCosts = 6,
    GiftCosts = 7,
    TravelCosts = 8,
    DressCosts = 9,
    DigitalCosts = 10,
    SubscribeCosts = 11,
    OtherCosts = 99
}out_kind_t;
#pragma endregion

#pragma region 收入
typedef enum{
    Salary = 1,
    Tutor = 2,
    Management = 3,
    Part_time = 4,
    Parent = 5,
    OtherIn = 99
}in_kind_t;
#pragma endregion

class Record : public QMainWindow
{
    Q_OBJECT
private:
    float val;//amount of money
    int category;//收入or支出,收入 = 1，支出 = 2
    int accountType;
    QDate date;
    double accountAmount;
    // static int outenum;
    // static int inenum;
    Menu* menuWindow;
    Ui::recordsInput *recordsInputUi;
    Ui::recentRecords *recentRecordsUi;


public:
    Record(QWidget *parent = nullptr, Menu* menu=nullptr);
    //void recordIn();
public slots:
    void fillDate();
    void fillCategory();
    void fillType();
    void fillAmount();
    void onConfirmPressed();
    void onBackButtonClicked();
    void setupButtonAnimations();
};




#endif // RECORD_H
