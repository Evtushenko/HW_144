#include "testBugKeeper.h"

using namespace std;

//добавить чистку памяти
//написать ГРАМОТНЫЕ комментарии
// вынести класс Node отедльно

int main() {
    BugKeeperTest test;
    QTest::qExec(&test);
}
