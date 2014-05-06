#ifndef HASHTABLETEST_H
#define HASHTABLETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "CRC32Hash.h"
#include "rotatingHash.h"
#include <iostream> //
#include "hash31.h"

using namespace std;


class hashtableTest : public QObject
{
    Q_OBJECT
public:
    explicit hashtableTest(QObject *parent = 0) : QObject(parent){}
private:
    Hashtable* table;
    Hashing* polynomialHash;
    Hashing* crcHash;
    Hashing* rotateHash;
    char *testWord1;
    char *testWord2;
private slots:
    void init(){
        crcHash = new CRC32Hash;
        polynomialHash = new Hash31;
        rotateHash = new RotatingHash;
        char f[] = "abdefttr";
        char g[] = "hi";
        testWord1 = f;
        testWord2 = g;
        table = new Hashtable(polynomialHash);
    }

    void cleanup(){
        delete crcHash;
        delete polynomialHash;
        delete rotateHash;
        delete table;
    }

    void testAddingAllTypes() {

        table->addElement(testWord1);
        table->addElement(testWord2);
        QVERIFY(table->findElement(testWord1));
        QVERIFY(table->findElement(testWord2));

        delete table;

        table = new Hashtable(crcHash);
        table->addElement(testWord1);
        table->addElement(testWord2);
        QVERIFY(table->findElement(testWord1));
        QVERIFY(table->findElement(testWord2));
        delete table;

        table = new Hashtable(rotateHash);
        table->addElement(testWord1);
        table->addElement(testWord2);
        QVERIFY(table->findElement(testWord1));
        QVERIFY(table->findElement(testWord2));
    }

    void testAddingList() {
        char a[] = "a";
        char b[] = "b";
        char c[] = "c";
        // if len == 1  this hashFunction return 0
        table->addElement(a);
        table->addElement(b);
        table->addElement(c);
        QVERIFY(table->findElement(a));
        QVERIFY(table->findElement(b));
        QVERIFY(table->findElement(c));
    }

    void testDeletingListMid() {
        char a[] = "a";
        char b[] = "b";
        char c[] = "c";
        // if len == 1  this hashFunction return 0
        table->addElement(a);
        table->addElement(b);
        table->addElement(c);
        table->removeElement(b);
        QVERIFY(table->findElement(a));
        QVERIFY(!table->findElement(b));
        QVERIFY(table->findElement(c));
    }

    void testDeletingListTop() {
        char a[] = "a";
        char b[] = "b";
        // if len == 1  this hashFunction return 0
        table->addElement(a);
        table->addElement(b);
        table->removeElement(a);
        QVERIFY(!table->findElement(a));
        QVERIFY(table->findElement(b));
    }

    void testDeletingListDown() {
        char a[] = "a";
        char b[] = "b";
        // if len == 1  this hashFunction return 0
        table->addElement(a);
        table->addElement(b);
        table->removeElement(b);
        QVERIFY(table->findElement(a));
        QVERIFY(!table->findElement(b));
    }

    void testSearchingAllTypes() {
        table->addElement(testWord1);
        QVERIFY(table->findElement(testWord1));
        QVERIFY(!table->findElement(testWord2));
        delete table;

        table = new Hashtable(crcHash);
        table->addElement(testWord1);
        QVERIFY(table->findElement(testWord1));
        QVERIFY(!table->findElement(testWord2));
        delete table;

        table = new Hashtable(rotateHash);
        table->addElement(testWord1);
        QVERIFY(table->findElement(testWord1));
        QVERIFY(!table->findElement(testWord2));
    }
    void testSearchingHard() {
        char a[] = "a";
        char b[] = "b";
        char c[] = "c";
        // if len == 1  this hashFunction return 0
        table->addElement(a);
        table->addElement(b);
        table->addElement(c);
        char d[] ="ddd";
        table->addElement(d);
        QVERIFY(table->findElement(a));
        QVERIFY(table->findElement(b));
        QVERIFY(table->findElement(c));
        QVERIFY(table->findElement(d));
    }
    void testSwitchHash() {
        char a[] = "a";
        table->addElement(a);
        table->changeHash(crcHash);
        QVERIFY(!table->findElement(a));
        table->changeHash(polynomialHash);
        QVERIFY(table->findElement(a));
    }
};

#endif // HASHTABLETEST_H
