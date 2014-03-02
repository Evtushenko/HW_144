#pragma once
#include <iostream>
#include <cstdlib>

int const amountElements = 5;

class Sorter {
public:
	virtual void sorting() = 0;
	void print() const;
	void readKeybord();
protected:
	int arrayElements[amountElements];
	void swap(int &first, int &second);
};
