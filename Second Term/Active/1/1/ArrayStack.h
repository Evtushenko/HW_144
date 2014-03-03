#include "StackGeneral.h"

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