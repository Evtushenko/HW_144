#include "stack.h"

using namespace std;

int main()
{
	myStacks* left = new pointStack();
	myStacks* right = new massiveStack();
	int const length = 100;
	char* mas = new char[length];
	cin.getline(mas, length);
	cout << right->infix(mas) << endl;

	return 0;
}

