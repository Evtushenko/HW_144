#pragma once
#include <iostream>
#include <cstdlib>
#include <string.h>

int const maxBufferSize = 20;

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
	virtual int getTop() = 0;
	virtual void print() const = 0;
	int infix(char stringIn []);
protected:
	int calculateStack(char stringOut []);
	bool firstPriority(char a) const;
};
