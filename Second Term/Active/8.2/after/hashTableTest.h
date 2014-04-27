#ifndef HASHTABLETEST_H
#define HASHTABLETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "CRC32Hash.h"
#include "rotatingHash.h"
#include "hash31.h"

class hashtableTest : public QObject
{
    Q_OBJECT
public:
    explicit hashtableTest(QObject *parent = 0) : QObject(parent){}
    
private slots:
    void initTestCase(){
        crcHash = new CRC32Hash;
        polynomialHash = new hash31;
        rotateHash = new RotatingHash;
    }

    void cleanupTestCase(){
        delete crcHash;
        delete polynomialHash;
        delete rotateHash;
    }

    void testRemoveElement(){
        table = new Hashtable(polynomialHash);
        QVERIFY(!table->removeElement("abc"));
        delete table;

        table = new Hashtable(crcHash);
        QVERIFY(!table->removeElement("abc"));
        delete table;

        table = new Hashtable(rotateHash);
        QVERIFY(!table->removeElement("abc"));
        delete table;
    }

    void testAddElement(){
        table = new Hashtable(polynomialHash);
        table->addElement("abdefttr");
        QVERIFY(!table->removeElement("abc"));
        QVERIFY(table->removeElement("abdefttr"));
        delete table;

        table = new Hashtable(crcHash);
        table->addElement("abdefttr");
        QVERIFY(!table->removeElement("abc"));
        QVERIFY(table->removeElement("abdefttr"));
        delete table;

        table = new Hashtable(rotateHash);
        table->addElement("abdefttr");
        QVERIFY(!table->removeElement("abc"));
        QVERIFY(table->removeElement("abdefttr"));
        delete table;

    }

    void testFindElement(){
        table = new Hashtable(polynomialHash);
        table->addElement("abdefttr31");
        QVERIFY(!table->findElement("ball"));
        QVERIFY(table->findElement("abdefttr31"));
        delete table;

        table = new Hashtable(crcHash);
        table->addElement("abdefttr31");
        QVERIFY(!table->findElement("ball"));
        QVERIFY(table->findElement("abdefttr31"));
        delete table;

        table = new Hashtable(rotateHash);
        table->addElement("abdefttr31");
        QVERIFY(!table->findElement("ball"));
        QVERIFY(table->findElement("abdefttr31"));
        delete table;

    }

private:
    Hashtable* table;
    Hashing* polynomialHash;
    Hashing* crcHash;
    Hashing* rotateHash;
    
};

#endif // HASHTABLETEST_H
