#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "queue.h"


class QueueTest: public QObject
{
    Q_OBJECT
public:
    explicit QueueTest(QObject *parent = 0) : QObject(parent) {}
private:
    Queue<int> *test;
private slots:
    void init() {
        test = new Queue<int>;
    }
    void correctAddingOne() {
        test->enqueue(1,2);
        QVERIFY(test->beginQueue->value == 1 && test->beginQueue->priory == 2  );
    }
    void correctAddingBegin() {
        test->enqueue(1,2);
        test->enqueue(3,3);
        QVERIFY(test->beginQueue->value == 3 && test->beginQueue->priory == 3  );
        QVERIFY(test->beginQueue->next->value == 1 && test->beginQueue->next->priory == 2  );
    }

    void correctAddingEnd() {
        test->enqueue(1,2);
        test->enqueue(5,1);
        QVERIFY(test->beginQueue->value == 1 && test->beginQueue->priory == 2);
        QVERIFY(test->beginQueue->next->value == 5 && test->beginQueue->next->priory == 1);
    }

    void correctAddingMiddle() {
        test->enqueue(3,5);
        test->enqueue(1,2);
        test->enqueue(4,4);
        QVERIFY(test->beginQueue->value == 3 && test->beginQueue->priory == 5  );
        QVERIFY(test->beginQueue->next->value == 4 && test->beginQueue->next->priory == 4);
        QVERIFY(test->beginQueue->next->next->value == 1 && test->beginQueue->next->next->priory == 2);
    }

    void correctPop() {
        test->enqueue(1,2);
        QVERIFY(test->dequeue() == 1);
    }

    void correctPopTwo() {
        test->enqueue(1,2);
        test->enqueue(5,3);
        QVERIFY(test->dequeue() == 5);
        QVERIFY(test->dequeue() == 1);
    }

    void correctBugFinder() {
        bool ok = false;
        try {
            test->dequeue();
        }
        catch(ExceptionEmpty) {
        ok = true;
        }
        QVERIFY(ok);
    }
    void cleanup() {
        delete test;
    }
};
