#include "StackGeneral.h"

using namespace std;

StackGeneral ::StackGeneral () {
}

StackGeneral ::~StackGeneral () {
}

bool StackGeneral::firstPriority(char a) const{
	return a == '*' || a == '/';
}

int StackGeneral::infix(char stringIn []) {
	char stringOut[maxBufferSize];
	for (int i = 0; i < maxBufferSize; i++)
		stringOut[i] = '\0';
	int size = strlen(stringIn);
	int current = 0;
	int i = 0;
	for (int i = 0; i < size; i++) {
		if (stringIn[i] == '(')
			this->push(stringIn[i]);
		if (stringIn[i] == ')') {
			while (this->getTop() != '(') {
				stringOut[current++] = this->pop();
			}
		}
		else {
			if (isdigit(stringIn[i])) {
				stringOut[current] = stringIn[i];
				++current;
			}
			if ((stringIn[i] == '+') || (stringIn[i] == '-')) {
				if ((this->getTop()) && (firstPriority(this->getTop()))) {
					while ((this->getTop()) && (firstPriority(this->getTop()))) {
						stringOut[current++] = this->pop();
					}
					this->push(stringIn[i]);
				}
				else {
					if ((this->getTop()) && ((this->getTop() == '+') || (this->getTop() == '-')))
						stringOut[current++] = this->pop();
					this->push(stringIn[i]);
				}
			}
			if ((stringIn[i] == '*') || (stringIn[i] == '/')) {
				this->push(stringIn[i]);
			}
		}
	}
	while (this->getTop()) {
		stringOut[current++] = this->pop();
	}
	calculateStack(stringOut);
return 0;
}

int StackGeneral::calculateStack(char stringOut []) {
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
				this->push(this->pop() - digitIntoSymbol + tempValue);
			}

			if (stringOut[i] == '-')
			{
				this->push(this->pop() + digitIntoSymbol - tempValue);
			}

			if (stringOut[i] == '*')
			{

				this->push(((this->pop() - digitIntoSymbol)*(tempValue - digitIntoSymbol) + digitIntoSymbol));
			}

			if (stringOut[i] == '/')
			{

				this->push( (this->pop()- digitIntoSymbol) / (tempValue - digitIntoSymbol) + digitIntoSymbol );
			}
		}
	}
	int answer = int(this->getTop()) - digitIntoSymbol;
	cout << "ans: " << answer << endl;
	return answer;
}