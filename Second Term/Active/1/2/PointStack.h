#include "StackGeneral.h"

class PointStack : public StackGeneral {
public:
	PointStack() : top(nullptr) {}
	~PointStack();
	void push(int number);
	int pop();
	void print() const;
	int infix(char stringIn []);
private:
	StackStruct *top;
	int calculateStack(char stringOut []);
};
