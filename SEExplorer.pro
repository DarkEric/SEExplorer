#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T18:06:53
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEExplorer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qdatabase.cpp \
    addnewdialog.cpp

HEADERS  += mainwindow.h \
    qdatabase.h \
    addnewdialog.h

FORMS    += mainwindow.ui \
    addnewdialog.ui

DISTFILES +=
