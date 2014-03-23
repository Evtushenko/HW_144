
#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "pointList.h"

class TestPointList: public QObject
{
    Q_OBJECT
public:
    explicit TestPointList(QObject *parent = 0) : QObject(parent) {}
private:
    PointList *test;
    int const testNumberArray = 1;
private slots:
            void testCorrectCreation() {
               test = new PointList;
               QVERIFY(test->size() == 0);
               delete test;
            }
            void testPushOne() {
                test = new PointList;
                test->push(testNumberArray);
                QVERIFY(test->size() == 1);
                delete test;
            }
            void testPushFour() {
                test = new PointList;
                test->push(testNumberArray);
                test->push(testNumberArray + 1);
                test->push(testNumberArray + 2);
                test->push(testNumberArray + 3);
                QVERIFY(test->size() == 4);
                delete test;
            }
            void testPushHard() {
                test = new PointList;
                int amountElementsTested = 100;
                for (int i = 0; i < amountElementsTested; i++ )
                    test->push(i);
                QVERIFY(test->size() ==  amountElementsTested);
                delete test;
            }
            void testPopOne() {
                test = new PointList;
                test->push(testNumberArray);
                QVERIFY(test->pop() == testNumberArray);
                QVERIFY(test->size() == 0 );
                delete test;
            }
            void testPopFour() {
                test = new PointList;
                test->push(testNumberArray);
                test->push(testNumberArray + 1);
                test->push(testNumberArray + 2);
                test->push(testNumberArray + 3);
                QVERIFY(test->pop() == testNumberArray);
                QVERIFY(test->pop() == testNumberArray + 1);
                QVERIFY(test->pop() == testNumberArray + 2);
                QVERIFY(test->pop() == testNumberArray + 3);
                QVERIFY(test->size() == 0 );
                delete test;
            }
            void testPopHard() {
                test = new PointList;
                int amountElementsTested = 100;
                for (int i = 0; i < amountElementsTested; i++ )
                    test->push(i);
                for (int i = 0; i < amountElementsTested; i++)
                    QVERIFY(test->pop() == i);
                QVERIFY(test->size() == 0 );
                delete test;
            }
};
