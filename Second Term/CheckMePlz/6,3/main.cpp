#include "testSharedPointer.h"

using namespace std;

int main() {
    SharedPointerTest test;
    QTest::qExec(&test);

    return 0;
}
