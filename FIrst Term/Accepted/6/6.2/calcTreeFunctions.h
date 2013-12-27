#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <cmath>

namespace functions {
	int const maxBufferSize = 100;
	int const maxNumberLength = 10;

	struct Tree {
		Tree *left;
		Tree *right;
		Tree *previous;
		int value;
		char function;
	};

	void clearChar(char s [], int length);
	void calc(Tree *&node);
	void printAbc(Tree *root);
	void calcHelp(Tree *root);
	Tree *newTree(int value, char symbol);
	int getInt(int &position, const char s []);
	bool isFunction(char c);
	bool isDigit(char c);
	void addTree(const char s []);
}