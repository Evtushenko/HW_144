#include "HashFunctionFirst.h"


HashFunctionFirst::HashFunctionFirst(void)
{
}


HashFunctionFirst::~HashFunctionFirst(void)
{
}

int HashFunctionFirst::calcHash(char* text){
    return strlen(text)*1;
}
