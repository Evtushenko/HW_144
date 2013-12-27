#include "polynomialFunctions.h"

using namespace std;
using namespace fuctionsPolynomial;

int main() {
	cout << "using:\n 1.txt\n 2.txt\n";
	ifstream inFile;
	inFile.open("1.txt", ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	int amountStringsFirst = 0;
	inFile >> amountStringsFirst;
	Expression *beginFirst = nullptr;
	Expression *endFirst = nullptr;
	int coef = 0;
	int exp = 0;
	for (int i = 0; i < amountStringsFirst; i++) {
		inFile >> coef >> exp;
		addSort(&beginFirst, &endFirst, coef, exp);
	}
	inFile.close();

	inFile.open("2.txt", ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	int amountStringsSecond = 0;
	inFile >> amountStringsSecond;
	Expression *beginSecond = nullptr;
	Expression *endSecond = nullptr;
	coef = 0;
	exp = 0;
	for (int i = 0; i < amountStringsSecond; i++) {
		inFile >> coef >> exp;
		addSort(&beginSecond, &endSecond, coef, exp);
	}
	inFile.close();
	cout << "First:\n";
	print(beginFirst);
	cout << "Second:\n";
	print(beginSecond);
	cout << "\nWelcome!\n 0=exit\n 1=equals(p,q)\n 2=calc(p,x)\n 3=sum(p,q)(result's in p)\n 4=show\n\n";
	for (;;) {
		cout << "Enter number of state" << endl;
		int changeTemp = 0;
		Change c;
		cin >> changeTemp;
		c = intToChange(changeTemp);

		if (!((changeTemp >= 0) && (changeTemp <= 4))) {
			cout << "Wrong command!" << endl;
			return 0;
		}

		if (c == exitProgramm) {
			cout << "L.A. GoodBay!\n";
			break;
		}

		if (c == equalPQ) {
			if (equals(beginFirst, beginSecond)) {
				cout << "equals\n";
			}
			else {
				cout << "not equals\n";
			}
		}

		if (c == calc) {
			cout << "enter the number\n";
			int number = 0;
			cin >> number;
			cout << "result:\n";
			cout << value(beginFirst, number) << endl;
		}

		if (c == sum) {
			makePQR(&beginFirst, &endFirst, beginSecond);
			cout << "now p = p +q;\n";
		}

		if (c == show) {
			print(beginFirst);
		}
	}

	freeMemory(beginFirst, beginSecond);
	return 0;
}