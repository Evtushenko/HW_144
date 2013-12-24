#include "calcTreeFunctions.h"

using namespace std;
using namespace functions;

int main() {
	cout << "Warning! For supporting numbers over 9 I used extra()\nso u need write like this\n";
	cout << "(/(+(2)(-(1)(0)))(3))\n";
	cout << "\nuse:\nin.txt\n\n";
	ifstream inFile1;
	inFile1.open("in.txt", ios::in);
	if (!(inFile1.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	char str[maxBufferSize];
	clearChar(str, maxBufferSize);
	inFile1.getline(str, maxBufferSize);
	addTree(str);
	inFile1.close();
	return 0;
}