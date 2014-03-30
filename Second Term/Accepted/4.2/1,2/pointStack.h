#pragma once
#include "stackGeneral.h"

class PointStack : public StackGeneral {
public:
    PointStack() : top(NULL) {}
    ~PointStack();
    void push(int number);
    int pop();
    void print() const;
    int getTop();
    int size() const;
private:
    struct StackStruct {
        StackStruct* previous;
        int value;
    };
    StackStruct *top;
};
