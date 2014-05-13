#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "interpreter.h"


class Test: public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}
private:
    Interpreter *test;
private slots:
    void addStack() {
        char nameFile[] = "test.txt";
        test = new Interpreter(nameFile);
        test->pushStack(1);
        test->pushStack(2);
        QCOMPARE(test->popStack(),2);
        QCOMPARE(test->popStack(),1);
    }

    void popStack() {
        char nameFile[] = "test.txt";
        test = new Interpreter(nameFile);
        test->pushStack(1);
        test->pushStack(2);
        test->pushStack(3);
        test->pushStack(4);
        QCOMPARE(test->popStack(), 4);
        QCOMPARE(test->popStack(), 3);
        QCOMPARE(test->popStack(), 2);
        QCOMPARE(test->popStack(), 1);
    }

    void getInt() {
        char nameFile[] = "getInt.txt";
        test = new Interpreter(nameFile);
        QCOMPARE(test->getInt(0, 3),1488);
    }

    void getPoint() {
        char nameFile[] = "getPoint.txt";
        test = new Interpreter(nameFile);
        QCOMPARE(test->getPoint(0,4), "target");

    }



    void findPoint() {
        char nameFile[] = "findPoint.txt";
        test = new Interpreter(nameFile);
        char name1[] = "one";
        char name2[] = "two";
        char name3[] = "three";
        char name4[] = "four";
        QCOMPARE(test->findPoint(name1), 5);
        QCOMPARE(test->findPoint(name2), 11);
        QCOMPARE(test->findPoint(name3), 15);
        QCOMPARE(test->findPoint(name4), -1);
    }

    void st() {
        char nameFile[] = "st.txt";
        test = new Interpreter(nameFile);
        test->pushStack(4);
        test->pushStack(3);
        test->pushStack(2);
        test->pushStack(1);
        //test->printStack();
        test->execute();
        QCOMPARE(test->Memory[1], 2);
        QCOMPARE(test->Memory[36],1);
        QCOMPARE(test->Memory[228],3);
        QCOMPARE(test->Memory[999],4);
    }

    void ldc() {
        char nameFile[] = "ldc.txt";
        test = new Interpreter(nameFile);
        test->execute();
        QCOMPARE(test->popStack(), 4444);
        QCOMPARE(test->popStack(), 333);
        QCOMPARE(test->popStack(), 22);
        QCOMPARE(test->popStack(), 1);
    }

    void ld() {
        char nameFile[] = "ld.txt";
        test = new Interpreter(nameFile);
        test->Memory[1] = 1;
        test->Memory[22] = 2;
        test->Memory[333] = 3;
        test->execute();
        QCOMPARE(test->popStack(), 3);
        QCOMPARE(test->popStack(), 2);
        QCOMPARE(test->popStack(), 1);
    }

    void add() {
        char nameFile[] = "add.txt";
        test = new Interpreter(nameFile);
        test->pushStack(2);
        test->pushStack(1);
        test->execute();
        QCOMPARE(test->popStack(), 3);
    }
    void abs() {
        char nameFile[] = "abs.txt";
        test = new Interpreter(nameFile);
        test->pushStack(-2);
        test->execute();
        QCOMPARE(test->popStack(), 2);
    }

    void mul() {
        char nameFile[] = "mul.txt";
        test = new Interpreter(nameFile);
        test->pushStack(-2);
        test->pushStack(-2);
        test->execute();
        QCOMPARE(test->popStack(), 4);
    }

    void div() {
        char nameFile[] = "div.txt";
        test = new Interpreter(nameFile);
        test->pushStack(2);
        test->pushStack(-3);
        test->execute();
        QCOMPARE(test->popStack(), -1);
    }

    void sub() {
        char nameFile[] = "sub.txt";
        test = new Interpreter(nameFile);
        test->pushStack(1);
        test->pushStack(12);
        test->execute();
        QCOMPARE(test->popStack(), 11);
    }

    void mod() {
        char nameFile[] = "mod.txt";
        test = new Interpreter(nameFile);
        test->pushStack(2);
        test->pushStack(3);
        test->execute();
        QCOMPARE(test->popStack(), 1);
    }

    void cmp() {
        char nameFile[] = "cmp.txt";
        test = new Interpreter(nameFile);
        test->pushStack(1);
        test->pushStack(1);
        test->execute();
        QCOMPARE(test->popStack(), 0);

        delete test;
        test = new Interpreter(nameFile);
        test->pushStack(2);
        test->pushStack(1);
        test->execute();
        QCOMPARE(test->popStack(), -1);

        delete test;
        test = new Interpreter(nameFile);
        test->pushStack(1);
        test->pushStack(2);
        test->execute();
        QCOMPARE(test->popStack(), 1);
    }

    void jmp() {
        char nameFile[] = "jmp.txt";
        test = new Interpreter(nameFile);
        test->execute();
        QCOMPARE(test->currentString, 14);
    }

    void jz() {
        char nameFile[] = "jz.txt";
        test = new Interpreter(nameFile);
        test->pushStack(0);
        test->execute();
        QCOMPARE(test->currentString, 16);

    }

    void jnz() {
        char nameFile[] = "jnz.txt";
        test = new Interpreter(nameFile);
        test->pushStack(54);
        test->execute();
        QCOMPARE(test->currentString, 16);
    }

    void jg() {
        char nameFile[] = "jg.txt";
        test = new Interpreter(nameFile);
        test->pushStack(54);
        test->execute();
        QCOMPARE(test->currentString, 16);
    }

    void jl() {
        char nameFile[] = "jl.txt";
        test = new Interpreter(nameFile);
        test->pushStack(-54);
        test->execute();
        QCOMPARE(test->currentString, 16);
    }

    void std() {
        char nameFile[] = "std.txt";
        test = new Interpreter(nameFile);
        test->pushStack(-54);
        test->execute();
        QVERIFY(!test->top);
    }

    void NOD() {
        char nameFile[] = "nod.txt";
        test = new Interpreter(nameFile);
        test->execute();
        QVERIFY(test->Memory[3] == 6);
    }

    void NOK() {
        char nameFile[] = "nok.txt";
        test = new Interpreter(nameFile);
        test->execute();
        QVERIFY(test->Memory[3] == 42);
    }

    void PRIME() {
        char nameFile[] = "prime.txt";
        test = new Interpreter(nameFile);
        test->execute();
        QVERIFY(test->Memory[3] == 557);
    }

    void FIB() {
        char nameFile[] = "fib.txt";
        test = new Interpreter(nameFile);
        test->execute();
        QVERIFY(test->Memory[2] == 1346269);
    }

    void cleanup() {
        delete test;
    }
};
