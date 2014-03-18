#pragma once
#include <string.h>
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
    HashFunction(void);
    ~HashFunction(void);
};

