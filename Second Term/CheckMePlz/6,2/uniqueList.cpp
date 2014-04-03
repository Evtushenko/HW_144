#include "uniqueList.h"

using namespace std;

void UniqueList::pushUser(int number) throw (ExceptionSame){
    if (find(number))
        throw ExceptionSame("caught ExceptionSame:\nit already has this one\n");
    push(number);
}


void UniqueList::removeUser(int number) throw(ExceptionNotExists) {
    if (!find(number))
        throw ExceptionNotExists("caught ExceptionNotExists:\nthis one Not Exists\n");
    remove(number);
}

