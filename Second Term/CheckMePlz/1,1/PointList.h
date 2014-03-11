#include "ListGeneral.h"

class PointList : public ListGeneral {
public:
	PointList() : begin(nullptr), end(nullptr) {}
	~PointList();
	void push(int number);
	int pop();
	void print() const;
private:
	StackStruct *begin;
	StackStruct *end;
};