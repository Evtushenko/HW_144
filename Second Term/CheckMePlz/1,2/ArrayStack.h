#include "StackGeneral.h"

class ArrayStack : public StackGeneral  {
public:
	ArrayStack(): lengthArray(0), arrayStackElements(nullptr) {}
	~ArrayStack(); 
	void push(int number);
	int pop();
	void print() const;
	int getTop();
private:
int *arrayStackElements;
int lengthArray;
};