#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "tree.h"

class TestTree: public QObject
{
    Q_OBJECT
public:
    explicit TestTree(QObject *parent = 0) : QObject(parent) {}
private slots:
    void testCalculate() {
        Tree *mom = new Tree;
        mom->value = '*';
        Tree *son = new Tree;
        son->value = 2;
        Tree *daughter = new Tree;
        daughter->value = 3;

        mom->left = son;
        mom->right = daughter;
        daughter->parent = mom;
        son->parent = mom;

        mom->calculate();
        QVERIFY(mom->value == 6);
        delete mom;
    }
};
