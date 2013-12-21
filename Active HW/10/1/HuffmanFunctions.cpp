#include "HuffmanFunctions.h"

using fuctionsHuffman::tree;
using fuctionsHuffman::codes;


void fuctionsHuffman::clearInt(int array [], int length) {
	for (int i = 0; i < length; i++)
		array[i] = 0;
}

void fuctionsHuffman::clearChar(char array []) {
	for (int i = 0; i < strlen(array); i++)
		array[i] = '\0';
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
			else
				t++;
		}
	}
}

codes *fuctionsHuffman::createCodes() {
	codes *pointerNew = new codes;
	for (int i = 0; i < maxLengthCode; i++) {
		pointerNew->s[i] = -1;
	}
	return pointerNew;
}

void fuctionsHuffman::addEnd(int code, int polular, tree **begin, tree **end) {
	if (*begin == nullptr) {
		tree *newT = new tree;
		newT->left = nullptr;
		newT->right = nullptr;
		newT->next = nullptr;
		newT->parent = nullptr;
		newT->code = startCode;
		newT->priory = polular;
		newT->symbol = char(code);
		*begin = newT;
		*end = *begin;
	}
	else {
		tree *newT = new tree;
		newT->left = nullptr;
		newT->right = nullptr;
		newT->next = nullptr;
		newT->parent = nullptr;
		newT->code = startCode;
		newT->priory = polular;
		newT->symbol = char(code);
		(*end)->next = newT;
		*end = newT;
	}
}

tree *fuctionsHuffman::create(int code, int polular) {
	tree *newT = new tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->next = nullptr;
	newT->parent = nullptr;
	newT->code = startCode;
	newT->priory = polular;
	newT->symbol = char(code);
	return newT;
}

tree *fuctionsHuffman::addBefore(tree **beginNode, tree **endNode, int number, int symbol) {
	tree *slot = *beginNode;
	tree *newNode = new tree;
	newNode->priory = number;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->next = nullptr;
	newNode->parent = nullptr;
	newNode->code = startCode;
	newNode->symbol = char(symbol);
	while (slot) {
		if (slot->priory >= number)
			break;
		slot = slot->next;
	}
	if (slot != *beginNode) {
		tree *rightList = *beginNode;
		while (rightList) {
			if (rightList->next == slot)
				break;
			rightList = rightList->next;
		}
		rightList->next = newNode;
	}
	newNode->next = slot;
	if (slot == *beginNode)
		*beginNode = newNode;
	if (slot == *endNode)
		*endNode = newNode;
	return newNode;
}

void fuctionsHuffman::printInc(tree *root, char out []) {
	int static position = 0;
	if (!root)
		return;
	printInc(root->left, out);
	out[position] = root->symbol;
	position++;
	out[position] = ' ';
	position++;
	printInc(root->right, out);
}

void fuctionsHuffman::findC(tree *root, char symbol, tree **result) {
	if (!root)
		return;
	findC(root->left, symbol, &(*result));
	if (symbol == root->symbol) {
		*result = root;
	}
	findC(root->right, symbol, &(*result));
}

tree *fuctionsHuffman::printAbc(tree *root, char out []) {
	int static position = 0;
	if (!root) {
		out[position] = ' ';
		position++;
		out[position] = 'n';
		position++;
		out[position] = 'u';
		position++;
		out[position] = 'l';
		position++;
		out[position] = 'l';
		position++;
		return root;
	}
	else{
		out[position] = '(';
		position++;
		out[position] = root->symbol;
		position++;
	}
	printAbc(root->left, out);
	printAbc(root->right, out);
	out[position] = ')';
	position++;
	return root;
}

tree *fuctionsHuffman::freeMemory(tree *root) {
	if (!root)
		return root;
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


