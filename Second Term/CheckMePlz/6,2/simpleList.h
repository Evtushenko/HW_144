//#pragma one
#include <cstdlib>
#include <iostream>

/**
@brief Mother for Unique List. It can add end, delete, print.
*/
class SimpleList {
public:
    SimpleList() : begin(NULL), end(NULL) {}
    ~SimpleList();
    /**
    @brief print all elemnts to console
    */
    void print() const;
protected:
    /**
    @brief push int to end of list
    */
    void push(int number);
    /**
    @brief remove int. Uses helping function find.
    */
    void remove(int number);
    /**
    @brief for storing List elements
    */
    struct StackStruct {
        StackStruct* next;
        int value;
    };
    StackStruct *begin;
    StackStruct *end;
    /**
    @brief has code here cause namespace truble
    @param int from delete remove
    @return pointer to element of list
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
};

