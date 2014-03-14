#include "FunctionsNames.h"

void addToStack(stackMemory ** top, int value) {
	stackMemory *newS = (stackMemory *) malloc(sizeof(stackMemory));
	newS->value = value;
	if (!*top) {
		newS->previous = nullptr;
		*top = newS;
	}
	else {
		newS->previous = *top;
		*top = newS;
	}
}

void removeStack(stackMemory ** top){
	stackMemory *helper = nullptr;
	while (*top) {
		helper = *top;
		*top = (*top)->previous;
		free(helper);
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

int popStack(stackMemory ** top) {
	int number = (*top)->value;
	stackMemory * slot= *top;
	*top= (*top)->previous;
	free(slot);
	return number;
}