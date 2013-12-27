#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>

namespace fuctionsHuffman {
	int const rangeCharCodes = 200;
	int const maxLengthCode = 20;
	char const emptyChar = '0';
	int const startCode = 3;
	int const maxLengthOutString = 1000;
	int const maxBufferSize = 100;

	struct Tree {
		Tree *left;
		Tree *right;
		Tree *next;
		Tree *parent;
		int priory;
		char symbol;
		char code;
	};

	struct Codes {
		char s[maxLengthCode];
	};
	int strlen(char *s);
	void clearInt(int array [], int length);
	void clearChar(char array []);
	void sortBubble(int popular [], int chars [], int amount);
	Codes *createCodes();
	void addEnd(int code, int polular, Tree **begin, Tree **end);
	Tree *addBefore(Tree **beginNode, Tree **endNode, int number, int symbol);
	void printInc(Tree *root, char out []);
	void findC(Tree *root, char symbol, Tree **result);
	Tree *printAbc(Tree *root, char out [], int &position);
	Tree *freeMemory(Tree *root);
	Tree *createNode(int code, int polular);
	Tree *makeTree(int popular [], int chars [], int amountChars);
	void getCodes(Codes *pointersCodes [], int chars [], Tree *&rootTree, int amountChars);
}