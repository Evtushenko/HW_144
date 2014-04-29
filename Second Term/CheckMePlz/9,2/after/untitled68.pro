#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T10:43:27
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = untitled68

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    hashing.cpp \
    CRC32Hash.cpp \
    hash31.cpp \
    hashTable.cpp \
    pointerList.cpp \
    rotatingHash.cpp

HEADERS += \
    hashing.h \
    CRC32Hash.h \
    hash31.h \
    rotatingHash.h \
    hashTableTest.h \
    hashTable.h \
    tableCell.h \
    pointerList.h \
    elementList.h
