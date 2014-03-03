#include "StackGeneral.h"
#include "ArrayStack.h"
#include "PointStack.h"

using namespace std;

int main() {
	
	StackGeneral* bubble = new PointStack();
	StackGeneral* bead = new ArrayStack();

	char input[maxBufferSize];
	for (int i = 0; i < maxBufferSize; i++)
		input[i] = '\0';
	cout << "enter the expressions:\n";
	cin.getline(input,maxBufferSize);
	cout << "Point Stack:\n";
	bubble->infix(input);
	cout << endl;
	cout << "Array Stack:\n";
	bead->infix(input);
	cout << endl;

	delete bubble;
	delete bead;
	return 0;
}