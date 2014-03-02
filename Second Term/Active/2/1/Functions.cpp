#include "Sorter.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "PlugSort.h"
#include "BubbleSort.h"

using namespace std;

void Sorter::swap(int &first, int &second) {
	int tmp = first;
	first = second;
	second = tmp;
}

void Sorter::readKeybord() {
	cout << "enter the elements(default amount = 5)\n";
	for (int i = 0 ; i < amountElements; i++)
		cin >> arrayElements[i];
}

void Sorter::print() const {
	cout << "list of elements:\n";
	for (int i = 0 ; i < amountElements; i++)
		cout << arrayElements[i] << endl;
}

PlugSort::PlugSort() {
}

HeapSort::HeapSort() {
}

QuickSort::QuickSort() {
	begin = 0;
	end = amountElements-1;
}

BubbleSort ::BubbleSort () {
}

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

	if (!(i < end) && !(j > begin))
		cout << "The quick sort completed\n";
}

void BubbleSort::sorting() {
	for (int i = amountElements - 1 ; i >= 0 ; i--) {
		for (int j = 0 ; j < i ; j++) {
			if (arrayElements[j] > arrayElements[j+1]) {
				swap(arrayElements[j],arrayElements[j+1]);
			}
		}
	}
	cout << "The bubble sort completed\n";
}

void PlugSort::sorting() {
	for (int i = 1 ; i < amountElements ; i++)     
		for (int j = i ; j > 0 && arrayElements[j-1] > arrayElements[j] ; j--) 
            swap(arrayElements[j-1],arrayElements[j]);  
	cout << "The plug sort completed\n";
}