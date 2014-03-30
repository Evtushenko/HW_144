#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "pointStack.h"

int const testNumberPoint = 1;

class TestPointStack: public QObject
{
    Q_OBJECT
public:
    explicit TestPointStack(QObject *parent = 0) : QObject(parent) {}
private:
    PointStack *test;
private slots:
    void init() {
       test = new PointStack;
    }
    void cleanup(){
       delete test;
    }
    void testCorrectCreation() {
       QVERIFY(test->size() == 0);
    }
    void testPushOne() {
        test->push(testNumberPoint);
        QVERIFY(test->size() == 1);
    }
    void testPushFour() {
        test->push(testNumberPoint);
        test->push(testNumberPoint + 1);
        test->push(testNumberPoint + 2);
        test->push(testNumberPoint + 3);
        QVERIFY(test->size() == 4);
    }
    void testPushHard() {
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        QVERIFY(test->size() ==  amountElementsTested);
    }
    void testPopOne() {
        test->push(testNumberPoint);
        QVERIFY(test->pop() == testNumberPoint);
        QVERIFY(test->size() == 0 );
    }
    void testPopFour() {
        test->push(testNumberPoint);
        test->push(testNumberPoint + 1);
        test->push(testNumberPoint + 2);
        test->push(testNumberPoint + 3);
        QVERIFY(test->pop() == testNumberPoint + 3);
        QVERIFY(test->pop() == testNumberPoint + 2);
        QVERIFY(test->pop() == testNumberPoint + 1);
        QVERIFY(test->pop() == testNumberPoint);
        QVERIFY(test->size() == 0 );
    }
    void testPopHard() {
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        for (int i = amountElementsTested-1; i >= 0; i--)
            QVERIFY(test->pop() == i);
        QVERIFY(test->size() == 0 );
    }
    void testGetTop() {
        test->push(testNumberPoint + 2);
        QVERIFY(test->getTop() == testNumberPoint + 2);
    }
    void testCorrectInfix() {
       char inPut[] = "1+1";
       char outPut[] = "11+";
       char *res = test->infix(inPut);
       int length = strlen(outPut);
       for (int i = 0; i < length; i++)
           QCOMPARE(char(res[i]), outPut[i]);
    }
    void testCorrectCalc() {
        int resultTest = 2;
        char inPut[] = "11+";
        QVERIFY(test->calculateStack(inPut) == resultTest);
    }
};
