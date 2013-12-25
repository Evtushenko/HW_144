#include "HuffmanFunctions.h"

using namespace std;
using namespace fuctionsHuffman;

int main() {
	ifstream inFile;
	inFile.open("in.txt", ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	char treeString[maxBufferSize];
	clearChar(treeString);
	inFile.getline(treeString, maxBufferSize);
	for (int i = 0; i < strlen(treeString); i++) {
		cout << treeString[i];
	}
	cout << endl;

	char codeString[maxBufferSize] = { emptyInt };
	inFile.getline(codeString, maxBufferSize);
	codeString[strlen(codeString)] = '.';
	for (int i = 0; i < strlen(codeString); i++) {
		cout << codeString[i];
	}
	cout << endl;
	inFile.close();

	
	tree *points[maxBufferSize];
	for (int i = 0; i < maxBufferSize; i++) {
		points[i] = nullptr;
	}
	int currentPoint = buildTree(treeString, points);
	
	traslate(codeString, points);
	for (int i = 0; i < currentPoint; i++) {
		delete points[i];
	}
	return 0;
}