#include "simpleList.h"

using namespace std;

SimpleList ::~SimpleList (){
    while (begin) {
        StackStruct* newS = begin;
        begin = begin->next;
        delete newS;
    }
}

void SimpleList::push(int number){
    StackStruct* newS = new StackStruct;
    newS->value = number;
    newS->next = NULL;
    if (!begin) {
        begin = newS;
        end = newS;
    }
    else {
        end -> next = newS;
        end = newS;
    }
}

void SimpleList::print() const {
    cout << "List of  Point Stack:\n";
    StackStruct* newS = begin;
    while (newS) {
        cout << newS->value << " ";
        newS = newS->next;
    }
    cout << endl;
}

void SimpleList::remove(int number) {
    StackStruct *previous = NULL;
    StackStruct *next = NULL;
    StackStruct *result = find(number);
    StackStruct *start = begin;
        while (start) {
              if (start->next == result)
                     previous = start;
              if (start == result && start->next) {
                     next = start->next;
               }
              start = start->next;
         }
        if (previous && next)
            previous->next = next;
        else
            if (previous)
                previous->next = NULL;
            else
                if (next)
                    begin = result->next;
                else
                    if (!next && !previous)
                        begin = NULL;
                delete result;
                result = NULL;
}
