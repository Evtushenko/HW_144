#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "sharedPointerTest.h"

using namespace std;

int main()
{
    SharedPointerTest test;
    QTest::qExec(&test);
   return 0;
}
