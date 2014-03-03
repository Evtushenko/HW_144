#include "PointStack.h"

using namespace std;

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
