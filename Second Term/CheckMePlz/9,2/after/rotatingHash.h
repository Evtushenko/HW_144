#pragma once
#include "hashing.h"

/*! \class RotatingHash
 * contains modified hash described by Knuth
*/
class RotatingHash : public Hashing{
public:
    //RotatingHash () {}
    int hashFunction(char *string) {
        int hash = *string++;
        int ch = 0;
        while (ch == *string++)
            hash = (hash << 5) ^ (hash >> 27) ^ ch;
        return abs(hash % 20399);
    }
};
