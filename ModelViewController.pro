#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T14:56:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModelViewController
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        dialog.cpp \
    personmodel.cpp \
    personproxymodel.cpp

HEADERS  += dialog.h \
    personmodel.h \
    personproxymodel.h

FORMS    += dialog.ui
