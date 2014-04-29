#include "CRC32Hash.h"
#include <cstring>
#include <stdlib.h>

int CRC32Hash::hashFunction(char *string){

    memset(binary, 0, sizeof binary);
    int n = 32; //first 32 bits are null

    int ch;

    while(ch = *string++){
        for (int i = 0; i < 8; i++)
            if ((ch >> i) & 1)
                binary[n++] = 1;
            else
                binary[n++] = 0;
    }

    int hash = 0;

    for (int i = n-1; i >=n-32; i--){ //take first essential 32 bit
        hash <<= 1;
        hash |= binary[i]; //on the free bit write binary[next]
    }

    for (int i = n-33; i >= 0; i--){
        int check = (hash >> 31) & 1;
        hash <<= 1;
        hash |= binary[i];

        if(check)
            hash ^= Q; //this is actually subtraction
    }

    return abs(hash % 20399);



}
