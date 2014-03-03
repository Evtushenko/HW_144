#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>

int const lengthString = 5;
int const lengthColumn = 5;

struct ListColumns {
public:
ListColumns* next;
int elementsOfColumn[lengthColumn];
friend bool operator<(const ListColumns &first, const ListColumns &second);
};

class Sorter {
public:
	Sorter();
	~Sorter();
	void printMatrix() const;
	void sortStupid();
	int readFile();
	void TransferToMatrix();
protected:
	int matrix[lengthString][lengthColumn];
	void change(ListColumns* one, ListColumns* two);
	ListColumns *beginListColumns;
	ListColumns *endListColumns;
	
};
