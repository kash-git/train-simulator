#-------------------------------------------------
#
# Project created by QtCreator 2023-04-11T16:04:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Control_Center
TEMPLATE = app
CONFIG +=C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    graph.cpp \
    speedometer.cpp \
    trainsim.cpp

HEADERS  += mainwindow.h \
    trainthread.h \
    graph.h \
    speedometer.h \
    trainsim.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
