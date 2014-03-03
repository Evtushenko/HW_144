#pragma once
#include <iostream>
#include <cstdlib>

struct StackStruct {
	StackStruct* previous;
	int value;
};

class StackGeneral {
public:
	StackGeneral();
	virtual ~StackGeneral() = 0;
	virtual void push(int number) = 0;
	virtual int pop() = 0;
	virtual void print() const = 0;
};