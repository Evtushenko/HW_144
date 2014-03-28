
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
    void init() {
         test = new ArrayList;
    }
    void cleanup(){
        delete test;
    }

    void testCorrectCreation() {
       QVERIFY(test->size() == 0);
    }
    void testPushOne() {
        test->push(testNumberArray);
        QVERIFY(test->size() == 1);
    }
    void testPushFour() {
        test->push(testNumberArray);
        test->push(testNumberArray + 1);
        test->push(testNumberArray + 2);
        test->push(testNumberArray + 3);
        QVERIFY(test->size() == 4);
    }
    void testPushHard() {
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        QVERIFY(test->size() ==  amountElementsTested);
    }
    void testPopOne() {
        test->push(testNumberArray);
        QVERIFY(test->pop() == testNumberArray);
        QVERIFY(test->size() == 0 );
    }
    void testPopFour() {
        test->push(testNumberArray);
        test->push(testNumberArray + 1);
        test->push(testNumberArray + 2);
        test->push(testNumberArray + 3);
        QVERIFY(test->pop() == testNumberArray + 3);
        QVERIFY(test->pop() == testNumberArray + 2);
        QVERIFY(test->pop() == testNumberArray + 1);
        QVERIFY(test->pop() == testNumberArray);
        QVERIFY(test->size() == 0 );
    }
    void testPopHard() {
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        for (int i =  amountElementsTested - 1; i >= 0; i--)
            QVERIFY(test->pop() == i);
        QVERIFY(test->size() == 0 );
    }
};
