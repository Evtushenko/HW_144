#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;


enum Change { exitProgramm, equalPQ, calc, sum, show};

Change intToChange(int one) {
	return static_cast<Change>(one);
}

struct Expression{
	Expression *next;
	int coefficient;
	int exponent;
};

void addSort(Expression **beginNode, Expression **endNode, int coefficient, int exponent){
	Expression *end = *endNode;
	Expression *newNode = new Expression;
	newNode->coefficient = coefficient;
	newNode->exponent = exponent;
	Expression *currentNode = *beginNode;
	if (*beginNode == nullptr) {
		newNode->next = nullptr;
		*beginNode = newNode;
		*endNode = *beginNode;
	}
	else{

		// если элемент меньше первого, то он будет новым первым//
		if (exponent < currentNode->exponent) {
			newNode->next = currentNode;
			*beginNode = newNode;
			if (currentNode == *endNode) {
				*endNode = currentNode;
			}
		}
		else {
			// Если новый больше первого //
			bool found = false; // результат поиска фолс //
			while (currentNode->next) {
				if ((currentNode->next)->exponent > newNode->exponent) {
					found = true;
					break;
				}
				// currentNode - предыдущий , а currentNode->next больше чем newNode //
				currentNode = currentNode->next;
			}
			if (found) {
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				if (currentNode->next == end) {
					*endNode = currentNode->next;
				}
			}
		}
		if ((*endNode)->exponent <= exponent) {
			newNode->exponent = exponent;
			newNode->next = nullptr;
			(*endNode)->next = newNode;
			*endNode = newNode;
		}
	}
}

bool equals(Expression *&beginFirst, Expression *& beginSecond) {
	Expression *start1 = beginFirst;
	Expression *start2 = beginSecond;
	while (start1) {
		if (start1->exponent != start2->exponent || start1->coefficient != start2->coefficient)
			return false;
		start1 = start1->next;
		start2 = start2->next;
	}
	return true;
}

double value(Expression *&begin, int number) {
	double answer = 0.0;
	Expression *start = begin;
	while (start) {
		answer += double(start->coefficient)*double(pow(number, start->exponent));
		start = start->next;
	}
	return answer;
}

bool changeCoefficients(Expression *&beginFirst, Expression *&second){
	Expression *start = beginFirst;
	while (start) {
		if (start->exponent == second->exponent) {
			start->coefficient = start->coefficient + second->coefficient;
			return true;
		}
		start = start->next;
	}
	return false;
}

void makePQR(Expression **beginFirst, Expression **endFirst, Expression *&beginSecond) {
	Expression *start = beginSecond;
	while (start) {
		if (!changeCoefficients(*beginFirst, start)){
			addSort(&(*beginFirst), &(*endFirst), start->coefficient, start->exponent);
		}
		start = start->next;
	}
}

void print(Expression *&begin1) {
	Expression *begin = begin1;
	while (begin) {
		if (begin->coefficient > 0)
			cout << "+";
		if (abs(begin->coefficient) != 1 || begin->exponent == 0)
			cout << begin->coefficient;
		if (begin->exponent != 0) {
			cout << "x^(";
			cout << begin->exponent;
			cout << ")";
		}
		begin=begin->next;
	}
	cout << endl;
}

void freeMemory(Expression *&begin1, Expression *&begin2) {
	Expression *helper = begin1;
	while (begin1) {
		helper = begin1;
		begin1 = begin1->next;
		delete helper;
	}

	while (begin2) {
		helper = begin2;
		begin2 = begin2->next;
		delete helper;
	}
}

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
		addSort(&beginFirst, &endFirst, coef,exp);
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
			if (equals(beginFirst, beginSecond))
				cout << "equals\n";
			else
				cout << "not equals\n";
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