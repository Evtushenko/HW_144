#include "TestHashInterface.h"

using namespace std;

enum StatesHashTable {exitProgram, add, search, del, change, details };
enum HashFunctions {zero, firstHF, secondHF};

int main() {
    TestHashInterface testHashInterface;
    QTest::qExec(&testHashInterface);
    /*
    HashInterface a;
    a.numberHF = 0;
    int state = -1;
    cout << "Welcome!\n";
    cout << "0 = exit\n";
    cout << "1 = add\n";
    cout << "2 = search\n";
    cout << "3 = delete\n";
    cout << "4 = switch fucntions\n";
    cout << "5 = print static\n";
    for (; state != exitProgram ;) {
        cout << "enter state: \n";
        cin >> state;
        if (state == add) {
            a.addHT();
        }
        if (state == search) {
            cout << "enter the string\n";
            char buffer[maxLengthWord];
            for (int i = 0; i < maxLengthWord; i++)
            buffer[i] = '\0';
            cin >> buffer;
            a.searchHT(buffer);
        }
        if (state == del) {
            cout << "enter the string\n";
            char buffer[maxLengthWord];
            for (int i = 0; i < maxLengthWord; i++)
            buffer[i] = '\0';
            cin >> buffer;
            a.deleteHT(buffer);
        }
        if (state == details) {
            a.staticHT();
        }
        if (state == change) {
            int stateSwitch = -1;
            cout << "Switch menu:\n";
            cout << "0 = exit from switch\n";
            cout << "1 = first hash fuction (set as default)\n";
            cout << "2 = second hash fuction\n";
            cin >> stateSwitch;
            if (stateSwitch == firstHF) {
                a.numberHF = 0;
            }
            if (stateSwitch == secondHF) {
                a.numberHF = 1;
            }

        }
    };
    cout << "L.A. Goodbay\n";
    */

    return 0;
}
