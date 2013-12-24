#include "floatFunctions.h"

using namespace std;
using namespace fuctionsFloat;

int main() {
	char  stringIn[maxBufferSize];
	for (int i = 0; i < strlen(stringIn); i++) {
		stringIn[i] = '\0';
	}
	cout << "enter the string\n";
	cin.getline(stringIn, maxBufferSize);
	if (checkFloat(stringIn)) {
		cout << "\n\n it may be float \n";
	}
	else {
		cout << "\n\n it is not float\n";
	}
	return 0;
}