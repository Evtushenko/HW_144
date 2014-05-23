#include "test.h"

int main() {
    Test test1;
    QTest::qExec(&test1);
    return 0;
}
