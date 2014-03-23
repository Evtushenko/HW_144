#include <QtTest/QTest>
#include <QtCore/QObject>
#include "bubbleSort.h"

using namespace std;

class TestBubbleSort: public QObject
{
    Q_OBJECT
public:
    explicit TestBubbleSort(QObject *parent = 0) : QObject(parent) {}
private:
    BubbleSort *test;
private slots:

    void testCorrectCompareStruct() {
        ListColumns *one = new ListColumns;
        ListColumns *two = new ListColumns;
        for (int i = 0; i < lengthString; i++) {
            one->elementsOfColumn[i] = rand() % 9;
            two->elementsOfColumn[i] = one->elementsOfColumn[i] + 1;
        }
        QVERIFY(*two > *one);
        delete one;
        delete two;
    }

    void testCorrectReading(){
        test = new BubbleSort;
        test->readFile();
        int *columns[lengthString];
        int one[] = {9, 4, 1, 3, 6};
        columns[0] = one;
        int two[] = {8, 6, 6, 4,9};
        columns[1] = two;
        int three[] = {4, 8, 3, 5, 7};
        columns[2] = three;
        int four[] = {7, 3, 8, 2, 5};
        columns[3] = four;
        int five[] = {5, 2, 8, 4, 4};
        columns[4] = five;
        for (int j = 0 ; j < lengthString; j++)
            for (int i = 0; i < lengthString; i++)
                QCOMPARE(test->arrayColumns[j]->elementsOfColumn[i],columns[j][i]);
        delete test;
    }

    void testCorrectSorting() {
        test = new BubbleSort;
        test->readFile();
        test->sorting();
        int *columns[lengthString];
        int one[] = {4, 8, 3, 5, 7};
        columns[0] = one;
        int two[] = {5, 2, 8, 4, 4};
        columns[1] = two;
        int three[] = {7, 3, 8, 2, 5};
        columns[2] = three;
        int four[] = {8, 6, 6, 4,9};
        columns[3] = four;
        int five[] = {9, 4, 1, 3, 6};
        columns[4] = five;
        for (int j = 0 ; j < lengthString; j++)
            for (int i = 0; i < lengthString; i++)
                QCOMPARE(test->arrayColumns[j]->elementsOfColumn[i],columns[j][i]);
        delete test;
    }

    void testCorrectSwap(){
        ListColumns *one = new ListColumns;
        ListColumns *two = new ListColumns;
        int *first = new int[lengthString];
        int *second = new int[lengthString];
        for (int i = 0; i < lengthString; i++) {
             one->elementsOfColumn[i] = i+1;
             two->elementsOfColumn[i] = i-1;
             first[i] =  one->elementsOfColumn[i];
             second[i] =  two->elementsOfColumn[i];
        }
        test->change(one,two);
        for (int i = 0; i < lengthString; i++) {
            QCOMPARE(one->elementsOfColumn[i],second[i]);
            QCOMPARE(two->elementsOfColumn[i],first[i]);
        }
        delete one;
        delete two;
        delete[] first;
        delete[] second;
    }
};
