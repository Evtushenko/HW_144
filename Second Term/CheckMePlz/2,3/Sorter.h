#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>

int const lengthString = 5;

/**
@brief stores elements of each column from matrix
@param int array of elements of column, uniq operator comparing (>)
*/
struct ListColumns {
public:

	int elementsOfColumn[lengthString];

	/**
	@brief enables comparing elements of ListCoumn structure. 
	@param two pointer to elements of ListColumns
	*/
	friend bool operator>(const ListColumns &first, const ListColumns &second);
};


/**
@brief main class
@detailed has common functions and variables for its chindren
@param int array of elements of column, uniq operator comparing (>)
*/
class Sorter {
public:
	/**
	@brief constructor
	*/
	Sorter();

	/**
	@brief destructor
	*/
	~Sorter();

	/**
	@brief virtual interface fuction sorting 
	@detailed has two uniq realizations in CC.
	*/
	virtual void sorting() = 0;
protected:
	/**
	@brief array of matrix's columns
	*/
	ListColumns *arrayColumns[lengthString];

	/**
	@brief current number of matrix's column
	*/
	int currentNumber;

	/**
	@brief stores elements form matrix.txt
	*/
	int matrix[lengthString][lengthString];

	/**
	@brief replacing elements from two colums of matrix
	@param two pointers to columns
	*/
	void change(ListColumns* one, ListColumns* two);

	/**
	@brief printing inPut matrix and transported  inPut matrix
	*/
	void printMatrix() const;

	/**
	@brief reading from matrix.txt
	*/
	int readFile();

	/**
	@brief transporting maxtrix
	*/
	void TransferToMatrix();
};
