#include "floatFunctions.h"

using namespace std;


bool fuctionsFloat::isSign(char a) {
	return (a == '+' || a == '-' || a == '*' || a == '/');
}

bool fuctionsFloat::isDigit(char a) {
	return (a >= '0' && a <= '9');
}

bool fuctionsFloat::isEnd(char a) {
	return a == '\0';
}

bool fuctionsFloat::isExp(char a) {
	return a == 'E' || a == 'e';
}

bool fuctionsFloat::isDot(char a) {
	return a == '.';
}

bool fuctionsFloat::checkFloat(char str []) {
	cout << "process:" << endl;
	enum State { firstPart1, firstPart2, firstPart3, firstPart4, secondPart1, secondPart2, secondPart3 }
	state = firstPart1;
	while (true) {
		char c = *(str++);
		switch (state) {
		case firstPart1:
			if (isSign(c)) {
				cout << "found out sign " << c << endl;
				state = firstPart2;
			}
			else if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = firstPart3;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case firstPart2:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = firstPart3;
			}
			else {
				return false;
				cout << "found out wrong char \n";
			}
			break;

		case firstPart3:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = firstPart3;
			}
			else if (isDot(c)) {
				cout << "found out dot .\n";
				state = firstPart4;
			}
			else if (isExp(c)) {
				cout << "found out exponent " << c << endl;
				state = secondPart1;
			}
			else if (isEnd(c))  {
				cout << "found out end\n";
				return true;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case firstPart4:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = firstPart4;
			}
			else if (isExp(c)) {
				cout << "found out exponent " << c << endl;
				state = secondPart1;
			}
			else if (isEnd(c)) {
				cout << "found out end\n";
				return true;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case secondPart1:
			if (isSign(c)) {
				cout << "found out sign " << c << endl;
				state = secondPart2;
			}
			else if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = secondPart3;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case secondPart2:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = secondPart3;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case secondPart3:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = firstPart3;
			}
			else 
				if (isEnd(c)) {
					cout << "found out end\n";
					return true;
				}
				else {
					cout << "found out wrong char \n";
					return false;
				}
			break;
			return false;
		}
	}
}
