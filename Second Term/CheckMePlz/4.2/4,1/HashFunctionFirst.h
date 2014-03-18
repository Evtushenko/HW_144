#include "HashFunction.h"
/**
@brief first hash fucntion = personal class
*/
class HashFunctionFirst :
    public HashFunction
{
public:
    /**
    @brief example function : returns length*1;
    @param text from Hash Interface Class
    */
    int calcHash(char* text);
    HashFunctionFirst(void);
    ~HashFunctionFirst(void);
};

