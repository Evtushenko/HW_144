#include "polynomialFunctions.h"

using fuctionsPolynomial::Change;
using fuctionsPolynomial::Expression;
using namespace std;


void fuctionsPolynomial::addSort(Expression **beginNode, Expression **endNode, int coefficient, int exponent) {
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

		// ���� ������� ������ �������, �� �� ����� ����� ������//
		if (exponent < currentNode->exponent) {
			newNode->next = currentNode;
			*beginNode = newNode;
			if (currentNode == *endNode) {
				*endNode = currentNode;
			}
		}
		else {
			// ���� ����� ������ ������� //
			bool found = false; // ��������� ������ ���� //
			while (currentNode->next) {
				if ((currentNode->next)->exponent > newNode->exponent) {
					found = true;
					break;
				}
				// currentNode - ���������� , � currentNode->next ������ ��� newNode //
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

bool fuctionsPolynomial::equals(Expression *&beginFirst, Expression *& beginSecond) {
	Expression *start1 = beginFirst;
	Expression *start2 = beginSecond;
	while (start1) {
		if (start1->exponent != start2->exponent || start1->coefficient != start2->coefficient) {
			return false;
		}
		start1 = start1->next;
		start2 = start2->next;
	}
	return true;
}

double fuctionsPolynomial::value(Expression *&begin, int number) {
	double answer = 0.0;
	Expression *start = begin;
	while (start) {
		answer += double(start->coefficient)*double(pow(number, start->exponent));
		start = start->next;
	}
	return answer;
}

bool fuctionsPolynomial::changeCoefficients(Expression *&beginFirst, Expression *&second){
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

void fuctionsPolynomial::makePQR(Expression **beginFirst, Expression **endFirst, Expression *&beginSecond) {
	Expression *start = beginSecond;
	while (start) {
		if (!changeCoefficients(*beginFirst, start)){
			addSort(&(*beginFirst), &(*endFirst), start->coefficient, start->exponent);
		}
		start = start->next;
	}
}

void fuctionsPolynomial::print(Expression *&begin1) {
	Expression *begin = begin1;
	while (begin) {
		if (begin->coefficient > 0) {
			cout << "+";
		}
		if (abs(begin->coefficient) != 1 || begin->exponent == 0) {
			cout << begin->coefficient;
		}
		if (begin->exponent != 0) {
			cout << "x^(";
			cout << begin->exponent;
			cout << ")";
		}
		begin = begin->next;
	}
	cout << endl;
}

void fuctionsPolynomial::freeMemory(Expression *&begin1, Expression *&begin2) {
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

Change fuctionsPolynomial::intToChange(int one) {
	return static_cast<Change>(one);
}
