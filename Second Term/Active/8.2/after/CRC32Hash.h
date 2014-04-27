#pragma once
#include "hashing.h"
#include <math.h>
#include <cstring>
#include <stdlib.h>

class CRC32Hash : public Hashing{
public:
    //CRC32Hash() {}
    int hashFunction(char *string) {
         memset(binary, 0, sizeof binary);
    int n = 32; //first 32 bits are null

    int ch = 0;

    while (ch = *string++){
        for (int i = 0; i < 8; i++)
            if ((ch >> i) & 1)
                binary[n++] = 1;
            else
                binary[n++] = 0;
    }

    int hash = 0;

    for (int i = n-1; i >=n-32; i--){ //take first essential 32 bit
        hash <<= 1;
        hash |= binary[i]; //on the free bit write binary[next]
    }

    for (int i = n-33; i >= 0; i--){
        int check = (hash >> 31) & 1;
        hash <<= 1;
        hash |= binary[i];

        if(check)
            hash ^= Q; //this is actually subtraction
    }

    return abs(hash % 20399);
    }
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

