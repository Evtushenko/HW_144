
#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "arrayList.h"

class TestArrayList: public QObject
{
    Q_OBJECT
public:
    explicit TestArrayList(QObject *parent = 0) : QObject(parent) {}
private:
    ArrayList *test;
    int const testNumberArray = 1;
private slots:
    void testCorrectCreation() {
       test = new ArrayList;
       QVERIFY(test->size() == 0);
       delete test;
    }
    void testPushOne() {
        test = new ArrayList;
        test->push(testNumberArray);
        QVERIFY(test->size() == 1);
        delete test;
    }
    void testPushFour() {
        test = new ArrayList;
        test->push(testNumberArray);
        test->push(testNumberArray + 1);
        test->push(testNumberArray + 2);
        test->push(testNumberArray + 3);
        QVERIFY(test->size() == 4);
        delete test;
    }
    void testPushHard() {
        test = new ArrayList;
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        QVERIFY(test->size() ==  amountElementsTested);
        delete test;
    }
    void testPopOne() {
        test = new ArrayList;
        test->push(testNumberArray);
        QVERIFY(test->pop() == testNumberArray);
        QVERIFY(test->size() == 0 );
        delete test;
    }
    void testPopFour() {
        test = new ArrayList;
        test->push(testNumberArray);
        test->push(testNumberArray + 1);
        test->push(testNumberArray + 2);
        test->push(testNumberArray + 3);
        QVERIFY(test->pop() == testNumberArray + 3);
        QVERIFY(test->pop() == testNumberArray + 2);
        QVERIFY(test->pop() == testNumberArray + 1);
        QVERIFY(test->pop() == testNumberArray);
        QVERIFY(test->size() == 0 );
        delete test;
    }
    void testPopHard() {
        test = new ArrayList;
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        for (int i =  amountElementsTested - 1; i >= 0; i--)
            QVERIFY(test->pop() == i);
        QVERIFY(test->size() == 0 );
        delete test;
    }
};
