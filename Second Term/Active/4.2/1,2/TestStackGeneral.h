#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "StackGeneral.h"

//int const testNumberPoint = 1;

class TestStackGeneral: public QObject
{
    Q_OBJECT
public:
    explicit TestStackGeneral(QObject *parent = 0) : QObject(parent) {}
private:
    StackGeneral *test;
private slots:
    void TestCorrectInfix() {
       //test = new StackGeneral;
       //QVERIFY(test->infix("1+1") == "11+");
    }

};
