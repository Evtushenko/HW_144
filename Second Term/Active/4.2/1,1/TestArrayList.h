
#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "ArrayList.h"

class TestArrayList: public QObject
{
    Q_OBJECT
public:
    explicit TestArrayList(QObject *parent = 0) : QObject(parent) {}
private:
    ArrayList *test;
private slots:
    void TestCorrectCreation() {
       test = new ArrayList;
       QVERIFY(test->size() == 0);
    }
    void testPush() {
        test = new ArrayList;
        int testNumber = 1;
        test->push(testNumber);
        test->push(testNumber+1);
        test->push(testNumber+2);
        QVERIFY(test->size() == 3);
        void testPop();
    }
    void testPop() {
        int testNumber = 1;
        QVERIFY(test->pop() == testNumber+2);
        QVERIFY(test->pop() == testNumber+1);
        QVERIFY(test->pop() == testNumber);
        QVERIFY(test->size() == 0 );
    }
};
