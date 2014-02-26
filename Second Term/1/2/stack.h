#pragma once;
#include <iostream>
#include <cstdlib>

struct list {
public:
	list(double value) {
		this->value = value;
		previous = nullptr;
	}
	list() { value = 0; }
	list* previous;
	double getValue();
private:
	double value;
};

class myStacks
{
public:
	virtual void clean() = 0;
	virtual void print() = 0;
	virtual void push(double value) = 0;
	virtual double pop() = 0;
	double calculate(char* mas);
	int infix(char* mas);
protected:
	list* top;
	bool firstPriority();
};

class pointStack : public myStacks
{
public:
	pointStack();
	void clean();
	void print();
	void push(double value);
	double pop();
};

class massiveStack : public myStacks
{
public:
	massiveStack();
	void clean();
	void print();
	void push(double value);
	double pop();
	double calculate(char* mas);
private:
	int end;
	int length;
};
