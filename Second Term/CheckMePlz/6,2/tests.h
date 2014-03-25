#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "uniqueList.h"

int const testNumber = 1;
int const testAmount = 100;

/**
@brief tests add, delete, all raport with task requies
*/
class TestUniqueList: public QObject
{
    Q_OBJECT
public:
    explicit TestUniqueList(QObject *parent = 0) : QObject(parent) {}
private:

    UniqueList *test;

private slots:
    void testAddOne() {
        test = new UniqueList;
        test->push(testNumber);
        QVERIFY(test->begin-> value == testNumber);
        delete test;
    }
    void testAddHard() {
        test = new UniqueList;
        for (int i = 0; i < testAmount; i++) {
            test->push(testNumber + i);
        }
        int counter = 0;
        while (test->begin) {
            QVERIFY(test->begin-> value == testNumber + counter);
            test->begin = test->begin->next;
            counter++;
        }
        delete test;
    }
    void testUniqueAdd() {
        test = new UniqueList;
        test->push(testNumber);
        test->push(testNumber);
        QVERIFY(test->begin-> value == testNumber);
        QVERIFY(test->begin->next == NULL);
        delete test;
    }
    void testRemove() {
        test = new UniqueList;
        test->push(testNumber + 1);
        test->push(testNumber + 2);
        test->push(testNumber + 3);

        test->remove(testNumber + 2);
        QVERIFY(test->begin->value == testNumber + 1);
        QVERIFY(test->begin->next->value == testNumber + 3);

        test->remove(testNumber + 3);
        QVERIFY(test->begin->value == testNumber + 1);

        test->remove(testNumber + 1);
        QVERIFY(test->begin == NULL);
        delete test;
    }
    void testRemoveHard() {
        test = new UniqueList;
        for (int i = 0; i < testAmount; i++) {
            test->push(testNumber + i);
        }
        for (int i = testAmount - 1; i >= 0; i--)
            test->remove(testNumber + i);
        QVERIFY(test->begin == NULL);
        delete test;
    }

    void testRemoveException() {
        test = new UniqueList;
        test->push(testNumber + 1);
        test->remove(testNumber + 2);
        QVERIFY(test->begin->value == testNumber + 1);
        delete test;
    }
};
