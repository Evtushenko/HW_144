#include <QCoreApplication>
#include "queueTest.h"

// don't forget to make NULL all pointers then you delete something!!!!!!!!!!!

int main() {
    QueueTest test1;
    QTest::qExec(&test1);
return 0;
}
