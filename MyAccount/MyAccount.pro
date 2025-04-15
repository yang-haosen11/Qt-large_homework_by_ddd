QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analyze.cpp \
    function.cpp \
    goalsetting.cpp \
    main.cpp \
    menu.cpp \
    record.cpp \
    start.cpp

HEADERS += \
    analyze.h \
    function.h \
    goalsetting.h \
    menu.h \
    record.h \
    start.h

FORMS += \
    start.ui

TRANSLATIONS += \
    MyAccount_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# 解决python调用问题
# 修改为你的Python版本号（例如311）
PYTHON_VERSION = 313
PYTHON_DIR = C:\Users\yhs19\Desktop\Qt_large_homework_localrepo\python_used

# 包含Python头文件
INCLUDEPATH += $${PYTHON_DIR}/include

# 链接Python库
LIBS += -L$${PYTHON_DIR}/libs -lpython$${PYTHON_VERSION}

# 处理Debug/Release版本差异（仅Windows需要）
win32 {
    CONFIG(debug, debug|release) {
        # 调试模式：链接python3XX_d.lib（若存在）
        LIBS += -lpython$${PYTHON_VERSION}_d
    } else {
        # 发布模式：链接python3XX.lib
        LIBS += -lpython$${PYTHON_VERSION}
    }
}

DISTFILES += \
    analyse_test.py \
    test.py
