#pragma once
#include "hashing.h"

/*! \class hash31
 * this class contains just one method for counting polynomial hash
*/
class hash31 : public Hashing {
public:
    int hashFunction(char *string);

};
