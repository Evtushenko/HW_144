#include "PlugSort.h"

using namespace std;

void PlugSort::sorting() {
    for (int i = 1 ; i < currentNumber ; i++)
        for (int j = i ; j > 0 && *arrayColumns[j-1] > *arrayColumns[j] ; j--)
            change(arrayColumns[j-1],arrayColumns[j]);
}
