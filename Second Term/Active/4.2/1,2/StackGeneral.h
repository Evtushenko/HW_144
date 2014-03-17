#pragma once
#include <iostream>
#include <cstdlib>
#include <string.h>

int const maxBufferSize = 20;

class StackGeneral {

public:
    virtual ~StackGeneral() = 0;
    virtual void push(int number) = 0;
    virtual int pop() = 0;
    virtual int getTop() = 0;
    virtual void print() const = 0;
    virtual int size() const = 0;
    char *infix(char stringIn []);
    int calculateStack(char stringOut []);

protected:
    bool firstPriority(char a) const;
};
