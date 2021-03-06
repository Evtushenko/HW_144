#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include <iostream>
#include "bubbleSort.h"

class TestBubbleSort: public QObject
{
    Q_OBJECT
public:
    explicit TestBubbleSort(QObject *parent = 0) : QObject(parent) {}
private:
    BubbleSort *test;
private slots:
    void init() {
        test = new BubbleSort;
    }
    void cleanup(){
        delete test;
    }
    void testCorrectInput() {
        int testElementsOuput[] = {1, 2, 3, 4, 5};
        std::cout << "enter 1 2 3 4 5" << std::endl;
        test->readKeybord();
        int *result = test->returnArray();
        for (int i = 0 ; i < amountElements; i++) {
            QCOMPARE(result[i], testElementsOuput[i]);
        }
    }

    void testSorting(){
        int testElementsInput[] = {3, 4, 2, 5, 1};
        int testElementsOuput[] = {1, 2, 3, 4, 5};
        test->fillArray(testElementsInput);
        test->sorting();
        int *result = test->returnArray();
        for (int i = 0 ; i < amountElements; i++) {
            QCOMPARE(result[i], testElementsOuput[i]);
        }
    }
};
