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
        void init() {
            test = new ArrayStack;
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
            for (int i = amountElementsTested-1; i >= 0; i--)
                QVERIFY(test->pop() == i);
            QVERIFY(test->size() == 0 );
        }
        void testGetTop() {
            test->push(testNumberArray + 2);
            QVERIFY(test->getTop() == testNumberArray + 2);
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
