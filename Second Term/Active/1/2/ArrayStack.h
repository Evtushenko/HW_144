#include "StackGeneral.h"

class ArrayStack : public StackGeneral  {
public:
	ArrayStack(): lengthArray(0) {}
	~ArrayStack(); 
	void push(int number);
	int pop();
	void print() const;
	int infix(char stringIn []);
	int calculateStack(char stringOut []);
private:
int *arrayStackElements;
int lengthArray;
};