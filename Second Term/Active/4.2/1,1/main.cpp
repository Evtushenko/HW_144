//#include <QCoreApplication>
//#include "ListGeneral.h"
#include <iostream>
#include "ArrayList.h"
#include "PointList.h"
#include "TestArrayList.h"
#include "TestPointList.h"

using namespace std;

enum Change { exitProgramm, add1, pop1, show1, add2, pop2, show2};

Change intToChange(int one) {
    return static_cast<Change>(one);
}

int main() {

    TestArrayList test1;
    QTest::qExec(&test1);
    TestPointList test2;
    QTest::qExec(&test2);
    /*

    cout << "Welcome!" << endl << "Enter the number of state" << endl;
    cout << "0 = exit" << endl;
    cout << "1 = add to Point Stack" << endl;
    cout << "2 = pop from Point Stack" << endl;
    cout << "3 = show Point Stack" << endl;
    cout << "4 = add to Array Stack" << endl;
    cout << "5 = pop from Array Stack" << endl;
    cout << "6 = show Array Stack" << endl;
    ListGeneral* bubble = new PointList();
    ListGeneral* bead = new ArrayList();
    int buffer = 0;

    for (;;) {
        cout << "Enter number of state" << endl;
        int changeTemp = 0;
        Change c;
        cin >> changeTemp;

        if (!((changeTemp >= 0) && (changeTemp <= 6))) {
            cout << "Wrong command!" << endl;
            return 0;
        }

        c = intToChange(changeTemp);

        if (c == exitProgramm) {
            delete bubble;
            delete bead;
            cout << "L.A.Goodbay" << endl;
            break;
        }
        if ( c == add1) {
            cout << "enter value\n";
            cin >> buffer;
            bubble->push(buffer);
        }
        if ( c == pop1) {
            bubble->pop();
        }
        if (c == show1) {
            bubble->print();
        }

        if ( c == add2) {
            cout << "enter value\n";
            cin >> buffer;
            bead->push(buffer);
        }
        if ( c == pop2) {
            bead->pop();
        }
        if (c == show2) {
            bead->print();
        }
    }
    */
    //return 0;
}
