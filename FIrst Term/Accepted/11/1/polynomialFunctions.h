#pragma once

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <fstream>

namespace fuctionsPolynomial {
	enum Change { exitProgramm, equalPQ, calc, sum, show };

	struct Expression{
		Expression *next;
		int coefficient;
		int exponent;
	};

	void addSort(Expression **beginNode, Expression **endNode, int coefficient, int exponent);
	bool equals(Expression *&beginFirst, Expression *& beginSecond);
	double value(Expression *&begin, int number);
	bool changeCoefficients(Expression *&beginFirst, Expression *&second);
	void makePQR(Expression **beginFirst, Expression **endFirst, Expression *&beginSecond);
	void print(Expression *&begin1);
	void freeMemory(Expression *&begin1, Expression *&begin2);
	Change intToChange(int one);
}