#pragma once
#include "elementList.h"
#include <stdio.h>
#include <string.h>

class PointerList {
public:
    PointerList(): head(NULL) {}
    ~PointerList();

    void addList(char *key);

    ElementList* headList() {
        return head;
    }

    void removeFromList(int i);

    bool listIsEmpty() {
        return (head == NULL);
    }

    void printList();

    int sizeList();

private:
    ElementList* head;
    ElementList* createListElement(char *key);
};
