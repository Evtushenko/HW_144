TEMPLATE = app

CONFIG += console
CONFIG += qtestlib
CONFIG += c++11

SOURCES += main.cpp \
    hashing.cpp

HEADERS += \
    hashing.h \
    hash31.h \
    CRC32Hash.h \
    hashTable.h \
    hashTableTest.h \
    pointerList.h \
    rotatingHash.h \
    tableCell.h \
    elementList.h

