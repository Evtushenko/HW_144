#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

namespace functions {
	int const primeNumber = 3;
	int const amount = 10000;
	int const maxLengthWord = 100;

	struct Word {
		char word[maxLengthWord];
		Word *next;
	};

	int strlen(char *s);
	Word *create(char s []);
	void addEnd(Word *&last, char s []);
	Word *findLast(Word *&first);
	int hashCount(char string []);
	Word *same(Word *&first, char s []);
	void memoryFree(Word *hashRange []);
	void del(Word **beginNode, Word *&pkey);

}