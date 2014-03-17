#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "ArrayStack.h"

int const testNumberArray = 1;

class TestArrayStack: public QObject
{
    Q_OBJECT
public:
    explicit TestArrayStack(QObject *parent = 0) : QObject(parent) {}
private:
    ArrayStack *test;
private slots:
        void TestCorrectCreation() {
           test = new ArrayStack;
           QVERIFY(test->size() == 0);
        }
        void testPush() {
            test = new ArrayStack;
            test->push(testNumberArray);
            test->push(testNumberArray+1);
            test->push(testNumberArray+2);
            QVERIFY(test->size() == 3);
            void testPop();
        }
        void testPop() {
            QVERIFY(test->pop() == testNumberArray+2);
            QVERIFY(test->pop() == testNumberArray+1);
            QVERIFY(test->pop() == testNumberArray);
            QVERIFY(test->size() == 0 );
        }
        void testGetTop() {
            test = new ArrayStack;
            test->push(testNumberArray+2);
            QVERIFY(test->getTop() == testNumberArray+2);
        }
        void TestCorrectInfix() {
           test = new ArrayStack;
           char inPut[]="1+1";
           char outPut[]="11+";
           char *res = test->infix(inPut);
           int length = strlen(outPut);
           for (int i =0; i< length; i++)
               QCOMPARE(char(res[i]), outPut[i]);
           void TestCorrectCalc();
        }
        void TestCorrectCalc() {
            int resultTest = 2;
            char inPut[]="11+";
            QVERIFY(test->calculateStack(inPut) == resultTest);
        }


};
