#include "hash31.h"


int hash31::hashFunction(char* string){

    int hash = *string++;
    int c;
    while(c = *string++)
        hash = (((hash << 5) - hash) + c) % 20399;
    return hash;
}
