#include "stringFunctions.h"

using namespace std;
using namespace listFunctions;

int main() {
	cout << "using:\n1.txt\nout.txt\n";
	int amountReadedWords = 0;
	Word *hashRange[amount];
	writeHastTable(hashRange, amountReadedWords);
	printStatic(hashRange,amountReadedWords);
	freeMemory(hashRange);
	return 0;
}