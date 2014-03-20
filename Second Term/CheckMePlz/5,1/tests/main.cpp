#include <QCoreApplication>
#include "TreeMaker.h"
#include "TestTree.h"
#include "TestTreeMaker.h"

int main() {
    TestTree test1;
    QTest::qExec(&test1);

    TestTreeMaker test2;
    QTest::qExec(&test2);
    //TreeMaker a;
    //a.readFile("input.txt");
    //a.buildTree();
    //std::cout << a.getResult() << std::endl;

    return 0;
}
