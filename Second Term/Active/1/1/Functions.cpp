#include "List.h"

using namespace std;

StackGeneral ::StackGeneral () {
}

StackGeneral ::~StackGeneral () {
}

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

PointStack ::~PointStack (){
	while (top) {
		StackStruct* newS = top;
		top = top->previous;
		delete newS;
	}
}

void PointStack::push(int number){
	StackStruct* newS = new StackStruct;
	newS->value = number;
	newS->previous = nullptr;
	if (!top) {
		top = newS;
	}
	else {
		newS->previous = top;
		top = newS;
	}
};

void PointStack::print() const {
	cout << "List of  Point Stack:\n";
	StackStruct* newS = top;
	while (newS) {
		cout << newS->value << " ";
		newS = newS->previous;
	}
	cout << endl;
}

int  PointStack::pop()  {
	if (!top)
		return -1;
	int answer = top->value;
	top = top->previous;
	return answer;
}
