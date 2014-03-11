#include "BubbleSort.h"

using namespace std;

void BubbleSort::sorting() {
	this->readFile();
	this->printMatrix();
	for (int i = currentNumber-1 ; i >= 0 ; i--) {
		for (int j = 0 ; j < i ; j++) {
			if (*arrayColumns[j] > *arrayColumns[j+1]) {
				change(arrayColumns[j],arrayColumns[j+1]);
			}
		}
	}
	cout << "The bubble sort completed\n";
	this->TransferToMatrix();
	this->printMatrix();
}