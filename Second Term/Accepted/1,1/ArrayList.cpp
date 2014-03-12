#include "ArrayList.h"

using namespace std;

ArrayList ::~ArrayList() {
	delete [] ArrayListElements;
}

int ArrayList ::pop(){
	if (!lengthArray)
		return -1;
	int answer = ArrayListElements[lengthArray-1];
	int *slot = new int[lengthArray-1];
	for (int i = 0; i < lengthArray-1; i++)
		slot[i] = ArrayListElements[i];
	delete [] ArrayListElements;
	ArrayListElements = slot;
	lengthArray--;
	return answer;
};

void ArrayList::print() const {
	cout << "List of Array Stack:\n";
	for (int i = 0; i < lengthArray; i++) {
		cout << ArrayListElements[i] << " ";
	}
	cout << endl;
}

void ArrayList::push(int number){
	if (lengthArray == 0) {
		ArrayListElements = new int[++lengthArray];
		ArrayListElements[0] = number;
	}
	else {
		int *slot = new int [lengthArray];
		for (int i = 0; i < lengthArray; i++)
			slot[i] = ArrayListElements[i];
		delete[] ArrayListElements;
		ArrayListElements = new int[++lengthArray];
		for (int i = 0; i < lengthArray-1; i++) {
			ArrayListElements[i] = slot[i];
		}
		ArrayListElements[lengthArray-1] = number;
		delete[] slot;
	}
}