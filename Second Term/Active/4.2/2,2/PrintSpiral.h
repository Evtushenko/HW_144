#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>

int const amountElements = 3;

/**
@brief Printing Sprirally.
@detailed Contains of 2 method which are chinldren(CC) of it.
For user only 1 fuction is enable. Has some functinons and variables for CC.
*/
class PrintSpiral {
public:

    /**
    @brief constructor
    @detailed indefy max distances default numbers.
    */
    PrintSpiral ();

    /**
    @brief destructor
    */
    virtual ~PrintSpiral() = 0;

    /**
    @brief virual printing out
    @detailed variety realization in CC.
    */
    virtual void outPrint() = 0;

    /**
    @brief reading form matrix.txt
    @detailed taking in matrix for working.
    */
    int readFromFile();

    /**
    @brief creating right order for queue for future printing
    @detailed stupid math principles
    */
    void spiralOrder();


    /**
    @brief for testing
    */
    int *returnMatrix();

    /**
    @brief for testing
    */
    int *returnSpiralOrder();

protected:

    /**
    @brief printing readed matrix
    */
    void printIn() const;

    /**
    @brief found out distance beetween 2 points of matrix
    @param 2 int Decart coordinate of one point
    */
    double dist(int Xa, int Ya) const;

    /**
    @brief input matrix
    @param size of square matrix
    */
    int matrix[amountElements][amountElements];

    /**
    @brief maximal distances from point to center of matrix
    @param size of square matrix
    */
    double  maxDistCentr[amountElements];

    /**
    @brief numbers that will be printing in chindren realization
    @param amount elements  of square matrix
    */
    int queuePrinting[amountElements*amountElements];
};
