#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>

namespace fuctionsHuffman {
	int const maxBufferSize = 100;
	int const maxLengthCode = 20;
	char const emptyChar = '0';
	int const emptyInt = -1;

	struct tree {
		tree *left;
		tree *right;
		tree *next;
		tree *parent;
		char symbol;
	};

	int strlen(char *s);
	void clearChar(char array []);
	tree *create(char symbol);
}