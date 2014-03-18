#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "PointStack.h"

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
    }
    void testPush() {
        test = new PointStack;
        test->push(testNumberPoint);
        test->push(testNumberPoint + 1);
        test->push(testNumberPoint + 2);
        QVERIFY(test->size() == 3);
    }
    void testPop() {
        test = new PointStack;
        test->push(testNumberPoint);
        test->push(testNumberPoint + 1);
        test->push(testNumberPoint + 2);
        QVERIFY(test->pop() == testNumberPoint + 2);
        QVERIFY(test->pop() == testNumberPoint + 1);
        QVERIFY(test->pop() == testNumberPoint);
        QVERIFY(test->size() == 0 );
    }
    void testGetTop() {
        test = new PointStack;
        test->push(testNumberPoint + 2);
        QVERIFY(test->getTop() == testNumberPoint + 2);
    }
    void testCorrectInfix() {
       test = new PointStack;
       char inPut[] = "1+1";
       char outPut[] = "11+";
       char *res = test->infix(inPut);
       int length = strlen(outPut);
       for (int i = 0; i < length; i++)
           QCOMPARE(char(res[i]), outPut[i]);
    }
    void testCorrectCalc() {
        test = new PointStack;
        int resultTest = 2;
        char inPut[] = "11+";
        QVERIFY(test->calculateStack(inPut) == resultTest);
    }
};
