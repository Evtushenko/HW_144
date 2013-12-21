#include "HuffmanFunctions.h"

using fuctionsHuffman::tree;

void fuctionsHuffman::clearChar(char array []) {
	for (int i = 0; i < strlen(array); i++)
		array[i] = '\0';
}

tree *fuctionsHuffman::create(char symbol) {
	tree *newT = new tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->next = nullptr;
	newT->parent = nullptr;
	newT->symbol = symbol;
	return newT;
}
