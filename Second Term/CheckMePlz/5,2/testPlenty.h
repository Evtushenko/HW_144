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
    void testEndAddingOne() {
        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);
        QVERIFY(test->arrayElements[0]->value == testNumber);
        delete test;
    }
    void testEndAddingThree() {
        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        QVERIFY(test->arrayElements[0]->value == testNumber);
        QVERIFY(test->arrayElements[0]->next->value == testNumber + 1);
        QVERIFY(test->arrayElements[0]->next->next->value == testNumber + 2);
        delete test;
    }
    void testEndAddingMulti() {
        test = new Plenty<int, testingAmount>;
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

        delete test;
    }
    void testSearchAlongListOne() {
        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        QVERIFY(test->findElements(testNumber + 1)->value == testNumber + 1);
        QVERIFY(test->findElements(testNumber + 3) == NULL);
        delete test;
    }

    void testSearchAlongListThree() {
        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        QVERIFY(test->findElements(testNumber)->value == testNumber);
        QVERIFY(test->findElements(testNumber + 1)->value == testNumber + 1);
        QVERIFY(test->findElements(testNumber + 2)->value == testNumber + 2);
        QVERIFY(test->findElements(testNumber + 3) == NULL);
        delete test;
    }

    void testRemoveOne() {
        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);
        test->deleteE(test->findElements(testNumber + 1));
        QVERIFY(test->arrayElements[0]->value == testNumber);
        QVERIFY(test->arrayElements[0]->next->value == testNumber + 2);
        delete test;
    }

    void testRemoveThree(){
        test = new Plenty<int, testingAmount>;
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
        delete test;
    }

    void testIntegrateSimple() {
        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);

        test->currentPositionArray = 2;
        test->addEnd(testNumber + 3);

        test->intergrate();

        QVERIFY(test->arrayElements[testingAmount - 1]->value == testNumber);
        QVERIFY(test->arrayElements[testingAmount - 1]->next->value == testNumber + 3);
        delete test;
    }

    void testCrossSimple() {

        test = new Plenty<int, testingAmount>;
        test->addEnd(testNumber);
        test->addEnd(testNumber + 1);
        test->addEnd(testNumber + 2);

        for (int i = 1; i < testingAmount -1 ; i++) {
            test->currentPositionArray = i;
            test->addEnd(testNumber + 1);
        }

        test->cross();

        QVERIFY(test->arrayElements[testingAmount - 1]->value == testNumber + 1);
        delete test;

    }

};
