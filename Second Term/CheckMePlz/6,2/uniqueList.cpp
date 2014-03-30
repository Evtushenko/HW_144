#include "uniqueList.h"

using namespace std;

void UniqueList::pushUser(int number){
    try {
        if (find(number))
           throw ExceptionSame();
       } catch (ExceptionSame &) {
           cout << "caught ExceptionSame:\nit already has this one\n";
           return;
       }
    push(number);
}


void UniqueList::removeUser(int number) {
    try {
        if (!find(number))
            throw ExceptionNotExists();
       } catch (ExceptionNotExists &) {
           cout << "caught ExceptionNotExists:\nthis one Not Exists\n";
           return;
       }
    remove(number);
}

