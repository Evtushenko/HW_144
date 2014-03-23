#pragma once
#include "listGeneral.h"

class ArrayList : public ListGeneral  {
public:
    ArrayList(): ArrayListElements(NULL), lengthArray(0) {}
    ~ArrayList();
    void push(int number);
    int pop();
    void print() const;
    int size() const;
private:
    int *ArrayListElements;
    int lengthArray;

};
