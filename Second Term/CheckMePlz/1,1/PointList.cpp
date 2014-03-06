#include "PointList.h"

using namespace std;

PointList ::~PointList (){
	while (begin) {
		StackStruct* newS = begin;
		begin = begin->next;
		delete newS;
	}
}

void PointList::push(int number){
	StackStruct* newS = new StackStruct;
	newS->value = number;
	newS->next = nullptr;
	if (!begin) {
		begin = newS;
		end = newS;
	}
	else {
		end -> next = newS;
		end = newS;
	}
};

void PointList::print() const {
	cout << "List of  Point Stack:\n";
	StackStruct* newS = begin;
	while (newS) {
		cout << newS->value << " ";
		newS = newS->next;
	}
	cout << endl;
}

int  PointList::pop()  {
	if (!begin)
		return -1;
	int answer = begin->value;
	begin = begin-> next;
	return answer;
}
