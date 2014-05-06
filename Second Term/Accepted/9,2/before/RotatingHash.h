#pragma once
#include "hashing.h"

/*! \class RotatingHash
 * contains modified hash described by Knuth
*/
class RotatingHash : public Hashing{
public:
    int hashFunction(char *string);
};
