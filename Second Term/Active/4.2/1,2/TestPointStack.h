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
    void testCorrectCreation() {
       test = new PointStack;
       QVERIFY(test->size() == 0);
       delete test;
    }
    void testPushOne() {
        test = new PointStack;
        test->push(testNumberPoint);
        QVERIFY(test->size() == 1);
        delete test;
    }
    void testPushFour() {
        test = new PointStack;
        test->push(testNumberPoint);
        test->push(testNumberPoint + 1);
        test->push(testNumberPoint + 2);
        test->push(testNumberPoint + 3);
        QVERIFY(test->size() == 4);
        delete test;
    }
    void testPushHard() {
        test = new PointStack;
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        QVERIFY(test->size() ==  amountElementsTested);
        delete test;
    }
    void testPopOne() {
        test = new PointStack;
        test->push(testNumberPoint);
        QVERIFY(test->pop() == testNumberPoint);
        QVERIFY(test->size() == 0 );
        delete test;
    }
    void testPopFour() {
        test = new PointStack;
        test->push(testNumberPoint);
        test->push(testNumberPoint + 1);
        test->push(testNumberPoint + 2);
        test->push(testNumberPoint + 3);
        QVERIFY(test->pop() == testNumberPoint + 3);
        QVERIFY(test->pop() == testNumberPoint + 2);
        QVERIFY(test->pop() == testNumberPoint + 1);
        QVERIFY(test->pop() == testNumberPoint);
        QVERIFY(test->size() == 0 );
        delete test;
    }
    void testPopHard() {
        test = new PointStack;
        int amountElementsTested = 100;
        for (int i = 0; i < amountElementsTested; i++ )
            test->push(i);
        for (int i = amountElementsTested-1; i >= 0; i--)
            QVERIFY(test->pop() == i);
        QVERIFY(test->size() == 0 );
        delete test;
    }
    void testGetTop() {
        test = new PointStack;
        test->push(testNumberPoint + 2);
        QVERIFY(test->getTop() == testNumberPoint + 2);
        delete test;
    }
    void testCorrectInfix() {
       test = new PointStack;
       char inPut[] = "1+1";
       char outPut[] = "11+";
       char *res = test->infix(inPut);
       int length = strlen(outPut);
       for (int i = 0; i < length; i++)
           QCOMPARE(char(res[i]), outPut[i]);
       delete test;
    }
    void testCorrectCalc() {
        test = new PointStack;
        int resultTest = 2;
        char inPut[] = "11+";
        QVERIFY(test->calculateStack(inPut) == resultTest);
        delete test;
    }
};
