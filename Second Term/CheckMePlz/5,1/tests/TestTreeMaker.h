#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "TreeMaker.h"
#include "tree.h"

using namespace std;

class TestTreeMaker: public QObject
{
    Q_OBJECT
public:
    explicit TestTreeMaker(QObject *parent = 0) : QObject(parent) {}
private:
    TreeMaker *test;
private slots:
    void testReadingFile() {
        test = new TreeMaker;
        char nameFile[] = "test.txt";
        test->readFile(nameFile);
        char waitingText[]="(*(+11)2)";
        QCOMPARE(waitingText, test->inPutString);
        delete test;

    }

    void correctBuildTree() {

        test = new TreeMaker;
        char textInput[] = "(*(+11)2)";
        test->inPutString = textInput;
        test->buildTree();
        QVERIFY(test->root->value == '*');
        QVERIFY(test->root->left->value == '+');
        QVERIFY(test->root->right->value == 2);
        QVERIFY(test->root->left->left->value == 1);
        QVERIFY(test->root->left->right->value == 1);
        delete test;
    }
    void correctCalculating() {

        test = new TreeMaker;
        test->root = new Tree;
        test->currentPoint = test->root;
        test->root->value = '*';
        test->addLeft('+');
        test->addRight(2);
        test->currentPoint = test->currentPoint->left;
        test->addLeft(1);
        test->addRight(1);
        QVERIFY(test->getResult() == 4);
        delete test;
    }

};
