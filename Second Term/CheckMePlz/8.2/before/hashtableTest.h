#ifndef HASHTABLETEST_H
#define HASHTABLETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "CRC32Hash.h"
#include "RotatingHash.h"
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
        QCOMPARE(table->removeElement("abc"), false);
        delete table;

        table = new Hashtable(crcHash);
        QCOMPARE(table->removeElement("abc"), false);
        delete table;

        table = new Hashtable(rotateHash);
        QCOMPARE(table->removeElement("abc"), false);
        delete table;
    }

    void testAddElement(){
        table = new Hashtable(polynomialHash);
        table->addElement("abdefttr");
        QCOMPARE(table->removeElement("abc"), false);
        QCOMPARE(table->removeElement("abdefttr"), true);
        delete table;

        table = new Hashtable(crcHash);
        table->addElement("abdefttr");
        QCOMPARE(table->removeElement("abc"), false);
        QCOMPARE(table->removeElement("abdefttr"), true);
        delete table;

        table = new Hashtable(rotateHash);
        table->addElement("abdefttr");
        QCOMPARE(table->removeElement("abc"), false);
        QCOMPARE(table->removeElement("abdefttr"), true);
        delete table;

    }

    void testFindElement(){
        table = new Hashtable(polynomialHash);
        table->addElement("abdefttr31");
        QCOMPARE(table->findElement("ball"), false);
        QCOMPARE(table->findElement("abdefttr31"), true);
        delete table;

        table = new Hashtable(crcHash);
        table->addElement("abdefttr31");
        QCOMPARE(table->findElement("ball"), false);
        QCOMPARE(table->findElement("abdefttr31"), true);
        delete table;

        table = new Hashtable(rotateHash);
        table->addElement("abdefttr31");
        QCOMPARE(table->findElement("ball"), false);
        QCOMPARE(table->findElement("abdefttr31"), true);
        delete table;

    }

private:
    Hashtable* table;
    Hashing* polynomialHash;
    Hashing* crcHash;
    Hashing* rotateHash;
    
};

#endif // HASHTABLETEST_H
