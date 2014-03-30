//#pragma one
#include <cstdlib>
#include <iostream>
#include "SimpleList.h"


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
    void pushUser(int number);
    /**
    @brief takes code from mother. And checking for exception
    */
    void removeUser(int number);
private:
    /**
    @brief case it has another element with entered value
    */
    class ExceptionSame {};
    /**
    @brief nothing to delete
    */
    class ExceptionNotExists {};
};



