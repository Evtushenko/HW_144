#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "bubble.cpp"
#include "human.h"

/**
@brief test for bubble sort
*/
class Test: public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:
    void intTest() {
        Comparater<int> test;
        int mas[] = {5,4,3,2,1};
        bubbleSort(mas, 5, test);
        for (int i = 0; i < 5; i++) {
            QCOMPARE(mas[i], i + 1);
        }
    }
    void charTest() {
        Comparater<char> test2;
        char mas2[] = {'m','d','a','z','f'};
        bubbleSort(mas2, 5, test2);
        QCOMPARE(mas2[0], 'z');
        QCOMPARE(mas2[1], 'm');
        QCOMPARE(mas2[2], 'f');
        QCOMPARE(mas2[3], 'd');
        QCOMPARE(mas2[4], 'a');
    }
    void HumanTest() {
        Human a(1,2);
        Human b(3,4);
        Human ar[] = {a,b};
        Comparater<Human> test3;
        bubbleSort(ar, 2, test3);
        QVERIFY(ar[0].age == 3 && ar[0].power == 4);
        QVERIFY(ar[1].age == 1 && ar[1].power == 2);
    }
};
