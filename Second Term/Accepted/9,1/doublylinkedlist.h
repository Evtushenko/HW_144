#pragma once

#include "list.h"

class DoublyLinkedList : public List
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addElement(int number);
    void deleteElement(int number);
    void printList();
private:
    struct Element
    {
        int number;
        Element *next;
        Element *previous;
    };
    Element *head;
    Element *ending;
    Element *createElement();
};
