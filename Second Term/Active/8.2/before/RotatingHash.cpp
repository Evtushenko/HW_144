#include "RotatingHash.h"
#include <stdlib.h>

int RotatingHash::hashFunction(char *string){

    int hash = *string++;
    int ch;
    while(ch = *string++)
        hash = (hash<<5)^(hash>>27)^ch;

    return abs(hash % 20399);
}
