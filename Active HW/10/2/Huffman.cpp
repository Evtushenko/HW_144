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

	char TreeString[maxBufferSize];
	clearChar(TreeString);
	inFile.getline(TreeString, maxBufferSize);
	for (int i = 0; i < strlen(TreeString); i++) {
		cout << TreeString[i];
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


	Tree *points[maxBufferSize];
	for (int i = 0; i < maxBufferSize; i++) {
		points[i] = nullptr;
	}
	int currentPoint = buildTree(TreeString, points);

	traslate(codeString, points);
	for (int i = 0; i < currentPoint; i++) {
		delete points[i];
	}
	return 0;
}