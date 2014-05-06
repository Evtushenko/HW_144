#pragma once
#include "tableCell.h"
#include "hashing.h"
#include <iostream>

using namespace std;

class Hashtable{
public:
    Hashtable (Hashing* typeOfHash):
        occupiedCells(0),
        numberOfConflicts(0),
        hashHelper(typeOfHash),
        table(new TableCell[sizeTable]) {}

    ~Hashtable() {
        delete[] table;
    }
    void addElement(char* string);
    bool findElement(char* string);
    bool removeElement(char* string);
    void changeHash(Hashing* typeOfHash)  {
        hashHelper = typeOfHash;
    }
    void showStatistic();
private:
    int getMaxSize();
    int occupiedCells;
    int numberOfConflicts;
    Hashing*  previousHashHelper;
    Hashing*  hashHelper;
    TableCell *table;
    int hash(char* string) {
        return hashHelper->hashFunction(string);
    }
};
