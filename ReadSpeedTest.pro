#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T09:09:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ReadSpeedTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = data\icon.ico

SOURCES += \
    data\cpp\main.cpp \
    data\cpp\mainwindow.cpp \
    data\cpp\userdata.cpp \
    data\cpp\textdata.cpp \
    data\cpp\user_stats_window.cpp \
    data\cpp\test_window.cpp \
    data\cpp\graph_window.cpp \
    data\cpp\qcustomplot.cpp

HEADERS += \
    data\h\mainwindow.h \
    data\h\userdata.h \
    data\h\textdata.h \
    data\h\user_stats_window.h \
    data\h\basedata.h \
    data\h\test_window.h \
    data\h\graph_window.h \
    data\h\qcustomplot.h

FORMS += \
    data\ui\mainwindow.ui \
    data\ui\user_stats_window.ui \
    data\ui\test_window.ui \
    data\ui\graph_window.ui
