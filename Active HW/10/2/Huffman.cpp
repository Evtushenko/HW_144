#include "HuffmanFunctions.h"

using namespace std;
using namespace fuctionsHuffman;

int main() {
	ifstream inFile;
	ofstream outFile;
	inFile.open("in.txt", ios::in);
	outFile.open("out.txt", ios::out);
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

	int currentPoint = 0;
	tree *currentNode = nullptr;
	tree *points[maxBufferSize];
	for (int i = 0; i < maxBufferSize; i++)
		points[i] = nullptr;
	for (int i = 0; i < strlen(treeString); i++) {
		if ((i > 0) && (treeString[i - 1] == '(')) {
			if (currentPoint == 0) {
				points[0] = create(treeString[i]);
				currentPoint++;
				currentNode = points[0];
			}
			else {
				if (currentNode->left == nullptr) {
					points[currentPoint] = create(treeString[i]);
					currentNode->left = points[currentPoint];
					points[currentPoint]->parent = currentNode;
					currentNode = points[currentPoint];
					currentPoint++;
				}
				else {
					points[currentPoint] = create(treeString[i]);
					currentNode->right = points[currentPoint];
					points[currentPoint]->parent = currentNode;
					currentNode = points[currentPoint];
					currentPoint++;
				}
			}
		}

		if (treeString[i] == ')') {
			currentNode = currentNode->parent;
		}
	}

	char code[maxLengthCode];
	clearChar(code);
	int position = 0;
	for (int i = 0; i < strlen(codeString); i++) {
		if ((codeString[i] != ' ') && (codeString[i] != '.')) {
			code[position] = codeString[i];
			position++;
		}
		else {
			tree *help = points[0];
			for (int j = 0; j < position; j++) {
				if (code[j] == emptyChar)
					help = help->left;
				else
					help = help->right;
			}
			outFile << help->symbol;
			cout << help->symbol;
			position = 0;
		}
	}
	cout << endl;

	outFile.close();
	for (int i = 0; i < currentPoint; i++) {
		delete points[i];
	}
	return 0;
}