#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T21:36:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chessGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameboard.cpp \
    readme.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    readme.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc
