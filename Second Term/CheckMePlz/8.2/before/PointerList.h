#pragma once
#include "ElementList.h"
#include <stdio.h>

template <typename T>
class PointerList{
public:
	PointerList(){

		head = NULL;

	}

	~PointerList(){
		head = NULL;
	}

	void addList(T key){

		if (!listIsEmpty()){
			ElementList <T>* current = head;
			while (current->next!=NULL){
				current = current->next;
			}
			current->next = createListElement(key);
		}
		else {
			head = createListElement(key);
		}

	}

	ElementList<T>* headList(){
		return head;
	}

	void removeFromList(int i){

		if(!listIsEmpty()){
			if (!(i==1)){
				ElementList <T>* current = head;
				for (int j=2; j<i; j++){
					if (current->next != NULL)
						current = current->next;
				}

				if (current->next != NULL){
					ElementList <T>* del = current->next;
					current->next = current->next->next;
					delete(del);
				}
			}
			else {
				ElementList <T>* del = head;
				head = head->next;
				delete(del);
			}

		}

	}

	bool listIsEmpty(){

		return (head == NULL);

	}
	void printList(){

		if(!listIsEmpty()){
			ElementList <T>* current = head;
			printf("%d\n", current->data);
			while (current->next != NULL){
				current = current->next;
				printf("%d\n", current->data);
			}
		}
		else printf("List is Empty");

	}

	int sizeList(){

		int size = 0;
		if (!listIsEmpty()){
			ElementList <T>* current = head;
			while (current->next != NULL){
				current = current->next;
				size++;
			}
			size++;
		}
		return size;

	}
private:
	ElementList <T>* head;
	ElementList <T>* createListElement(T key){

		ElementList <T>* pNew = new ElementList<T>;
		pNew->next = NULL;
		pNew->data = key;
		return pNew;

	}
};
