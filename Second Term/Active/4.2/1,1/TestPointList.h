
#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "PointList.h"

class TestPointList: public QObject
{
    Q_OBJECT
public:
    explicit TestPointList(QObject *parent = 0) : QObject(parent) {}
private:
    PointList *test;
private slots:
    void testCorrectCreation() {
       test = new PointList;
       QVERIFY(test->size() == 0);
    }
    void testPush() {
        test = new PointList;
        int testNumber = 1;
        test->push(testNumber);
        test->push(testNumber + 1);
        test->push(testNumber + 2);
        QVERIFY(test->size() == 3);
    }
    void testPop() {
        test = new PointList;
        int testNumber = 1;
        test->push(testNumber);
        test->push(testNumber + 1);
        test->push(testNumber + 2);
        QVERIFY(test->pop() == testNumber);
        QVERIFY(test->pop() == testNumber + 1);
        QVERIFY(test->pop() == testNumber + 2);
        QVERIFY(test->size() == 0 );
    }
};
