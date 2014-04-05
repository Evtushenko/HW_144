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
        delete test;
    }
    void creationCopy() {
        SharedPointer<int> one(new int(testNumber));
        SharedPointer<int> * slot = new SharedPointer<int>(one);
        QVERIFY(*(slot->amount) == 2);
        QVERIFY(*(one.amount) == 2);
        delete slot;
    }
    void deleting() {

        test = new SharedPointer<int>(new int(testNumber));
        SharedPointer<int> * slot = new SharedPointer<int>(*test);
        int slotAmount = *(slot->amount);
        delete test;
        QVERIFY(*(slot->amount) == slotAmount - 1);
        delete slot;
    }
    void testAssign() {
        test = new SharedPointer<int>(new int(testNumber));
        SharedPointer<int> one(new int(testNumber));
        *test = one;
        QCOMPARE(test->pointer, one.pointer);
        QVERIFY(*test->amount == 2);
        delete test;
    }
};
