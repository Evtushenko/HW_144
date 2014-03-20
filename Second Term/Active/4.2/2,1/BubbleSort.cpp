#include "BubbleSort.h"

using namespace std;

void BubbleSort::sorting() {
    for (int i = amountElements - 1 ; i >= 0 ; i--) {
        for (int j = 0 ; j < i ; j++) {
            if (arrayElements[j] > arrayElements[j+1]) {
                swap(arrayElements[j],arrayElements[j+1]);
            }
        }
    }
}
