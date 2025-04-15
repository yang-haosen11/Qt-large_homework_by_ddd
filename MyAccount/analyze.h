#ifndef ANALYZE_H
#define ANALYZE_H

#include "function.h"
#include <QEvent>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#pragma push_macro("slots")
#undef slots //用于由于slots在Qt和Python都是关键字，互相冲突
#include <Python.h>
#pragma pop_macro("slots")
class Analyze : public Function
{
private:
    std::vector<int> FileInfro;
    std::string question;
public:
    Analyze();//构造函数，实现分析类
    void FileRead();//存储文件读取
    void MakeCharts();//制表：每周、每月树状、饼状图，共计四张
    void MakeQuestion();//将文件信息转化可以投给大模型的问题
    int AIAnalyze();//调用API分析账单并提供建议
};

#endif // ANALYZE_H
