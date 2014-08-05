#pragma once
#include <QChar>
#include <QList>
#include "word.h"

class Letter {
public:
    Letter() {}
    ~Letter() {}
    QChar value;
    QList <Word> listWords;
};
