#-------------------------------------------------
#
# Project created by QtCreator 2015-12-21T23:27:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ares
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainhelper.cpp \
    selectactionpage.cpp

HEADERS  += mainwindow.h \
    stylesheet.h \
    mainhelper.h \
    selectactionpage.h

CONFIG += mobility
MOBILITY = 

