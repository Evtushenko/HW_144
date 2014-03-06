#include "console.h"

using namespace std;

void Console::outPrint() {
	readFromFile();
	printIn();
	this->spiralOrder();
	cout << "\nconsole spiral order:\n";
	for (int i = 0; i < amountElements * amountElements ; i++)
		cout << queuePrinting[i] << " ";
	cout << endl;
}