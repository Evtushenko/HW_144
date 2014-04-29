#pragma once

int const sizeTable = 20400;

/*! \class Hashing
 * this virtual class includes just one method for counting hash
*/
class Hashing {
public:
    /*! \fn hashFunction
     * returns hash of input string
    */
    virtual int hashFunction(char* string) = 0;
    virtual ~Hashing() = 0;
protected:
    int const amountCells = 20400;
};


