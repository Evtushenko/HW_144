#include "expressionFunction.h"

using namespace std;


bool expression::isSign(char a) {
	return (a == '+' || a == '-' || a == '*' || a == '/');
}

bool expression::isDigit(char a) {
	return (a >= '0' && a <= '9');
}

bool expression::isEnd(char a) {
	return a == '\0';
}

bool expression::isExp(char a) {
	return a == 'E' || a == 'e';
}

bool expression::isDot(char a) {
	return a == '.';
}

bool expression::checkFloat(char string [], int &position) {
	enum State { firstPart1, firstPart2, firstPart3, firstPart4, secondPart1, secondPart2, secondPart3 }
	state = firstPart1;
	int begin = position;
	bool stop = false;
	while (!isEnd(string[position]) && !stop) {
		char c = string[position++];
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
				stop = true;
			}
			break;

		case firstPart2:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = firstPart3;
			}
			else {
				stop = true;
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
				stop = true;
			}
			else {
				cout << "found out wrong char \n";
				stop = true;
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
				stop = true;
			}
			else {
				cout << "found out wrong char \n";
				stop = true;
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
				stop = true;
			}
			break;

		case secondPart2:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = secondPart3;
			}
			else {
				cout << "found out wrong char \n";
				stop = true;
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
					stop = true;
				}
				else {
					cout << "found out wrong char \n";
					stop = true;
				}
				break;
				stop = true;
		}
	}
	if (stop) {
		position--;
	}
	return (state == firstPart3 || state == firstPart4 || state == secondPart3);
}

bool expression::ruleT(int &position, char string []);
bool expression::ruleTouchE(int &position, char string []);
bool expression::ruleF(int &position, char string []);
bool expression::ruleTouchT(int &position, char string []);
bool expression::ruleE(int &position, char string []);

bool expression::isCorrect(int &position, char string []) {
	return (ruleE(position, string) && isEnd(string[position]));
}

bool expression::ruleE(int &position, char string []) {
	return (ruleT(position, string) && ruleTouchE(position, string));
}

bool expression::ruleTouchE(int &position, char string []) {
	if (string[position] != '+' && string[position] != '-') {
		return true;
	}
	position++;
	return (ruleT(position, string) && ruleTouchE(position, string));
}

bool expression::ruleT(int &position, char string []) {
	return (ruleF(position, string) && ruleTouchT(position, string));
}

bool expression::ruleTouchT(int &position, char string []) {
	if (string[position] != '*' && string[position] != '/') {
		return true;
	}
	position++;
	return (ruleF(position, string) && ruleTouchT(position, string));
}

bool expression::ruleF(int &position, char string []) {
	if (string[position] == '(') {
		position++;
		bool answer = ruleE(position, string);
		if (string[position] != ')') {
			return false;
		}
		position++;
		return answer;
	}
	return checkFloat(string, position);
}