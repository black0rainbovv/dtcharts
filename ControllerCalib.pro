QT       += core gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DTCharts
TEMPLATE = app

VERSION = 1.4.4

RC_ICONS = Short.ico

LIBS += -lsetupapi \
        -lwinmm

SOURCES += main.cpp\
        mainwindow.cpp \
    CANChannels.cpp \
    CypressUsb.cpp \
    Utility.cpp \
    qcustomplot.cpp \
    plotdialog.cpp \
    colorswidget.cpp \
    termcycledialog.cpp \
    selectdeviceform.cpp \
    about.cpp \
    dtsettings.cpp

HEADERS  += mainwindow.h \
    CANChannels.h \
    cyioctl.h \
    CypressUsb.h \
    Utility.h \
    qcustomplot.h \
    plotdialog.h \
    colorswidget.h \
    termcycledialog.h \
    selectdeviceform.h \
    about.h \
    dtsettings.h

FORMS    += mainwindow.ui \
    plotdialog.ui \
    termcycledialog.ui \
    selectdeviceform.ui \
    about.ui \
    dtsettings.ui

RESOURCES += resourses.qrc\

