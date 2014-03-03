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

class PointStack : public StackGeneral {
public:
	PointStack() : top(nullptr) {}
	~PointStack();
	void push(int number);
	int pop();
	void print() const;
private:
	StackStruct *top;
};

class ArrayStack : public StackGeneral  {
public:
	ArrayStack(): lengthArray(0) {}
	~ArrayStack(); 
	void push(int number);
	int pop();
	void print() const;
private:
int *arrayStackElements;
int lengthArray;
};