#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "arrayStack.h"

int const testNumberArray = 1;

class TestArrayStack: public QObject
{
    Q_OBJECT
public:
    explicit TestArrayStack(QObject *parent = 0) : QObject(parent) {}
private:
    ArrayStack *test;
private slots:
        void testCorrectCreation() {
           test = new ArrayStack;
           QVERIFY(test->size() == 0);
           delete test;
        }
        void testPushOne() {
            test = new ArrayStack;
            test->push(testNumberArray);
            QVERIFY(test->size() == 1);
            delete test;
        }
        void testPushFour() {
            test = new ArrayStack;
            test->push(testNumberArray);
            test->push(testNumberArray + 1);
            test->push(testNumberArray + 2);
            test->push(testNumberArray + 3);
            QVERIFY(test->size() == 4);
            delete test;
        }
        void testPushHard() {
            test = new ArrayStack;
            int amountElementsTested = 100;
            for (int i = 0; i < amountElementsTested; i++ )
                test->push(i);
            QVERIFY(test->size() ==  amountElementsTested);
            delete test;
        }
        void testPopOne() {
            test = new ArrayStack;
            test->push(testNumberArray);
            QVERIFY(test->pop() == testNumberArray);
            QVERIFY(test->size() == 0 );
            delete test;
        }
        void testPopFour() {
            test = new ArrayStack;
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
            test = new ArrayStack;
            int amountElementsTested = 100;
            for (int i = 0; i < amountElementsTested; i++ )
                test->push(i);
            for (int i = amountElementsTested-1; i >= 0; i--)
                QVERIFY(test->pop() == i);
            QVERIFY(test->size() == 0 );
            delete test;
        }
        void testGetTop() {
            test = new ArrayStack;
            test->push(testNumberArray + 2);
            QVERIFY(test->getTop() == testNumberArray + 2);
            delete test;
        }
        void testCorrectInfix() {
           test = new ArrayStack;
           char inPut[]="1+1";
           char outPut[]="11+";
           char *res = test->infix(inPut);
           int length = strlen(outPut);
           for (int i = 0; i < length; i++)
               QCOMPARE(char(res[i]), outPut[i]);
           delete test;
        }
        void testCorrectCalc() {
            test = new ArrayStack;
            int resultTest = 2;
            char inPut[] = "11+";
            QVERIFY(test->calculateStack(inPut) == resultTest);
            delete test;
        }


};
