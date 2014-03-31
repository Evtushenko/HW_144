#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "queueTest.h"

int main() {
    QueueTest test1;
    QTest::qExec(&test1);
return 0;
}
