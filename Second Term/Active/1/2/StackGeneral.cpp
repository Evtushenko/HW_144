#include "StackGeneral.h"

StackGeneral ::StackGeneral () {
}

StackGeneral ::~StackGeneral () {
}

bool StackGeneral::firstPriority(char a) const{
	return a == '*' || a == '/';
}