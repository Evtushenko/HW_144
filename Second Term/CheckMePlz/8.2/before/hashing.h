#pragma once

/*! \class Hashing
 * this virtual class includes just one method for counting hash
*/
class Hashing{
public:
    /*! \fn hashFunction
     * returns hash of input string
    */
    virtual int hashFunction(char* string) = 0;


};
