#include "bubbleSort.h"

using namespace std;

void BubbleSort::sorting() {
    for (int i = currentNumber-1 ; i >= 0 ; i--) {
        for (int j = 0 ; j < i ; j++) {
            if (*arrayColumns[j] > *arrayColumns[j+1]) {
                change(arrayColumns[j],arrayColumns[j+1]);
            }
        }
    }
    this->TransferToMatrix();
}
