//#pragma one
#include <cstdlib>
#include <iostream>


class TestUniqueList;
/**
@brief unique adding, removing with cheking, and printing
*/
class UniqueList {
    /**
    @brief for using private fields
    */
friend class TestUniqueList;
public:
    UniqueList() : begin(NULL), end(NULL) {}
    ~UniqueList();
    /**
    @brief push int to the end
    */
    void push(int number);
    /**
    @brief printing list to the console
    */
    void print() const;
    /**
    @brief delete from all list postition if it's possible
    */
    void remove(int number);
private:
    /**
    @brief for storing list elements
    */
    struct StackStruct {
        StackStruct* next;
        int value;
    };
    StackStruct *begin;
    StackStruct *end;
    /**
    @brief find list elements with current value
    @detailed has code here cause i have troubles with namespaces
    */
    StackStruct *find(int value) {
        StackStruct *helper = begin;
        while (helper) {
            if (helper->value == value)
                return helper;
            helper = helper->next;
        }
        return helper;
    }

    /**
    @brief for chenking list for this value
    */
    class ExceptionSame {};
    static void throwExceptionSame() { throw ExceptionSame(); }

    /**
    @brief can we delete it or not?
    */
    class ExceptionNotExists {};
    static void throwExceptionNotExists () { throw ExceptionNotExists(); }
};



