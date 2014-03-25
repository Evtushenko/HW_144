#include "uniqueList.h"
#include "exceptionSame.h"

using namespace std;

UniqueList ::~UniqueList (){
    while (begin) {
        StackStruct* newS = begin;
        begin = begin->next;
        delete newS;
    }
}

void UniqueList::push(int number){
    try {
        if (find(number))
            throwExceptionSame();
       } catch (ExceptionSame &) {
           cout << "caught ExceptionSame:\nit already has this one\n";
           return;
       }
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

void UniqueList::print() const {
    cout << "List of  Point Stack:\n";
    StackStruct* newS = begin;
    while (newS) {
        cout << newS->value << " ";
        newS = newS->next;
    }
    cout << endl;
}

void UniqueList::remove(int number) {
    try {
        if (!find(number))
            throwExceptionNotExists();
       } catch (ExceptionNotExists &) {
           cout << "caught ExceptionNotExists:\nthis one Not Exists\n";
           return;
       }
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

