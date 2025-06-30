#include "record.h"
#include "qdir.h"
#include "ui_recordsInput.h"
#include "ui_recentRecords.h"

Record::Record(QWidget *parent):Function(parent),recordsInputUi(new Ui::recordsInput),
    recentRecordsUi(new Ui::recentRecords)
{
    recordsInputUi->setupUi(this);
    //recentRecordsUi->setupUi(this);
    connect(recordsInputUi->recordBack,&QPushButton::clicked,this,&Record::close);
    //connect(recordsInputUi->dateEdit,&QDateEdit::editingFinished,this,&Record::fillDate);
    connect(recordsInputUi->recordConfirm,&QPushButton::clicked,this,&Record::onConfirmPressed);
    //connect(recordsInputUi->recordType,,&QComboBox::)
}

void Record::fillDate(){
    date = recordsInputUi->dateEdit->date();
}
void Record::fillCategory(){
    if(recordsInputUi->cost->isChecked()){
        this->category = 2;
    }
    else if(recordsInputUi->income->isChecked()){
        this->category = 1;
    }
}
void Record::fillType(){
    accountType = recordsInputUi->recordType->currentIndex();
}
void Record::fillAmount(){
    accountAmount = recordsInputUi->recordAmount->value();
}
void Record::onConfirmPressed(){
    fillDate();
    fillCategory();
    fillType();
    fillAmount();

    // QDir().mkdir("./rec");
    // QFile file("./rec/records.txt");
    // if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
    //     qDebug() << "文件打开失败：" << file.errorString();
    //     return;
    // }
    // //int a = 1;
    // QTextStream stream(&file);
    // stream >> date.year() >> "-" >> date.month() >> "-" >> date.day() >> "-"
    //     >> category >> "-" >> accountAmount >> "-" >> accountType >> endl;
    // //file.write("%4d-%02d-%02d-%d-%.2lf-%d\n",date.year(),date.month(),date.day(),category,accountAmount,accountType);
    // file.close();
    // Record::close();
    string dir = QDir::currentPath().toStdString();
    const string path = dir+"/rec/records.txt";
    cout << path;
    ofstream file(path,ios::app);
    if(!file.is_open()){
        cerr<<"Error when opening the file!"<<endl;
    }
    else{
        // cout << date.year() << "-" << date.month() << "-" << date.day() << "-"
        //      << category << "-" << accountAmount << "-" << accountType <<endl;
        file << date.year() << "-" << date.month() << "-" << date.day() << "-"
             << category << "-" << accountAmount << "-" << accountType <<endl;
    }
    file.close();
    Record::close();
}

