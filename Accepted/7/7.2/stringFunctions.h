#pragma once

#include <iostream>
#include <cstdlib>
#include <string.h>

int const siseBlocks = 5;
int const maxBufferSize = 100;

namespace listFunctions {

	struct strings {
		char string[siseBlocks];
		strings *next;
	};

	int strlen(char *s);
	void create(char s [], strings **begin, strings **end);
	bool same(char string [], strings *&begin, strings *&end);
	char *transform(strings *&begin, int const length);
	char *halfString(char m [], int  start, int finish);
	void addChar(strings **end, int length, char symbol);
	void clone(strings *& begin, strings ** end, int length);
	int plusS(strings **end, int length);
	void print(strings *&begin);
	void freeMemory(strings *&begin);
}