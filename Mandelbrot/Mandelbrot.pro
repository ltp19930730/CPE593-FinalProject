#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T15:04:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandelbrot
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp

HEADERS  += mainwindow.h \
    complex.hpp \
    mandelbrot.h \
    graphicview.h \
    graphic.h

FORMS    += mainwindow.ui
