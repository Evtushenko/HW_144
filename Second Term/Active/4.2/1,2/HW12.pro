#-------------------------------------------------
#
# Project created by QtCreator 2014-03-23T11:43:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = HW12
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    pointStack.cpp \
    stackGeneral.cpp \
    arrayStack.cpp

HEADERS += \
    stackGeneral.h \
    pointStack.h \
    arrayStack.h \
    testArrayStack.h \
    testPointStack.h
