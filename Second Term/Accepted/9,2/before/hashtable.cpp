#include "hashtable.h"
#include <stdio.h>

Hashtable::Hashtable(Hashing *typeOfHash){

	Table = new TableCell<char*>[sizeTable];
	occupiedCells = 0;
	numberOfConflicts = 0;

}

int Hashtable::hash(char *string){

	return hashHelper->hashFunction(string);

}

void Hashtable::addElement(char *string){

	TableCell<char*>* neededList = &Table[hash(string)];
	if(neededList->listIsEmpty())
		occupiedCells++;
	else
		if(neededList->sizeOfCell == 1)
			numberOfConflicts++;
	neededList->sizeOfCell++;
	neededList->addList(string);

}

bool Hashtable::findElement(char *string){

	TableCell<char*>* neededList = &Table[hash(string)];
	if (!neededList->listIsEmpty()){
		int i = 0;
		ElementList<char*>* scanningElement = neededList->headList();
		while(scanningElement != NULL){
			i = 0;
			while((scanningElement->data[i] == string[i])&&(string[i] != '\0')) //compare current string with pattern
				i++;
			if (string[i] == '\0')
				return true;
			scanningElement = scanningElement->next;

		}
	}
	return false;

}

bool Hashtable::removeElement(char *string){

	TableCell<char*>* neededList = &Table[hash(string)];
	if (!neededList->listIsEmpty()){

		neededList->sizeOfCell--;

		if(neededList->sizeOfCell == 1)
			numberOfConflicts--;

		int i = 0;
		ElementList<char*>* previousElement = NULL;
		ElementList<char*>* scanningElement = neededList->headList();
		while(scanningElement != NULL){
			i = 0;
			while((scanningElement->data[i] == string[i])&&(string[i] != '\0'))
				i++;
			if (string[i] == '\0'){  //delete scanningElement from neededList


				if (previousElement == NULL){
					neededList->removeFromList(1);
					if(neededList->listIsEmpty())
						occupiedCells--;
				}
				else{
					ElementList<char*>* tmp = scanningElement;
					previousElement->next = scanningElement->next;
					delete tmp;
				}
				return false;

			}
			previousElement = scanningElement;
			scanningElement = scanningElement->next;

		}
	}
	return false;
}

int Hashtable::getMaxSize(){

	int maxSize = 0;

	for(int i = 0; i < sizeTable; i++)
		if(!Table[i].listIsEmpty())
			if(maxSize < Table[i].sizeOfCell)
				maxSize = Table[i].sizeOfCell;

	return maxSize;

}

void Hashtable::showStatistic(){
	printf("\n\nAll Cells: %d\n", sizeTable);
	printf("Occupied Cells: %d\n", occupiedCells);
	printf("Free Cells: %d\n", sizeTable - occupiedCells);
	loadFactor = (double)occupiedCells/sizeTable;
	printf("Load Factor: %.8f\n", loadFactor);
	printf("Count of Conflicts: %d\n", numberOfConflicts);
	printf("Max Size of Cell: %d\n\n", getMaxSize());
}

void Hashtable::changeHash(Hashing *typeOfHash){

	previousHashHelper = hashHelper;
	hashHelper = typeOfHash;
	int actualHash;
	ElementList<char*>* head;
	ElementList<char*>* tmp;
	for(int i = 0; i < sizeTable; i++){
		if(!Table[i].listIsEmpty()){
			head = Table[i].headList();
			actualHash = hashHelper->hashFunction(head->data);

			while((actualHash != i) && (head != NULL)){
				Table[actualHash].addList(head->data);
				Table[actualHash].sizeOfCell++;
				head = head->next;
				tmp = head;
				delete tmp;
				Table[i].sizeOfCell--;
				if (head != NULL)
					actualHash = hashHelper->hashFunction(head->data);
			}
		}
	}
}
