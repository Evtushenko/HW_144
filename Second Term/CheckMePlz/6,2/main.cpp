//#pragma one
//#include "uniqueList.h"
#include "tests.h"

using namespace std;

enum Change { exitProgramm, add1, pop1, show1};

Change intToChange(int one) {
    return static_cast<Change>(one);
}

int main() {
    TestUniqueList test1;
    QTest::qExec(&test1);

    cout << "Welcome!" << endl << "Enter the number of state" << endl;
    cout << "0 = exit" << endl;
    cout << "1 = add to Point Stack" << endl;
    cout << "2 = pop from Point Stack" << endl;
    cout << "3 = show Point Stack" << endl;

    UniqueList *bubble = new UniqueList();
    int buffer = 0;

    for (;;) {
        cout << "Enter number of state" << endl;
        int changeTemp = 0;
        Change c;
        cin >> changeTemp;

        if (!((changeTemp >= 0) && (changeTemp <= 3))) {
            cout << "Wrong command!" << endl;
            return 0;
        }

        c = intToChange(changeTemp);

        if (c == exitProgramm) {
            delete bubble;
            cout << "L.A.Goodbay" << endl;
            break;
        }
        if ( c == add1) {
            cout << "enter value\n";
            cin >> buffer;
            bubble->push(buffer);
        }
        if ( c == pop1) {
            cout << "enter value\n";
            cin >> buffer;
            bubble->remove(buffer);
        }
        if (c == show1) {
            bubble->print();
        }
    }
    return 0;

}
