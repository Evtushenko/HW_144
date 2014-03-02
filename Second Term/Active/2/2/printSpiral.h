#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>

int const amountElements = 3;

class PrintSpiral {
public:
	PrintSpiral();
	int readFromFile();
	void print() const;
	virtual void spiralOrder(int Xc, int Yc) const = 0;
protected:
	float dist(int Xa, int Ya) const;
	int matrix[amountElements][amountElements];
	int mid;
	float  maxDistCentr[amountElements];
};
