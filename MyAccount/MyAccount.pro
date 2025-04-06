QT       += core gui
QT        +=sql
QT          +=charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analyze.cpp \
    function.cpp \
    goalsetting.cpp \
    login.cpp \
    main.cpp \
    menu.cpp \
    record.cpp \
    start.cpp

HEADERS += \
    analyze.h \
    function.h \
    goalsetting.h \
    login.h \
    menu.h \
    record.h \
    start.h \
    ui_analyze.h

FORMS += \
    analyze.ui \
    login.ui \
    menu.ui \
    start.ui
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
