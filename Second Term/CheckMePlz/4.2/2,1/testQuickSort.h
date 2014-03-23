#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "quickSort.h"

class TestQuickSort: public QObject
{
    Q_OBJECT
public:
    explicit TestQuickSort(QObject *parent = 0) : QObject(parent) {}
private:
    QuickSort *test;
private slots:

    void testCorrectInput() {
        test = new QuickSort;
        int testElementsOuput[] = {1, 2, 3, 4, 5};
        std::cout << "enter 1 2 3 4 5" << std::endl;
        test->readKeybord();
        int *result = test->returnArray();
        for (int i = 0 ; i < amountElements; i++) {
            QCOMPARE(result[i], testElementsOuput[i]);
        }
        delete test;
    }
        void testSorting(){
            test = new QuickSort;
            int testElementsInput[] = {3, 4, 2, 5, 1};
            int testElementsOuput[] = {1, 2, 3, 4, 5};
            test->fillArray(testElementsInput);
            test->sorting();
            int *result = test->returnArray();
            for (int i = 0 ; i < amountElements; i++) {
                QCOMPARE(result[i], testElementsOuput[i]);
            }
            delete test;
        }
};
