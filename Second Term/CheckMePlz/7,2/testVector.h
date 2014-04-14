#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include <iostream>
#include "vector.h"

using namespace std;

int const testNumber = 3;
/**
@brief test Vector
*/
class TestVector: public QObject
{
    Q_OBJECT
public:
    explicit TestVector(QObject *parent = 0) : QObject(parent) {}
private:
    int *arrayV;
private slots:
    void init() {
        arrayV = new int[testNumber];
        for (int i = 0 ; i < testNumber; i++)
            arrayV[i] = i;
    }

    void correctCreation() {
        MyVector<int> *test = new MyVector<int> (arrayV, testNumber);
        for (int i = 0 ; i < testNumber; i++)
            QCOMPARE(test->arrayVector[i], arrayV[i]);
        delete test;
    }
    void correctCopy() {
        MyVector<int> b(arrayV, testNumber);
        MyVector<int> a(b);
        for (int i = 0 ; i < testNumber; i++)
            QCOMPARE(a.arrayVector[i], arrayV[i]);
    }

    void correctIncrease() {
        MyVector<int> b(arrayV, testNumber);
        MyVector<int> d(arrayV, testNumber);
        d += b;
        QCOMPARE(d.arrayVector[0], 0);
        QCOMPARE(d.arrayVector[1], 2);
        QCOMPARE(d.arrayVector[2], 4);
    }

    void correctDecrease() {
        MyVector<int> b(arrayV, testNumber);
        MyVector<int> d(arrayV, testNumber);
        d -= b;
        QCOMPARE(d.arrayVector[0], 0);
        QCOMPARE(d.arrayVector[1], 0);
        QCOMPARE(d.arrayVector[2], 0);
    }

    void correctMultiplication() {
        MyVector<int> b(arrayV, testNumber);
        MyVector<int> d(arrayV, testNumber);
        int waitingResult = 5;
        QCOMPARE(d * b, waitingResult );
    }

    void exceptionDimension() {
        bool ok[3] = {false, false, false};
        MyVector<int> b(arrayV, testNumber);
        MyVector<int> d(arrayV, testNumber+1);
        try {
            b += d;
        }
        catch(ExceptionDimension a) {
            ok[0] = true;
        }
        try {
            b -= d;
        }
        catch(ExceptionDimension a) {
            ok[1] = true;
        }
        try {
            b * d;
        }
        catch(ExceptionDimension a) {
            ok[2] = true;
        }
        QVERIFY(ok[0]);
        QVERIFY(ok[1]);
        QVERIFY(ok[2]);

    }
    void exceptionZero() {
        bool ok[3] = {false, false, false};
        int *arrayV2 = new int[testNumber];
        for (int i = 0 ; i < testNumber; i++)
            arrayV2[i] = 0;

        MyVector<int> b(arrayV, testNumber);
        MyVector<int> d(arrayV2, testNumber);

        try {
            b += d;
        }
        catch(ExceptionZero a) {
            ok[0] = true;
        }
        try {
            b -= d;
        }
        catch(ExceptionZero a) {
            ok[1] = true;
        }
        try {
            b * d;
        }
        catch(ExceptionZero a) {
            ok[2] = true;
        }
        QVERIFY(ok[0]);
        QVERIFY(ok[1]);
        QVERIFY(ok[2]);
    }
    void cleanup() {
        delete[] arrayV;
    }
};
