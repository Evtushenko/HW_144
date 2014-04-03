//#pragma one
#include <cstdlib>
#include <iostream>
#include "simpleList.h"
#include "exceptionSame.h"
#include "exceptionNotExists.h"


class TestUniqueList;
/**
@brief class for chenking for exceprion with add and delete. Has Unique List = son.
*/
class UniqueList: public SimpleList {
friend class TestUniqueList;
public:
    /**
    @brief takes code from mother. And checking for exception
    */
    void pushUser(int number) throw (ExceptionSame);
    /**
    @brief takes code from mother. And checking for exception
    */
    void removeUser(int number) throw(ExceptionNotExists);
};



