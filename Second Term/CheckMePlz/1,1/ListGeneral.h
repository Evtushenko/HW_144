#pragma once
#include <iostream>
#include <cstdlib>

struct StackStruct {
	StackStruct* next;
	int value;
};

class ListGeneral {
public:
	ListGeneral();
	virtual ~ListGeneral() = 0;
	virtual void push(int number) = 0;
	virtual int pop() = 0;
	virtual void print() const = 0;
};