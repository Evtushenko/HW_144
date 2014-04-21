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
    void init() {
        test = new UniqueList;
    }
    void cleanup() {
        delete test;
    }

    void testAddOne() {
        test->pushUser(testNumber);
        QVERIFY(test->begin-> value == testNumber);
    }
    void testAddHard() {
        for (int i = 0; i < testAmount; i++) {
            test->pushUser(testNumber + i);
        }
        int counter = 0;
        while (test->begin) {
            QVERIFY(test->begin-> value == testNumber + counter);
            test->end = test->begin;
            test->begin = test->begin->next;
            delete test->end;
            counter++;
        }
    }
    void testRemoveUser() {
        test->pushUser(testNumber + 1);
        test->pushUser(testNumber + 2);
        test->pushUser(testNumber + 3);

        test->removeUser(testNumber + 2);
        QVERIFY(test->begin->value == testNumber + 1);
        QVERIFY(test->begin->next->value == testNumber + 3);

        test->removeUser(testNumber + 3);
        QVERIFY(test->begin->value == testNumber + 1);

        test->removeUser(testNumber + 1);
        QVERIFY(test->begin == NULL);
    }
    void testremoveUserHard() {
        for (int i = 0; i < testAmount; i++) {
            test->pushUser(testNumber + i);
        }
        for (int i = testAmount - 1; i >= 0; i--)
            test->removeUser(testNumber + i);
        QVERIFY(test->begin == NULL);
    }

    void testremoveUserException() {
        bool ok = false;
        test->pushUser(testNumber + 1);
        try {
            test->removeUser(testNumber + 2);
        }
        catch(ExceptionNotExists) {
            ok = true;
            QVERIFY(ok);
        }
    }
    void testUniqueAdd() {
        bool ok = false;
        test->pushUser(testNumber);
        try {
            test->pushUser(testNumber);
        }
        catch(ExceptionSame) {
            ok = true;
            QVERIFY(ok);
        }
    }
};
