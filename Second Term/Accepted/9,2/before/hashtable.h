#pragma once
#include "hashing.h"
#include "TableCell.h"

class Hashtable{
public:
	Hashtable(Hashing* typeOfHash);
	void addElement(char* string);
	bool findElement(char* string);
	bool removeElement(char* string);
	void changeHash(Hashing* typeOfHash);
	void showStatistic();

	/*! \var hashHelper
	 * contains actual hash function of Table
	*/
	/*! \var previousHashHelper
	 * contains previous hash function of Table
	*/
	/*! \fn getMaxSize
	 * returns max size of Cells
	*/
	int hash(char* string);
	Hashing*  hashHelper;
	Hashing*  previousHashHelper;
	TableCell<char*>* Table;
	static int const sizeTable = 20400;
	int occupiedCells;
	double loadFactor;
	int numberOfConflicts;
	int getMaxSize();

};
