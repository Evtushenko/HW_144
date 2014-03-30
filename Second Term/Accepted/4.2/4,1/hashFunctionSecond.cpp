#include "hashFunctionSecond.h"


HashFunctionSecond::HashFunctionSecond(void)
{
}


HashFunctionSecond::~HashFunctionSecond(void)
{
}

int HashFunctionSecond::calcHash(char* text){
    int result = 0;
    int simpleNumber = 3;
    for (int i = 0 ; i < strlen(text); i++) {
        result += int(text[i])*pow(simpleNumber, i);
        result = result % amountElements;
    }
    return result;
}
