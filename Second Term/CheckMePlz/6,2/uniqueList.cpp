#include "uniqueList.h"

using namespace std;

void UniqueList::pushUser(int number){
    try {
        if (find(number))
            throwExceptionSame();
       } catch (ExceptionSame &) {
           cout << "caught ExceptionSame:\nit already has this one\n";
           return;
       }
    push(number);
}


void UniqueList::removeUser(int number) {
    try {
        if (!find(number))
            throwExceptionNotExists();
       } catch (ExceptionNotExists &) {
           cout << "caught ExceptionNotExists:\nthis one Not Exists\n";
           return;
       }
    remove(number);
}

