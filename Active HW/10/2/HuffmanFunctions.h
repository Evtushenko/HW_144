#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>

namespace fuctionsHuffman {
	int const maxBufferSize = 100;
	int const maxLengthCode = 20;
	char const emptyChar = '0';
	int const emptyInt = -1;

	struct Tree {
		Tree *left;
		Tree *right;
		Tree *next;
		Tree *parent;
		char symbol;
	};

	int strlen(char *s);
	void clearChar(char array []);
	Tree *create(char symbol);
	int buildTree(char TreeString [], Tree *points []);
	void traslate(char codeString [], Tree *points []);
}