#pragma once
#include "hashing.h"

class CRC32Hash : public Hashing{
public:
    int hashFunction(char *string);
private:
    /*! \var binary
     * contains binary representations of all chars in input string
    */
    /*! \var max
     * it actually contains max size of input string (a little less 12500 symbols)
    */
    /*! \var Q
     * it is the generative polynom
    */
    static int const max = (int)1e5;
    static int const Q = (1<<26) | (1<<23) | (1<<22) | (1<<16) | (1<<12) | (1<<11) | (1<<10) | (1<<8) | (1<<7) | (1<<5) | (1<<4) | (1<<2) | (1<<1) | 1;
    int binary[max];
};

