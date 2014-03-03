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

int PointStack::calculateStack(char stringOut []) {
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

				top->value = top->value - digitIntoSymbol + tempValue;
			}

			if (stringOut[i] == '-')
			{

				(top->value) = top->value - tempValue + digitIntoSymbol;
			}

			if (stringOut[i] == '*')
			{

				(top->value) = ((top->value - digitIntoSymbol)*(tempValue - digitIntoSymbol) + digitIntoSymbol);
			}

			if (stringOut[i] == '/')
			{

				(top->value) = (top->value - digitIntoSymbol) / (tempValue - digitIntoSymbol) + digitIntoSymbol;
			}
		}
	}
	int answer = int(top->value) - digitIntoSymbol;
	cout << "ans: " << answer << endl;
	return answer;
}


int PointStack::infix(char stringIn []) {
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
			while (top->value != '(') {
				stringOut[current++] = this->pop();
			}
		}
		else {
			if (isdigit(stringIn[i])) {
				stringOut[current] = stringIn[i];
				++current;
			}
			if ((stringIn[i] == '+') || (stringIn[i] == '-')) {
				if ((top) && (firstPriority(top->value))) {
					while ((top) && (firstPriority(top->value))) {
						stringOut[current++] = this->pop();
					}
					this->push(stringIn[i]);
				}
				else {
					if ((top) && ((top->value == '+') || (top->value == '-')))
						stringOut[current++] = this->pop();
					this->push(stringIn[i]);
				}
			}
			if ((stringIn[i] == '*') || (stringIn[i] == '/')) {
				this->push(stringIn[i]);
			}
		}
	}
	while (top) {
		stringOut[current++] = this->pop();
	}
	calculateStack(stringOut);
return 0;
}