#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T15:04:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandelbrot
TEMPLATE = app
CONFIG += c++14

SOURCES += main.cpp \
    complex.cpp \
    graphic.cpp \
    mainwindow.cpp \
    graphicview.cpp \
    mandelbrot.cpp \
    mandelbrotthread.cpp

HEADERS  += mainwindow.h \
    complex.hpp \
    mandelbrot.h \
    graphicview.h \
    graphic.h \
    others.hpp \
    mandelbrotthread.hpp

FORMS    += mainwindow.ui
