#include "ListGeneral.h"

class ArrayList : public ListGeneral  {
public:
	ArrayList(): ArrayListElements(nullptr), lengthArray(0) {}
	~ArrayList(); 
	void push(int number);
	int pop();
	void print() const;
private:
	int *ArrayListElements;
	int lengthArray;
};