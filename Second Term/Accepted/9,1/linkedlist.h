#pragma once

#include "list.h"

class LinkedList : public List
{
public:
    LinkedList();
    ~LinkedList();
    void addElement(int number);
    void deleteElement(int number);
    void printList();
private:
    struct Element
    {
        int number;
        Element *next;
    };
    Element *head;
    Element *createElement();
};
