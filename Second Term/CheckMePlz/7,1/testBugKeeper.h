#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "bugKeeper.h"
#include "bug.h"
#include <iostream>
int const testNumber = 10;
/**
@brief tests copy, assign, delete
*/
class BugKeeperTest: public QObject
{
    Q_OBJECT
public:
    explicit BugKeeperTest(QObject *parent = 0) : QObject(parent) {}
private:
    BugKeeper<Bug> *test;
private slots:
    void init(){
        test = new BugKeeper<Bug>();
    }
    void correctComparingBugClass() {
        char one []= "myBug";
        char two []= "BigBug";
        Bug a(one);
        Bug b(two);
        Bug c(one);
        QVERIFY(a < b);
        QVERIFY(b > a);
        QVERIFY(a == c);
        QVERIFY( !(a == b) );
    }

    void addOne() {
        char text1[] = "myBug";
        Bug a(text1);
        test->root = test->insert(test->root,a);
        QVERIFY(test->root->key->text() == text1);

    }
    void addThreeSimple() {
        char text1[] = "qw";
        Bug a(text1);
        char text2[] = "q";
        Bug b(text2);
        char text3[] = "qwe";
        Bug c(text3);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,b);
        test->root = test->insert(test->root,c);
        QVERIFY(test->root->key->text() == text1);
        QVERIFY(test->root->left->key->text() == text2);
        QVERIFY(test->root->right->key->text() == text3);
    }

    void addThreeBalanced() {
        char text1[] = "q";
        Bug a(text1);
        char text2[] = "qw";
        Bug b(text2);
        char text3[] = "qwe";
        Bug c(text3);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,b);
        test->root = test->insert(test->root,c);
        QVERIFY(test->root->key->text() == text2);
        QVERIFY(test->root->left->key->text() == text1);
        QVERIFY(test->root->right->key->text() == text3);
    }
    void addThreeSame() {
        char text1[] = "q";
        Bug a(text1);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,a);
        QVERIFY(test->root->key->text() == text1);
        QVERIFY(test->root->left->key->text() == text1);
        QVERIFY(test->root->right->key->text() == text1);
    }

    void deleteOne() {
        char text1[] = "myBug";
        Bug a(text1);
        test->root = test->insert(test->root,a);
        test->root = test->remove(test->root, a);
        QVERIFY(test->root == NULL);
    }

    void deleteTopOfThree() {
        char text1[] = "q";
        Bug a(text1);
        char text2[] = "qw";
        Bug b(text2);
        char text3[] = "qwe";
        Bug c(text3);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,b);
        test->root = test->insert(test->root,c);
        test->root = test->remove(test->root, b);
        QCOMPARE(test->root->key->text(), text3);
        QCOMPARE(test->root->left->key->text(), text1);
    }

    void deleteThree() {
        char text1[] = "q";
        Bug a(text1);
        char text2[] = "qw";
        Bug b(text2);
        char text3[] = "qwe";
        Bug c(text3);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,b);
        test->root = test->insert(test->root,c);

        test->root = test->remove(test->root,a);
        test->root = test->remove(test->root,b);
        test->root = test->remove(test->root,c);

        QVERIFY(test->root == NULL);
    }

    void deleteThreeSame() {
        char text1[] = "q";
        Bug a(text1);

        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,a);

        test->root = test->remove(test->root,a);
        test->root = test->remove(test->root,a);
        test->root = test->remove(test->root,a);

        QVERIFY(test->root == NULL);
    }

    void deleteNotExist() {
        char text1[] = "q";
        Bug a(text1);
        char text2[] = "qw";
        Bug b(text2);
        test->root = test->insert(test->root,a);
        test->root = test->remove(test->root,b);
        QVERIFY(test->root->key->text() == text1);
    }


    void searchSameTest() {
        char text1[] = "q";
        Bug a(text1);
        Bug b(text1);
        Bug c(text1);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,b);
        test->root = test->insert(test->root,c);
        QVERIFY(test->searchBinary(test->root, a) == 3);
    }

    void searchThree() {
        char text1[] = "q";
        Bug a(text1);
        char text2[] = "qw";
        Bug b(text2);
        char text3[] = "qwe";
        Bug c(text3);
        test->root = test->insert(test->root,a);
        test->root = test->insert(test->root,b);
        test->root = test->insert(test->root,c);
        QVERIFY(test->searchBinary(test->root, a) == 1);
        test->resultSearching = 0;
        QVERIFY(test->searchBinary(test->root, b) == 1);
        test->resultSearching = 0;
        QVERIFY(test->searchBinary(test->root, c) == 1);
    }

    void cleanup() {
        delete test;
    }
};
