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
        main/window.cpp \
    main/helper.cpp \
    page/select/action.cpp \
    page/select/language.cpp \
    page/select/language/button.cpp

HEADERS  += main/window.h \
    stylesheet.h \
    main/helper.h \
    page/select/action.h \
    page/select/language.h \
    page/select/language/button.h

CONFIG += mobility
MOBILITY = 

