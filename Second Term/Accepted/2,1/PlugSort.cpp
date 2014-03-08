#include "PlugSort.h"

using namespace std;

void PlugSort::sorting() {
	for (int i = 1 ; i < amountElements ; i++)     
		for (int j = i ; j > 0 && arrayElements[j-1] > arrayElements[j] ; j--) 
            swap(arrayElements[j-1],arrayElements[j]);  
	cout << "The plug sort completed\n";
}