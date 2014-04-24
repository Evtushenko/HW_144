#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "bagKeeper.h"
#include "bag.h"
#include <iostream>
int const testNumber = 10;

/**
@brief tests copy, assign, delete
*/
class BagKeeperTest: public QObject
{
    Q_OBJECT
public:
    explicit BagKeeperTest(QObject *parent = 0) : QObject(parent) {}
private:
    BagKeeper<Bag> *test;
private slots:
    void init(){
        test = new BagKeeper<Bag>();
    }

    void correctComparingBagClass() {
        char one []= "myBag";
        char two []= "BigBag";
        Bag a(one);
        Bag b(two);
        Bag c(one);
        QVERIFY(a < b);
        QVERIFY(b > a);
        QVERIFY(a == c);
        QVERIFY( !(a == b) );
    }

    void addOne() {
        char text1[] = "myBag";
        Bag a(text1);
        test->add(a);
        int l = strlen(text1);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->key->text()[i],text1[i]);
    }

    void addThreeSimple() {
        char text1[] = "qw";
        Bag a(text1);
        char text2[] = "q";
        Bag b(text2);
        char text3[] = "qwe";
        Bag c(text3);
        test->add(a);
        test->add(b);
        test->add(c);
        int l = strlen(text1);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->key->text()[i],text1[i]);
        l = strlen(text2);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->left->key->text()[i],text2[i]);
        l = strlen(text3);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->right->key->text()[i],text3[i]);
    }

    void addThreeBalanced() {
        char text1[] = "q";
        Bag a(text1);
        char text2[] = "qw";
        Bag b(text2);
        char text3[] = "qwe";
        Bag c(text3);
        test->add(a);
        test->add(b);
        test->add(c);
        int l = strlen(text2);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->key->text()[i],text2[i]);
        l = strlen(text1);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->left->key->text()[i],text1[i]);
        l = strlen(text3);
        for (int i = 0; i < l; i++)
            QCOMPARE(test->root->right->key->text()[i],text3[i]);
    }

    void addThreeSame() {
        char text1[] = "q";
        Bag a(text1);
        test->add(a);
        test->add(a);
        test->add(a);
        int l = strlen(text1);
        for (int i = 0; i < l; i++) {
            QCOMPARE(test->root->key->text()[i],text1[i]);
            QCOMPARE(test->root->left->key->text()[i],text1[i]);
            QCOMPARE(test->root->right->key->text()[i],text1[i]);
        }
    }

    void deleteOne() {
        char text1[] = "myBag";
        Bag a(text1);
        test->add(a);
        test->del(a);
        QVERIFY(test->root == NULL);
    }

    void deleteTopOfThree() {
        char text1[] = "q";
        Bag a(text1);
        char text2[] = "qw";
        Bag b(text2);
        char text3[] = "qwe";
        Bag c(text3);
        test->add(a);
        test->add(b);
        test->add(c);
        test->del(b);
        QCOMPARE(test->root->key->text(), text3);
        QCOMPARE(test->root->left->key->text(), text1);
    }


    void deleteThree() {
        char text1[] = "q";
        Bag a(text1);
        char text2[] = "qw";
        Bag b(text2);
        char text3[] = "qwe";
        Bag c(text3);
        test->add(a);
        test->add(b);
        test->add(c);

        test->del(a);
        test->del(b);
        test->del(c);

        QVERIFY(test->root == NULL);
    }

    void deleteThreeSame() {
        char text1[] = "q";
        Bag a(text1);

        test->add(a);
        test->add(a);
        test->add(a);

        test->del(a);
        test->del(a);
        test->del(a);

        QVERIFY(test->root == NULL);
    }

    void deleteNotExist() {
        char text1[] = "q";
        Bag a(text1);
        char text2[] = "qw";
        Bag b(text2);
        test->add(a);
        test->del(b);
        QCOMPARE(test->root->key->text(), text1);
    }


    void searchSameTest() {
        char text1[] = "q";
        Bag a(text1);
        Bag b(text1);
        Bag c(text1);
        test->add(a);
        test->add(b);
        test->add(c);
        QVERIFY(test->find(a) == 3);
    }

    void searchThree() {
        char text1[] = "q";
        Bag a(text1);
        char text2[] = "qw";
        Bag b(text2);
        char text3[] = "qwe";
        Bag c(text3);
        test->add(a);
        test->add(b);
        test->add(c);
        QVERIFY(test->find(a) == 1);
        QVERIFY(test->find(b) == 1);
        QVERIFY(test->find(c) == 1);
    }

    void cleanup() {
        delete test;
    }

};
