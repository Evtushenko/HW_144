#include "stringFunctions.h"

using namespace std;
using listFunctions::strings;

int listFunctions::strlen(char *s) {
	int length = 0;
	while (*s != '\0'){
		s = s + 1;
		length++;
	}
	return length;
}

void listFunctions::create(char s [], strings **begin, strings **end) {
	for (int i = 0; i < strlen(s); i++) {
		if (i % siseBlocks == 0) {
			if (*begin == nullptr) {
				strings *newS = new strings;
				for (int j = 0; j < siseBlocks; j++) {
					newS->string[j] = -1;
				}
				newS->next = nullptr;
				*begin = newS;
				*end = newS;
			}
			else {
				strings *newS = new strings;
				newS->next = nullptr;
				for (int j = 0; j < siseBlocks; j++) {
					newS->string[j] = -1;
				}
				(*end)->next = newS;
				*end = newS;
			}
		}
		(*end)->string[i % siseBlocks] = s[i];
	}
}

bool listFunctions::same(char string [], strings *&begin, strings *&end) {
	strings *slot = begin;
	int position = 0;
	while (slot) {
		for (int i = 0; i < siseBlocks; i++) {
			if (slot->string[i] != -1) {
				if (slot->string[i] != string[position])
					return false;
				position++;
			}
		}
		slot = slot->next;
	}
	return true;
}

char *listFunctions::transform(strings *&begin, int const length) {
	char *s = new char[length];
	strings *slot = begin;
	int position = 0;
	while (slot) {
		for (int i = 0; i < siseBlocks; i++) {
			if (slot->string[i] != -1) {
				s[position] = slot->string[i];
				position++;
			}
		}
		slot = slot->next;
	}
	s[position] = '\0';
	return s;
}

char *listFunctions::halfString(char m [], int  start, int finish) {
	char *s = new char[finish - start + 1];
	for (int i = start; i <= finish; i++) {
		s[i - start] = m[i];
		if (i == finish) {
			s[i - start + 1] = '\0';
		}
	}
	return s;
}

void listFunctions::addChar(strings **end, int length, char symbol) {
	if (length % siseBlocks == 0) {
		strings *newS = new strings;
		for (int j = 0; j < siseBlocks; j++) {
			newS->string[j] = -1;
		}
		newS->next = nullptr;
		(*end)->next = newS;
		*end = newS;
	}
	(*end)->string[length % siseBlocks] = symbol;
}

void listFunctions::clone(strings *& begin, strings ** end, int length) {
	int oldLength = length;
	int position = 0;

	strings *slot = begin;
	bool stop = false;
	while (position < oldLength) {
		for (int i = 0; i < siseBlocks && position < oldLength; i++) {
			if (slot->string[i] != -1) {
				addChar(&*end, length, slot->string[i]);
				length++;
				position++;
			}
			else {
				stop = true;
				break;
			}
		}
		if (stop)
			break;
		slot = slot->next;
	}
}

int listFunctions::plusS(strings **end, int length) {
	char buffer[maxBufferSize] = { -1 };
	cout << "enter the string\n";
	cin >> buffer;
	for (int i = 0; i < strlen(buffer); i++) {
		addChar(&*end, length, buffer[i]);
		length++;
	}
	return length;
}

void listFunctions::print(strings *&begin) {
	strings *begin1 = begin;
	while (begin1) {
		for (int i = 0; i < siseBlocks; i++) {
			if (begin1->string[i] != -1)
				cout << begin1->string[i];
		}
		begin1 = begin1->next;
	}
	cout << endl;
}

void listFunctions::freeMemory(strings *&begin) {
	strings *slot = begin;
	while (begin) {
		slot = begin;
		begin = begin->next;
		delete slot;
	}
	delete begin;
}