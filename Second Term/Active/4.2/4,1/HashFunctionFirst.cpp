#include "hashFunctionFirst.h"


HashFunctionFirst::HashFunctionFirst(void)
{
}


HashFunctionFirst::~HashFunctionFirst(void)
{
}

int HashFunctionFirst::calcHash(char* text) {
    int result = 0;
    for (int i = 0 ; i < strlen(text); i++) {
        result += int(text[i])*i;
        result = result % amountElements;
    }
    return result;
}
