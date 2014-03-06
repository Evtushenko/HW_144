#include "ListGeneral.h"

class ArrayList : public ListGeneral  {
public:
	ArrayList(): lengthArray(0) {}
	~ArrayList(); 
	void push(int number);
	int pop();
	void print() const;
private:
int *ArrayListElements;
int lengthArray;
};