#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <stdio.h>

namespace listFunctions {
	int const primeNumber = 3;
	int const amount = 10000;
	int const wordLen = 25;

	struct Word {
		char word[wordLen];
		Word *next;
		int amount;
		int length;
	};

	Word *create(char s []);
	void addEnd(Word *&last, char s []);
	Word *findLast(Word *&first);
	int calcLength(Word *&begin);
	int hashCount(char string []);
	bool findSame(Word *&begin, char buffer []);
	void printMax(Word *&begin);
	int writeHastTable(Word *hashRange [], int &amountReadedWords);
	void freeMemory(Word *hashRange []);
	void printStatic(Word *hashRange [], int amountReadedWords);
}