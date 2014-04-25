#include <iostream>
#include "doublylinkedlist.h"
#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList *a = new LinkedList();
    a->addElement(1);
    a->printList();
    a->addElement(2);
    a->printList();
    a->addElement(3);
    a->printList();
    a->addElement(4);
    a->printList();
    a->deleteElement(2);
    a->printList();
    a->deleteElement(1);
    a->printList();
    a->deleteElement(2);
    a->printList();
    a->deleteElement(2);
    a->printList();
    a->deleteElement(1);
    a->printList();
    delete a;
    DoublyLinkedList *b = new DoublyLinkedList();
    a->addElement(1);
    a->printList();
    a->addElement(2);
    a->printList();
    a->addElement(3);
    a->printList();
    a->addElement(4);
    a->printList();
    a->deleteElement(2);
    a->printList();
    a->deleteElement(1);
    a->printList();
    a->deleteElement(2);
    a->printList();
    a->deleteElement(2);
    a->printList();
    a->deleteElement(1);
    a->printList();
    delete b;
}

