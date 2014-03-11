#pragma once
#include <iostream>
#include <cstdlib>

class ListGeneral {

public:
	struct StackStruct {
	StackStruct* next;
	int value;
};
	virtual ~ListGeneral() = 0;
	virtual void push(int number) = 0;
	virtual int pop() = 0;
	virtual void print() const = 0;
};