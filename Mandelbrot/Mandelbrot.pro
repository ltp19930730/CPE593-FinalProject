#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T15:04:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandelbrot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    complex.hpp \
    mandelbrot.h

FORMS    += mainwindow.ui
