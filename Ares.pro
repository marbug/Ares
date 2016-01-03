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
    pageHelper.cpp \
    mainHelper.cpp \
    mainWindow.cpp \
    page/selectLanguagePage.cpp \
    page/selectActionPage.cpp \
    page/selectLanguagePageButton.cpp \
    mainHelperSubscriber.cpp \
    page/selectActionPageButton.cpp

HEADERS  += \
    stylesheet.h \
    pageHelper.h \
    mainHelper.h \
    mainWindow.h \
    page/selectLanguagePage.h \
    page/selectActionPage.h \
    page/selectLanguagePageButton.h \
    mainHelperSubscriber.h \
    page/selectActionPageButton.h

CONFIG += mobility
MOBILITY = 

