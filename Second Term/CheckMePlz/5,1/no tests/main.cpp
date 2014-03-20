#include <QCoreApplication>
#include "TreeMaker.h"

int main() {
    TreeMaker a;
    a.readFile("input.txt");
    a.buildTree();
    std::cout << a.getResult() << std::endl;

    return 0;
}
