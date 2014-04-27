#pragma once
#include "hashing.h"

/*! \class hash31
 * this class contains just one method for counting polynomial hash
*/
class hash31 : public Hashing {
public:
    //hash31() {}
    int hashFunction(char *string) {
    int hash = *string++;
    int c;
    while (c = *string++)
        hash = (((hash << 5) - hash) + c) % 20399;
    return hash;
    }
};
