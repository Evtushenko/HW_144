#include "pointerList.h"

PointerList::~PointerList() {
    ElementList *current = head;
    while (head) {
        current = head;
        head = head->next;
        delete current;
    }
    head = NULL;
}

void PointerList::addList(char *key) {
    if (!listIsEmpty()){
        ElementList* current = head;
        while (current->next!=NULL){
            current = current->next;
        }
        current->next = createListElement(key);
    }
    else {
        head = createListElement(key);
    }
}

void PointerList::removeFromList(int i){
    if (!listIsEmpty()){
        if (!(i==1)){
            ElementList* current = head;
            for (int j=2; j<i; j++){
                if (current->next != NULL)
                    current = current->next;
            }

            if (current->next != NULL){
                ElementList* del = current->next;
                current->next = current->next->next;
                delete(del);
            }
        }
        else {
            ElementList* del = head;
            head = head->next;
            delete(del);
        }

    }
}

void PointerList::printList(){
    if (!listIsEmpty()){
        ElementList* current = head;
        printf("%s\n", current->data);
        while (current->next != NULL){
            current = current->next;
            printf("%s\n", current->data);
        }
    }
    else printf("List is Empty");
}

int PointerList::sizeList(){
    int size = 0;
    if (!listIsEmpty()){
        ElementList* current = head;
        while (current->next != NULL){
            current = current->next;
            size++;
        }
        size++;
    }
    return size;

}

ElementList *PointerList::createListElement(char *key){
    char * slot = new char[strlen(key) + 1];
    memcpy(slot, key, strlen(key) + 1);
    ElementList* pNew = new ElementList;
    pNew->next = NULL;
    pNew->data = slot;
    return pNew;
}
