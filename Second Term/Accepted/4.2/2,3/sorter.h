#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <math.h>

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
    virtual ~Sorter() = 0;

    /**
    @brief virtual interface fuction sorting
    @detailed has two uniq realizations in CC.
    */
    virtual void sorting() = 0;

    /**
    @brief array of matrix's columns
    */
    ListColumns *arrayColumns[lengthString];

    /**
    @brief reading from matrix.txt
    */
    int readFile();


    /**
    @brief replacing elements from two colums of matrix
    @param two pointers to columns
    */
    void change(ListColumns* one, ListColumns* two);
protected:


    /**
    @brief current number of matrix's column
    */
    int currentNumber;

    /**
    @brief stores elements form matrix.txt
    */
    int matrix[lengthString][lengthString];


    /**
    @brief printing inPut matrix and transported  inPut matrix
    */
    void printMatrix() const;

    /**
    @brief transporting maxtrix
    */
    void TransferToMatrix();
};
