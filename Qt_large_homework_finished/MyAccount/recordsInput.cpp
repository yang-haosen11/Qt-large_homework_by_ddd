#include "recordsInput.h"
#include "qdir.h"
#include "ui_recordsInput.h"
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
//#include "ui_recentRecords.h"

Record::Record(QWidget *parent, Menu* menu, QString username):QMainWindow(parent),recordsInputUi(new Ui::recordsInput),menuWindow(menu)
    //  recentRecordsUi(new Ui::recentRecords)
{
    this->username = username;
    recordsInputUi->setupUi(this);
    //recentRecordsUi->setupUi(this);
    recordsInputUi->dateEdit->setDate(QDate::currentDate());
    connect(recordsInputUi->recordBack, &QPushButton::clicked, this, &Record::onBackButtonClicked);
    //connect(recordsInputUi->dateEdit,&QDateEdit::editingFinished,this,&Record::fillDate);
    connect(recordsInputUi->recordConfirm,&QPushButton::clicked,this,&Record::onConfirmPressed);
    //connect(recordsInputUi->recordType,,&QComboBox::)
    setupButtonAnimations();
}

void Record::setupButtonAnimations()
{
    // 为按钮添加悬停动画效果
    QList<QPushButton*> allButtons = findChildren<QPushButton*>();
    foreach (QPushButton* button, allButtons) {
        button->setAttribute(Qt::WA_Hover, true);

        // 创建按钮悬停效果
        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(button);
        effect->setBlurRadius(10);
        effect->setColor(QColor(0, 0, 0, 80));
        effect->setOffset(0, 0);
        button->setGraphicsEffect(effect);

        // 存储原始大小
        button->setProperty("originalSize", button->size());
    }
}

void Record::onBackButtonClicked()
{
    if (menuWindow) {
        menuWindow->show(); // 显示 Menu 界面
        this->hide(); // 隐藏 Record 界面
    }
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
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/" + username + "_record.txt";

    // 设置文件路径
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Error when opening the file:" << file.errorString();
    } else {
        QTextStream out(&file);
        out << date.year() << "-" << date.month() << "-" << date.day() << "-"
            << category << "-" << accountAmount << "-" << accountType << "\n";

        // 不再需要显式调用 close()，QFile 析构时会自动关闭
        // 但作为好习惯，我们可以在作用域结束前关闭
        file.close();
    }
    if (category == 1) { // 收入
        emit incomeRecorded();
    } else if (category == 2) { // 支出
        emit expenseRecorded();
    }

    // 清空输入字段而非关闭窗口
    recordsInputUi->recordAmount->setValue(0.0);
    recordsInputUi->recordType->setCurrentIndex(0);

    QMessageBox::information(this, "保存成功", "记录已成功保存！");

}
