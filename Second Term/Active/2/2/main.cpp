#include "console.h"
#include "file.h"
#include "printSpiral.h"

using namespace std;

enum Change { exitProgramm, Cprint, Fprint};

Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {
	cout << "Welcome to Spiral print!" << endl << "Choose the number of state" << endl;
	cout << "0 = exit" << endl;
	cout << "1 = console print" << endl;
	cout << "2 = File print" << endl;
	for (;;) {
		cout << "Enter number of state" << endl;
		int changeTemp = 0;
		Change c;
		cin >> changeTemp;

		if (!((changeTemp >= 0) && (changeTemp <= 2))) {
			cout << "Wrong command!" << endl;
			return 0;
		}

		c = intToChange(changeTemp);

		if (c == exitProgramm) {
			cout << "L.A.Goodbay" << endl;
			break;
		}

		if ( c == Cprint) {
			PrintSpiral* pointer = new Console();
			pointer->readFromFile();
			pointer->print();
			pointer->spiralOrder(amountElements/2,amountElements/2);
			delete pointer;
		}
		if ( c == Fprint) {
			PrintSpiral* pointer = new File();
			pointer->readFromFile();
			pointer->print();
			pointer->spiralOrder(amountElements/2,amountElements/2);
			delete pointer;
		}
	}
	return 0;
}