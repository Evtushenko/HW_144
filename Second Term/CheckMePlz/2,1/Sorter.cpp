#include "Sorter.h"

using namespace std;

Sorter::Sorter() {
}

Sorter::~Sorter() {
}

void Sorter::swap(int &first, int &second) {
	int tmp = first;
	first = second;
	second = tmp;
}

void Sorter::readKeybord() {
	cout << "enter the elements(default amount = 5)\n";
	for (int i = 0 ; i < amountElements; i++)
		cin >> arrayElements[i];
}

void Sorter::print() const {
	cout << "list of elements:\n";
	for (int i = 0 ; i < amountElements; i++)
		cout << arrayElements[i] << endl;
}
