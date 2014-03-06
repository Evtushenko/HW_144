#include "ArrayStack.h"

using namespace std;

ArrayStack ::~ArrayStack() {
	delete [] arrayStackElements;
}

int ArrayStack ::pop(){
	if (!lengthArray)
		return -1;
	int answer = arrayStackElements[0];
	int *slot = new int[lengthArray-1];
	for (int i = 1; i < lengthArray; i++)
		slot[i-1] = arrayStackElements[i];
	delete [] arrayStackElements;
	arrayStackElements = slot;
	lengthArray--;
	return answer;
};

void ArrayStack::print() const {
	cout << "List of Array Stack:\n";
	for (int i = 0; i < lengthArray; i++) {
		cout << arrayStackElements[i] << " ";
	}
	cout << endl;
}

void ArrayStack::push(int number){
	if (lengthArray == 0) {
		arrayStackElements = new int[++lengthArray];
		arrayStackElements[0] = number;
	}
	else {
		int *slot = new int [lengthArray];
		for (int i = 0; i < lengthArray; i++)
			slot[i] = arrayStackElements[i];
		delete[] arrayStackElements;
		arrayStackElements = new int[++lengthArray];
		arrayStackElements[0] = number;
		for (int i=0; i < lengthArray-1; i++) {
			arrayStackElements[i+1] = slot[i];
		}
		delete[] slot;
	}
}

int ArrayStack::getTop() {
	if (lengthArray)
		return arrayStackElements[lengthArray-1];
	return 0;
}
