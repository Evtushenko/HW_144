#include "StackGeneral.h"

class PointStack : public StackGeneral {
public:
	PointStack() : top(nullptr) {}
	~PointStack();
	void push(int number);
	int pop();
	void print() const;
	int getTop();
private:
	StackStruct *top;
};
