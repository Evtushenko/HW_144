#include "FunctionsNames.h"



void addToStack(stackMemory ** top, int value, int &amountElementsStack) {
	//printf("add\n");
	stackMemory * newS = new stackMemory;
	newS->value = value;
	if (!*top) {
		newS->previous = nullptr;
		*top = newS;
	}
	else {
		newS->previous = *top;
		*top = newS;
	}
	amountElementsStack++;
}


void removeStack(stackMemory ** top){
	stackMemory *helper = nullptr;
	while (*top) {
		helper = *top;
		*top = (*top)->previous;
		delete helper ;
	}
}

void showStack(stackMemory ** top) {
	stackMemory *helper = *top;
	printf("list of stack:\n");
	while (helper) {
		printf("%d\n",helper->value);
		helper = helper->previous;
	}
}

int popStack(stackMemory ** top, int &amountElementsStack) {
	//printf("pop\n");
	int number = (*top)->value;
	stackMemory * slot= *top;
	*top= (*top)->previous;
	delete slot;
	amountElementsStack--;
	return number;
}