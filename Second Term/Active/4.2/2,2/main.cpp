#include "testFile.h"
#include "testConsole.h"

using namespace std;

enum Change {Cprint, Fprint};

Change intToChange(int one) {
    return static_cast<Change>(one);
}

int main() {
    TestConsole testConsole;
    QTest::qExec(&testConsole);
    TestFile testFile;
    QTest::qExec(&testFile);

    /*
    cout << "Welcome to Spiral print!" << endl << "Choose the number of state" << endl;
    cout << "1 = console print" << endl;
    cout << "2 = File print" << endl;
        cout << "Enter number of state" << endl;
        int changeTemp = 0;
        Change c;
        cin >> changeTemp;

        if (!((changeTemp >= 1) && (changeTemp <= 2))) {
            cout << "Wrong command!" << endl;
            return 0;
        }

        c = intToChange(changeTemp);

        if ( c == Cprint+1) {
            PrintSpiral* pointer = new Console();
            pointer->outPrint();
            delete pointer;
        }
        if ( c == Fprint+1) {
            PrintSpiral* pointer = new File();
            pointer->outPrint();
            delete pointer;
        }
        */
    return 0;

}
