#include "sameStringsFunctions.h"

using namespace std;
using namespace functions;

int main() {
	cout << "using:\n1.txt\n2.txt\nout.txt\n";
	ifstream inFile1;
	ifstream inFile2;
	ofstream outFile;
	outFile.open("out.txt", ios::out);
	inFile1.open("1.txt", ios::in);
	if (!(inFile1.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	inFile2.open("2.txt", ios::in);
	if (!(inFile2.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	Word *hashRange[amount];
	for (int i = 0; i < amount; i++) {
		hashRange[i] = nullptr;
	}

	char *line = new char[maxLengthWord];
	Word *slot = nullptr;
	int valueHash = 0;

	// записали в хэш таблицу //
	while (inFile1.good()) {
		inFile1.getline(line, maxLengthWord);
		valueHash = hashCount(line);
		if (hashRange[valueHash] == nullptr) {
			hashRange[valueHash] = create(line);
		}
		else {
			if (same(hashRange[valueHash], line) == nullptr) {
				slot = findLast(hashRange[valueHash]);
				addEnd(slot, line);
			}
		}
	}

	slot = nullptr;
	while (inFile2.good()) {
		inFile2.getline(line, maxLengthWord);
		valueHash = hashCount(line);
		slot = same(hashRange[valueHash], line);
		if (slot) {
			outFile << line << "\n";
			del(&hashRange[valueHash], slot);
		}
	}

	inFile1.close();
	inFile2.close();
	outFile.close();
	memoryFree(hashRange);
	delete line;
	return 0;
}