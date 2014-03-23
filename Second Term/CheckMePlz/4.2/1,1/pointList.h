#pragma once
#include "listGeneral.h"

class PointList : public ListGeneral {
public:
    PointList() : begin(NULL), end(NULL) {}
    ~PointList();
    void push(int number);
    int pop();
    void print() const;
    int size() const;
private:
    struct StackStruct {
        StackStruct* next;
        int value;
    };
    StackStruct *begin;
    StackStruct *end;
};
