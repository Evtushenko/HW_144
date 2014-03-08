#include "HeapSort.h"

using namespace std;

void HeapSort::sorting(){
	int shift = 0;
	bool useful = false;
	while (shift + 2 < amountElements) {
		useful = false;
		for (int i = 0; i < amountElements; i++){
			int first = i * 2 + 1;
			int second = i * 2 + 2;
			if (second + shift < amountElements){
				if ((arrayElements[i + shift] > arrayElements[first + shift]) || (arrayElements[i + shift] > arrayElements[second + shift])){
					if (arrayElements[first + shift] < arrayElements[second + shift]){
						swap(arrayElements[i + shift], arrayElements[first + shift]);
						useful = true;
					}
					else if (arrayElements[second + shift] < arrayElements[first + shift]){
						swap(arrayElements[i + shift], arrayElements[second + shift]);
						useful = true;
					}
				}
			}
			else 
				if (first + shift < amountElements){
					if (arrayElements[i + shift] > arrayElements[first + shift]){
					swap(arrayElements[i + shift], arrayElements[first + shift]);
					useful = true;
					}
				}
		}
		if (!useful)
			shift++;
	}
	cout << "The heap sort completed\n";
}