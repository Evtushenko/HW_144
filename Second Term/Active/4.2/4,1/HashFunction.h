#pragma once
#include <string.h>
#include <math.h>

/**
@brief amount elements witch can be keep in the range of HashTable
*/
int const amountElements = 1000;

/**
@brief parent class for calc hash functions
*/
class HashFunction
{
public:
    /**
    @brief has 2 realisations
    */
    virtual int calcHash(char* text) = 0;
};

