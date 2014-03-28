#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "plenty.h"
#include "testPlenty.h"

// комменты

using namespace std;

enum MainMenu {zeroMM, addMM, removeMM, searchMM, printMM, crossMM, integrateMM};

int main() {
    TestPlenty test1;
    QTest::qExec(&test1);
    /*
    Plenty<int, 10> intPlenty;
    cout << "menu\n";
    cout << "0 = exit\n";
    cout << "1 = add\n";
    cout << "2 = delete\n";
    cout << "3 = search\n";
    cout << "4 = print\n";
    cout << "5 = cross Lists\n";
    cout << "6 = integrate Lists\n";
    int state = -1;
    for (; state;) {
        cout << "enter global state\n";
        cin >> state;
        if (state == addMM)
            intPlenty.add();
        if (state == removeMM)
            intPlenty.remove();
        if (state == searchMM)
            intPlenty.itHere();
        if (state == printMM)
            intPlenty.print();
        if (state == crossMM) {
            intPlenty.cross();
            cout << "cross of elements of plenties:\n";
            intPlenty.printIntergate();
        }
        if (state == integrateMM) {
            intPlenty.intergrate();
            cout << "union of elements of plenties:\n";
            intPlenty.printIntergate();
        }

    }
    */
return 0;
}
