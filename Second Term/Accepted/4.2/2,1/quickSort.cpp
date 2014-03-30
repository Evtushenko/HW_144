#include "quickSort.h"

using namespace std;

void QuickSort:: sorting() {
    int middle = arrayElements[(begin + end) / 2];
    int i = begin;
    int j = end;

    while (i < j){
        while (arrayElements[i] < middle)
            ++i;
        while (arrayElements[j] > middle)
            --j;
        if (i <= j)
        {
            if (i < j)
                swap(arrayElements[i],arrayElements[j]);
            ++i;
            --j;
        }
    }

    if (i < end) {
        begin = i;
        sorting();
    }
    if (j > begin) {
        end = j;
        sorting();
    }
}
