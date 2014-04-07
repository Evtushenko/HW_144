#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "sharedPointer.h"

int const testNumber = 10;
/**
@brief tests copy, assign, delete
*/
class SharedPointerTest: public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}
private:
    SharedPointer<int> *test;
private slots:
    void creationWithoutPointer() {
        test = new SharedPointer<int>();
        QVERIFY(*(test->amount) == 0);
        delete test;
    }
    void creationWithPointer() {
        test = new SharedPointer<int>(new int(testNumber));
        QVERIFY(*(test->amount) == 1);
        QVERIFY(*(test->pointer) == testNumber);
        delete test;
    }
    void creationCopy() {
        test = new SharedPointer<int>(new int(testNumber));
        SharedPointer<int> one(*test);
        QCOMPARE(*test->amount, *one.amount);
        QCOMPARE(*test->pointer, *one.pointer);
        QVERIFY(*one.amount == 2);
        QVERIFY(*one.pointer == testNumber);
        delete test;
    }
    void deleting() {
        test = new SharedPointer<int>(new int(testNumber));
        SharedPointer<int> slot(*test);
        int slotAmount = *(slot.amount);
        delete test;
        QVERIFY(*(slot.amount) == slotAmount - 1);
    }
    void testAssign() {
        test = new SharedPointer<int>(new int(testNumber+2));
        SharedPointer<int> one(new int(testNumber));
        *test = one;
        QCOMPARE(test->pointer, one.pointer);
        QVERIFY(*test->amount == 2);
        delete test;
    }
};
