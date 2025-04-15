#include "analyze.h"

Analyze::Analyze() {
    FileInfro.clear();
    question.clear();
}
void Analyze::FileRead()
{
}
void Analyze::MakeCharts()
{

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
int Analyze::AIAnalyze()
{
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
        std::cout << "函数调用失败" << std::endl;
    }
    else {
        // 检查返回值类型是否为字符串
        if (PyUnicode_Check(response)) {
            // 转换为C字符串并打印
            const char *result = PyUnicode_AsUTF8(response);
            std::cout << result << std::endl;
        }
        else {
            std::cout<<"返回值非字符串"<<std::endl;
        }

        // 释放引用计数
        Py_DECREF(response);
    }
    // 清理解释器
    Py_Finalize();
    return 0;
}
