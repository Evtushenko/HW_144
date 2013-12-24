#include "HuffmanFunctions.h"

using fuctionsHuffman::Tree;
using fuctionsHuffman::Codes;

int fuctionsHuffman::strlen(char *s) {
	int length = 0;
	while (*s != '\0'){
		s = s + 1;
		length++;
	}
	return length;
}

void fuctionsHuffman::clearInt(int array [], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = 0;
	}
}

void fuctionsHuffman::clearChar(char array []) {
	for (int i = 0; i < strlen(array); i++) {
		array[i] = '\0';
	}
}

void fuctionsHuffman::sortBubble(int popular [], int chars [], int amount) {
	int t = 0;
	int tmp = 0;
	int i = 0;
	while (t < amount - 1) {
		t = 0;
		for (i = 0; i < amount - 1; i++) {
			if (popular[chars[i]] > popular[chars[i + 1]]) {
				tmp = chars[i];
				chars[i] = chars[i + 1];
				chars[i + 1] = tmp;
			}
			else {
				t++;
			}
		}
	}
}

Codes *fuctionsHuffman::createCodes() {
	Codes *pointerNew = new Codes;
	for (int i = 0; i < maxLengthCode; i++) {
		pointerNew->s[i] = -1;
	}
	return pointerNew;
}

Tree *fuctionsHuffman::createNode(int code, int popular) {
	Tree *newT = new Tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->next = nullptr;
	newT->parent = nullptr;
	newT->code = startCode;
	newT->priory = popular;
	newT->symbol = char(code);
	return newT;
}

void fuctionsHuffman::addEnd(int code, int popular, Tree **begin, Tree **end) {
	Tree *newT = createNode(code, popular);
	if (*begin == nullptr) {
		*begin = newT;
		*end = *begin;
	}
	else {
		(*end)->next = newT;
		*end = newT;
	}
}

Tree *fuctionsHuffman::addBefore(Tree **beginNode, Tree **endNode, int number, int symbol) {
	Tree *slot = *beginNode;
	Tree *newNode = createNode(symbol, number);
	while (slot) {
		if (slot->priory >= number) {
			break;
		}
		slot = slot->next;
	}
	if (slot != *beginNode) {
		Tree *rightList = *beginNode;
		while (rightList) {
			if (rightList->next == slot) {
				break;
			}
			rightList = rightList->next;
		}
		rightList->next = newNode;
	}
	newNode->next = slot;
	if (slot == *beginNode) {
		*beginNode = newNode;
	}
	if (slot == *endNode) {
		*endNode = newNode;
	}
	return newNode;
}

void fuctionsHuffman::printInc(Tree *root, char out []) {
	int static position = 0;
	if (!root) {
		return;
	}
	printInc(root->left, out);
	out[position] = root->symbol;
	position++;
	out[position] = ' ';
	position++;
	printInc(root->right, out);
}

void fuctionsHuffman::findC(Tree *root, char symbol, Tree **result) {
	if (!root) {
		return;
	}
	findC(root->left, symbol, &(*result));
	if (symbol == root->symbol) {
		*result = root;
	}
	findC(root->right, symbol, &(*result));
}

Tree *fuctionsHuffman::printAbc(Tree *root, char out [], int &position) {
	if (!root) {
		out[position] = emptyChar;
		position++;
		return root;
	}
	else{
		out[position] = '(';
		position++;
		out[position] = root->symbol;
		position++;
	}
	printAbc(root->left, out,position);
	printAbc(root->right, out,position);
	out[position] = ')';
	position++;
	return root;
}

Tree *fuctionsHuffman::freeMemory(Tree *root) {
	if (!root) {
		return root;
	}
	if (root->left == root->right)
	{
		delete root;
		return nullptr;
	}
	root->left = freeMemory(root->left);
	root->right = freeMemory(root->right);
	delete root;
	return nullptr;
}
