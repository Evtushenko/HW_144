#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "plenty.h"

int const testingAmount = 10;

class TestPlenty: public QObject
{
    Q_OBJECT
public:
    explicit TestPlenty(QObject *parent = 0) : QObject(parent) {}
private:

    int const testNumber = 1;
    Plenty<int, testingAmount> *test;
private slots:
    void init() {
        test = new Plenty<int, testingAmount>;
    }
    void cleanup() {
        delete test;
    }

    void testEndAddingOne() {
        test->addEnd(testNumber);
        QVERIFY(test->arrayElements[0]->value == testNumber);

    }
    void testEndAddingThree() {
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        QVERIFY(test->arrayElements[0]->value == testNumber);
        QVERIFY(test->arrayElements[0]->next->value == testNumber + 1);
        QVERIFY(test->arrayElements[0]->next->next->value == testNumber + 2);
    }
    void testEndAddingMulti() {
        test->currentPositionArray = 0;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);

        test->currentPositionArray = 1;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);

        test->currentPositionArray = 2;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);

        QVERIFY(test->arrayElements[0]->value == testNumber);
        QVERIFY(test->arrayElements[0]->next->value == testNumber + 1);
        QVERIFY(test->arrayElements[0]->next->next->value == testNumber + 2);

        QVERIFY(test->arrayElements[1]->value == testNumber);
        QVERIFY(test->arrayElements[1]->next->value == testNumber + 1);
        QVERIFY(test->arrayElements[1]->next->next->value == testNumber + 2);

        QVERIFY(test->arrayElements[2]->value == testNumber);
        QVERIFY(test->arrayElements[2]->next->value == testNumber + 1);
        QVERIFY(test->arrayElements[2]->next->next->value == testNumber + 2);
    }
    void testSearchAlongListOne() {
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        QVERIFY(test->findElements(testNumber + 1)->value == testNumber + 1);
        QVERIFY(test->findElements(testNumber + 3) == NULL);
    }

    void testSearchAlongListThree() {
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        QVERIFY(test->findElements(testNumber)->value == testNumber);
        QVERIFY(test->findElements(testNumber + 1)->value == testNumber + 1);
        QVERIFY(test->findElements(testNumber + 2)->value == testNumber + 2);
        QVERIFY(test->findElements(testNumber + 3) == NULL);
    }

    void testRemoveOne() {
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        test->deleteE(test->findElements(testNumber + 1));
        QVERIFY(test->arrayElements[0]->value == testNumber);
        QVERIFY(test->arrayElements[0]->next->value == testNumber + 2);
    }

    void testRemoveThree(){
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        test->deleteE(test->findElements(testNumber + 1));
        QVERIFY(test->arrayElements[0]->value == testNumber);
        QVERIFY(test->arrayElements[0]->next->value == testNumber + 2);

        test->deleteE(test->findElements(testNumber));
        QVERIFY(test->arrayElements[0]->value == testNumber + 2);

        test->deleteE(test->findElements(testNumber + 2));
        QVERIFY(test->arrayElements[0] == NULL);
    }

    void testIntegrateSimple() {
        test->addEnd(testNumber);

        test->currentPositionArray = 2;
        test->addEnd(testNumber + 3);

        test->intergrate();

        QVERIFY(test->arrayElements[testingAmount - 1]->value == testNumber);
        QVERIFY(test->arrayElements[testingAmount - 1]->next->value == testNumber + 3);
    }

    void testCrossSimple() {
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);

        for (int i = 1; i < testingAmount -1 ; i++) {
            test->currentPositionArray = i;
            test->addEnd(testNumber + 1);
        }

        test->cross();

        QVERIFY(test->arrayElements[testingAmount - 1]->value == testNumber + 1);
    }

};
