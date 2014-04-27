TEMPLATE = app
CONFIG += console
CONFIG += qtestlib

SOURCES += main.cpp \
    hashtable.cpp \
    hash31.cpp \
    CRC32Hash.cpp \
    RotatingHash.cpp

HEADERS += \
    hashtable.h \
    hashing.h \
    PointerList.h \
    ElementList.h \
    TableCell.h \
    hash31.h \
    CRC32Hash.h \
    RotatingHash.h \
    hashtableTest.h

