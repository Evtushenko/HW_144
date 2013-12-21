#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

namespace fuctionsHuffman {
	int const rangeCharCodes = 200;
	int const maxLengthCode = 20;
	char const emptyChar = '0';
	int const startCode = 3;
	int const maxLengthOutString = 1000;
	int const maxBufferSize = 100;

	struct tree {
		tree *left;
		tree *right;
		tree *next;
		tree *parent;
		int priory;
		char symbol;
		char code;
	};

	struct codes {
		char s[maxLengthCode];
	};

	void clearInt(int array [], int length);
	void clearChar(char array []);
	void sortBubble(int popular [], int chars [], int amount);
	codes *createCodes();
	void addEnd(int code, int polular, tree **begin, tree **end);
	tree *create(int code, int polular);
	tree *addBefore(tree **beginNode, tree **endNode, int number, int symbol);
	void printInc(tree *root, char out []);
	void findC(tree *root, char symbol, tree **result);
	tree *printAbc(tree *root, char out []);
	tree *freeMemory(tree *root);
}