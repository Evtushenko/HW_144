#include "FunctionsNames.h"

void removeData(dataMemory ** top) {
	dataMemory *helper = nullptr;
	while (*top) {
		helper = *top;
		*top = (*top)->next;
		delete helper ;
	}
}

void showData(dataMemory ** top) {
	dataMemory *helper = *top;
	printf("list of data:\n");
	while (helper) {
		printf("%d %d\n",helper->value, helper->adress);
		helper = helper->next;
	}
}

void addToData(dataMemory ** begin, int adress, int value) {
	if (!*begin) {
		dataMemory *slot = new dataMemory;
		slot->adress = 0;
		if (adress == 0)
			slot->value = value;
		else
			slot->value = 0; 
		slot->next = nullptr;
		*begin = slot;
		//printf("test\n\n");
	}
	//else {
		//printf("test\n\n");
		dataMemory *start = *begin;
		int currentAdress = 1;
		while ( currentAdress < adress) { // going to target adress
			if (!start->next) {
				dataMemory *slot = new dataMemory;
				slot->adress = currentAdress++;
				slot->value = 0;
				slot->next = nullptr;
				start->next = slot;
				start = start->next;
			}
			else {
				start = start->next;
			}
		}
		dataMemory *slot = new dataMemory;
				slot->adress = currentAdress++;
				slot->value = value;
				slot->next = nullptr;
				start->next = slot;
				//start = start->next;
	//}
}