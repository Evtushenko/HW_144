#include "StackGeneral.h"

class ArrayStack : public StackGeneral  {

public:
	ArrayStack(): arrayStackElements(nullptr), lengthArray(0) {}
	~ArrayStack(); 
	void push(int number);
	int pop();
	void print() const;
	int getTop();

private:
	int *arrayStackElements;
	int lengthArray;
};