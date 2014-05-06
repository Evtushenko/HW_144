#include "hash31.h"

int Hash31::hashFunction(char *text) {
    int l = strlen(text);
    int result = 0;
        for (int i = 0 ; i < l; i++) {
            result += int(text[i])*i;
            result = result % (amountCells -1);
        }
     return result;
}
