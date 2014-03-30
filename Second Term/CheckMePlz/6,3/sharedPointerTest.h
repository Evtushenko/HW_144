#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "sharedPoint.h"

int const testNumber = 1;
/**
@brief tests copy, assign, delete
*/
class SharedPointerTest: public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}
private:
    SharedPoint<int> *test;
private slots:
        void init() {
            test = new SharedPoint<int>(new int(testNumber));
        }
        void testCorrectCopy() {
            SharedPoint<int> *slot = new SharedPoint<int>(*test);
            QVERIFY(*(test->pointStorage->pointerFromStorage) == testNumber);
            QVERIFY(*(slot->pointStorage->pointerFromStorage) == testNumber);
            QVERIFY(test->pointStorage->amount == 2);
            delete slot;
        }

        void testCorrectAssignment() {
            SharedPoint<int> tmp(new int(testNumber * 2));
            *test = tmp;
            QCOMPARE(tmp.pointStorage->pointerFromStorage, test->pointStorage->pointerFromStorage);
            QVERIFY(tmp.pointStorage->amount == 2);
            QVERIFY(test->pointStorage->amount == 2);
        }
        void testCorrectDelete() {
            SharedPoint<int> tmp(*test);
            int amount = tmp.pointStorage->amount;
            delete test;
            QVERIFY(tmp.pointStorage->amount == amount - 1);
        }

        void cleanup() {
            delete test;
        }
};
