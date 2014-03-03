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


int ArrayStack::infix(char stringIn []) {
	char stringOut[maxBufferSize];
	for (int i=0; i < maxBufferSize; i++)
		stringOut[i] = '\0';
	int size = strlen(stringIn);
	int current = 0;
	int i = 0;
	for (int i = 0; i < size; i++) {
		if (stringIn[i] == '(')
			this->push(stringIn[i]);
		if (stringIn[i] == ')') {
			while (arrayStackElements[0] != '(') {
				stringOut[current++] = this->pop();
			}
		}
		else {
			if (isdigit(stringIn[i])) {
				stringOut[current] = stringIn[i];
				++current;
			}
			if ((stringIn[i] == '+') || (stringIn[i] == '-')) {
				if ((lengthArray) && (firstPriority(arrayStackElements[0]))) {
					while ((lengthArray) && (firstPriority(arrayStackElements[0]))) {
						stringOut[current++] = this->pop();
					}
					this->push(stringIn[i]);
				}
				else {
					if ((lengthArray) && ((arrayStackElements[0] == '+') || (arrayStackElements[0] == '-')))
						stringOut[current++] = this->pop();
					this->push(stringIn[i]);
				}
			}
			if ((stringIn[i] == '*') || (stringIn[i] == '/')) {
				this->push(stringIn[i]);
			}
		}
	}
	while (lengthArray) {
		stringOut[current++] = this->pop();
	}
	calculateStack(stringOut);
return 0;
}

int ArrayStack::calculateStack(char stringOut []) {
	int const digitIntoSymbol = 48;
	StackStruct *helper = nullptr;
	int length = strlen(stringOut);
	int tempValue = 0;
	for (int i = 0; i < length; i++) {
		if (isdigit(stringOut[i]))
			this->push(stringOut[i]);
		else
		{
			tempValue = this->pop();
			if (stringOut[i] == '+')
			{

				arrayStackElements[0] = arrayStackElements[0] - digitIntoSymbol + tempValue;
			}

			if (stringOut[i] == '-')
			{

				(arrayStackElements[0]) = arrayStackElements[0] - tempValue + digitIntoSymbol;
			}

			if (stringOut[i] == '*')
			{

				(arrayStackElements[0]) = ((arrayStackElements[0] - digitIntoSymbol)*(tempValue - digitIntoSymbol) + digitIntoSymbol);
			}

			if (stringOut[i] == '/')
			{

				(arrayStackElements[0]) = (arrayStackElements[0]- digitIntoSymbol) / (tempValue - digitIntoSymbol) + digitIntoSymbol;
			}
		}
	}
	int answer = int(arrayStackElements[0]) - digitIntoSymbol;
	cout << "ans: " << answer << endl;
	return answer;
}