QT += core
QT -= gui

TARGET = ParallelMandelbrot
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    stb_image_write.h

