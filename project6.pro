QT       += core gui
QT       += core gui widgets
QT       += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brigetestersetting.cpp \
    brigetestsetting_expect_r.cpp \
    c.cpp \
    dc.cpp \
    device_dm3068.cpp \
    hardware/device.cpp \
    hardware/pm.cpp \
    hardware/testproject.cpp \
    l.cpp \
    main.cpp \
    mainwindow.cpp \
    r.cpp \
    va.cpp

HEADERS += \
    brigetestersetting.h \
    brigetestsetting_expect_r.h \
    c.h \
    datastruct.h \
    dc.h \
    device_dm3068.h \
    hardware/device.h \
    hardware/pm.h \
    hardware/testproject.h \
    l.h \
    mainwindow.h \
    r.h \
    va.h \
    visa.h \
    visatype.h \
    vpptype.h

FORMS += \
    brigetestersetting.ui \
    brigetestsetting_expect_r.ui \
    c.ui \
    dc.ui \
    device_dm3068.ui \
    l.ui \
    mainwindow.ui \
    r.ui \
    va.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    visa32.bas \
    vpptype.bas
INCLUDEPATH += $$quote(C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include)
LIBS += $$quote(C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Lib_x64\msc\nivisa64.lib)
LIBS += $$quote(C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Lib_x64\msc\visa64.lib)
include($$PWD/QXlsx/QXlsx.pri)
INCLUDEPATH += $$PWD/QXlsx
