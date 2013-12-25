#include "sameStringsFunctions.h"

using namespace std;
using namespace functions;

int main() {
	cout << "using:\n1.txt\n2.txt\nout.txt\n";

	Word *hashRange[amount];
	for (int i = 0; i < amount; i++) {
		hashRange[i] = nullptr;
	}

	if (writeHashTable(hashRange) == 1) {
		cout << "error!\n";
		return 1;
	}
	if (compareFiles(hashRange) == 1) {
		cout << "error!\n";
		return 1;
	}
	memoryFree(hashRange);
	return 0;
}