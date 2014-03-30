#pragma once
#include "stackGeneral.h"

class ArrayStack : public StackGeneral  {

public:
    ArrayStack(): arrayStackElements(NULL), lengthArray(0) {}
    ~ArrayStack();
    void push(int number);
    int pop();
    void print() const;
    int getTop();
    int size() const;

private:
    int *arrayStackElements;
    int lengthArray;
};
