#include "HashFunctionSecond.h"


HashFunctionSecond::HashFunctionSecond(void)
{
}


HashFunctionSecond::~HashFunctionSecond(void)
{
}

int HashFunctionSecond::calcHash(char* text){
    return strlen(text)*2;
}
