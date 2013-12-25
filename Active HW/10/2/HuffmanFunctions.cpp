#include "HuffmanFunctions.h"

using fuctionsHuffman::Tree;
using namespace std;

int fuctionsHuffman::strlen(char *s) {
	int length = 0;
	while (*s != '\0'){
		s = s + 1;
		length++;
	}
	return length;
}

void fuctionsHuffman::clearChar(char array []) {
	for (int i = 0; i < strlen(array); i++) {
		array[i] = '\0';
	}
}

Tree *fuctionsHuffman::create(char symbol) {
	Tree *newT = new Tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->next = nullptr;
	newT->parent = nullptr;
	newT->symbol = symbol;
	return newT;
}

int fuctionsHuffman::buildTree(char TreeString [], Tree *points []) {
	int currentPoint = 0;
	Tree *currentNode = nullptr;
	for (int i = 0; i < strlen(TreeString); i++) {
		if ((i > 0) && (TreeString[i - 1] == '(')) {
			if (currentPoint == 0) {
				points[0] = create(TreeString[i]);
				currentPoint++;
				currentNode = points[0];
			}
			else {
				if (currentNode->left == nullptr) {
					points[currentPoint] = create(TreeString[i]);
					currentNode->left = points[currentPoint];
					points[currentPoint]->parent = currentNode;
					currentNode = points[currentPoint];
					currentPoint++;
				}
				else {
					points[currentPoint] = create(TreeString[i]);
					currentNode->right = points[currentPoint];
					points[currentPoint]->parent = currentNode;
					currentNode = points[currentPoint];
					currentPoint++;
				}
			}
		}

		if (TreeString[i] == ')') {
			currentNode = currentNode->parent;
		}
	}
	return currentPoint;
}

void fuctionsHuffman::traslate(char codeString [], Tree *points []) {
	ofstream outFile;
	outFile.open("out.txt", ios::out);
	char code[maxLengthCode];
	clearChar(code);
	int position = 0;
	for (int i = 0; i < strlen(codeString); i++) {
		if ((codeString[i] != ' ') && (codeString[i] != '.')) {
			code[position] = codeString[i];
			position++;
		}
		else {
			Tree *help = points[0];
			for (int j = 0; j < position; j++) {
				if (code[j] == emptyChar) {
					help = help->left;
				}
				else {
					help = help->right;
				}
			}
			outFile << help->symbol;
			cout << help->symbol;
			position = 0;
		}
	}
	cout << endl;

	outFile.close();
}