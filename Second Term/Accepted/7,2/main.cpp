#include <QCoreApplication>
#include "testVector.h"

int main() {
    TestVector test1;
    QTest::qExec(&test1);
   return 0;
}

// конструктор копирования и тест на него, чтобы копии были независимы. Т.е изменения оригинала не трогали копию и наооборот
// комментарии
