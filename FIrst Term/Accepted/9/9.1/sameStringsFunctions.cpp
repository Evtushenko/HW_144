#include "sameStringsFunctions.h"

using functions::Word;
using namespace std;

int functions::strlen(char *s) {
	int length = 0;
	while (*s != '\0'){
		s = s + 1;
		length++;
	}
	return length;
}

Word *functions::create(char s []) {
	Word *creature = new Word;
	int i = 0;
	for (i; i < strlen(s); i++) {
		creature->word[i] = s[i];
	}
	creature->word[i + 1] = '\0';
	creature->next = nullptr;
	return creature;
}

void functions::addEnd(Word *&last, char s []) {
	Word *creature = new Word;
	int i = 0;
	for (i; i < strlen(s); i++) {
		creature->word[i] = s[i];
	}
	creature->word[i + 1] = '\0';
	creature->next = nullptr;
	last->next = creature;
}

Word *functions::findLast(Word *&first) {
	Word *helper = first;
	while (helper->next) {
		helper = helper->next;
	}
	return helper;
}

int functions::hashCount(char string []) {
	int result = 0;
	for (int i = 0; string[i] != '\0'; ++i) {
		result = (result + string[i]) % amount;
	}
	return result;
}

Word *functions::same(Word *&first, char s []) {
	Word *help = first;
	while (help) {
		bool correct = true;
		int i = 0;
		while (s[i] != '\0') {
			if (help->word[i] != s[i]) {
				correct = false;
				break;
			}
			i++;
		}
		if (correct) {
			return help;
		}
		help = help->next;
	}
	return nullptr;
}

void functions::memoryFree(Word *hashRange []) {
	Word *slot = nullptr;
	for (int i = 0; i < amount; i++) {
		while (hashRange[i]) {
			slot = hashRange[i];
			hashRange[i] = hashRange[i]->next;
			delete slot;
		}
	}
}

void functions::del(Word **beginNode, Word *&pkey) {
	Word *start = *beginNode;
	if (start == pkey) {
		*beginNode = nullptr;
		delete start;
	}
	else {
		bool found = false;
		while (start->next) {
			if (start->next == pkey) {
				found = true;
				break;
			}
			start = start->next;
		}
		if (found) {
			start->next = (pkey)->next;
			delete pkey;
		}
	}
}

int functions::writeHashTable(Word *hashRange []) {
	ifstream inFile1;
	inFile1.open("1.txt", ios::in);
	if (!(inFile1.is_open())) {
		cout << "Where is your file ???" << endl;
		return 1;
	}
	char *line = new char[maxLengthWord];
	Word *slot = nullptr;
	int valueHash = 0;

	// записали в хэш таблицу //
	while (inFile1.good()) {
		inFile1.getline(line, maxLengthWord);
		valueHash = hashCount(line);
		if (hashRange[valueHash] == nullptr) {
			hashRange[valueHash] = create(line);
		}
		else {
			if (same(hashRange[valueHash], line) == nullptr) {
				slot = findLast(hashRange[valueHash]);
				addEnd(slot, line);
			}
		}
	}
	delete line;
	inFile1.close();
	return 0;
}

int functions::compareFiles(Word *hashRange []) {
	ifstream inFile2;
	ofstream outFile;
	outFile.open("out.txt", ios::out);
	inFile2.open("2.txt", ios::in);
	if (!(inFile2.is_open())) {
		cout << "Where is your file ???" << endl;
		return 1;
	}
	Word *slot = nullptr;
	char *line = new char[maxLengthWord];
	int valueHash = 0;
	while (inFile2.good()) {
		inFile2.getline(line, maxLengthWord);
		valueHash = hashCount(line);
		slot = same(hashRange[valueHash], line);
		if (slot) {
			outFile << line << "\n";
			del(&hashRange[valueHash], slot);
		}
	}

	delete line;
	inFile2.close();
	outFile.close();
	return 0;
}