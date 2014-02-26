#include <stdlib.h>
#include <cstring>
#include <stdio.h>

int const primeNumber = 3;
int const amount = 10000;
int const wordLen = 25;
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */

struct Word {
	char word[wordLen];
	Word *next;
	int amount;
	int length;
};

Word *create(char s []) {
	Word *creature = (Word *) malloc(sizeof(Word));
	int i = 0;
	for (i; i < strlen(s); i++) {
		creature->word[i] = s[i];
	}
	creature->word[i + 1] = '\0';
	creature->next = nullptr;
	creature->amount = 1;
	creature->length = strlen(s);
	return creature;
}

void addEnd(Word *&last, char s []) {
	Word *creature = (Word *) malloc(sizeof(Word));
	int i = 0;
	for (i; i < strlen(s); i++) {
		creature->word[i] = s[i];
	}
	creature->word[i + 1] = '\0';
	creature->next = nullptr;
	creature->amount = 1;
	creature->length = strlen(s);
	last->next = creature;
}

Word *findLast(Word *&first){
	Word *helper = first;
	while (helper->next) {
		helper = helper->next;
	}
	return helper;
}

int calcLength(Word *&begin) {
	int answer = 0;
	Word *helper = begin;
	while (helper) {
		answer++;
		helper = helper->next;
	}
	return answer;
}

int hashCount(char string []) {
	int result = 0;
	for (int i = 0; string[i] != '\0'; ++i)
		result = (result + string[i]) % amount;
	return result;
}

int hashCount2(char word [])
{
	int seed = 131;
	unsigned long hash = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		hash = (hash * seed) + word[i];
	}
	return hash % amount;
}

unsigned hashCount3(const char s [])
{
	unsigned h = 31 /* also prime */;
	while (*s) {
		h = (h * A) ^ (s[0] * B);
		s++;
	}
	return int(h % amount); // or return h % C;
}

bool findSame(Word *&begin, char buffer []) {
	Word *slot = begin;
	while (slot) {
		int position = 0;
		bool result = true;
		if (slot->length == strlen(buffer)) {
			while (slot->word[position + 1] != '\0'){
				if (slot->word[position] != buffer[position]) {
					result = false;
					break;
				}
				position++;
			}
		}
		else {
			result = false;
		}
		if (result) {
			slot->amount++;
			return true;
		}
		slot = slot->next;
	}
	return false;
}

void printMax(Word *&begin) {
	Word *slot = begin;
	while (slot) {
		int position = 0;
		while (slot->word[position + 1] != '\0') {
			printf("%c", slot->word[position]);
			position++;
		}
		slot = slot->next;
		printf("\n");
	}
}

bool correct(char a []) {
	if (strlen(a) == 1) {
		if ((a[0] >= 'a' && a[0] <= 'z') || (a[0] >= 'A' && a[0] <= 'Z'))
			return true;
	}
	for (int i = 0; i < strlen(a) - 1; i++) {
		if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')))
			return false;
	}
	if (a[strlen(a) - 1] != '.' && a[strlen(a) - 1] != ',' && a[strlen(a) - 1] != '?' && a[strlen(a) - 1] != '!' && (!((a[0] >= 'a' && a[0] <= 'z') || (a[0] >= 'A' && a[0] <= 'Z'))))
		return false;
	return true;
}

bool sign(char a) {
	return (a == '.') || (a == ',') || (a == '!') || (a == '?');
}

int MakeHashTable(int &amountReadedWords, Word *hashRange []) {
	FILE *inFile1;
	if (fopen_s(&inFile1, "1.txt", "r")){
		printf("\nCant find file\n");
		return 0;
	}
	Word *slot = nullptr;
	char buffer[wordLen] = { -1 };
	int valueHash = 0;
	char *line = new char[10000];
	while (fgets(line, 10000, inFile1) != nullptr) {
		char word[30] = { -1 };
		int position = 0;
		for (int i = 0; i < strlen(line); i++) {
			if (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t') {
				word[position] = line[i];
				position++;
			}
			else {
				if (correct(word)) {
					if (sign(word[strlen(word) - 1])) {
						word[strlen(word) - 1] = '\0';
					}
					word[position] = '\0';
					amountReadedWords++;
					valueHash = hashCount(word);
					if (hashRange[valueHash] == nullptr) {
						hashRange[valueHash] = create(word);
					}
					else {
						if (!findSame(hashRange[valueHash], word)) {
							slot = findLast(hashRange[valueHash]);
							addEnd(slot, word);
						}
					}
				}
				position = 0;
			}
		}

	}
	fclose(inFile1);
	return 1;
}

void clearMemory(Word *hashRange []) {
	Word *slot11 = nullptr;
	Word *slot2 = nullptr;
	Word *slot1 = nullptr;
	for (int i = 0; i < amount; i++) {
		if (hashRange[i] != nullptr) {
			slot1 = hashRange[i];
			while (slot11) {
				slot2 = slot11;
				slot11 = slot11->next;
				free(slot2);
			}
		}
	}
}

void printStatic(int amountReadedWords, Word *hashRange []){
	int amountVacant = 0;
	int maxLength = 0;
	int midLength = 0;
	int curLength = 0;
	int amountUniq = 0;
	int amountHit = 0;
	Word *hitPointer = nullptr;
	Word *maxLenPoint = nullptr;
	long long sumLength = 0;
	for (int i = 0; i < amount; i++) {
		if (hashRange[i] != nullptr) {
			amountVacant++;
			amountUniq++;
			Word *slot1 = hashRange[i];
			if (hashRange[i]->amount > amountHit) {
				amountHit = hashRange[i]->amount;
				hitPointer = hashRange[i];
			}
			while (slot1->next) {
				amountUniq++;
				if (slot1->amount > amountHit) {
					amountHit = slot1->amount;
					hitPointer = slot1;
				}
				slot1 = slot1->next;
			}
			curLength = calcLength(hashRange[i]);
			if (curLength > maxLength) {
				maxLength = curLength;
				maxLenPoint = hashRange[i];
			}
			sumLength = sumLength + curLength;
		}
	}

	double loadFactor = (double(amountVacant) / double(amount));
	printf("amount readed words %d\n\n", amountReadedWords);
	printf("amount uniq words %d\n\n", amountUniq);
	printf("amount free slots %d\n\n", amount - amountVacant);
	midLength = sumLength / amountVacant;
	printf("max length %d\n", maxLength);
	printf("words:\n");
	printMax(maxLenPoint);
	printf("\n");
	printf("mid length %d\n\n", midLength);
	printf("load factor %.4lf\n\n", loadFactor);
	printf("Hit word %d time '", amountHit);
	Word *slot1 = hitPointer;
	int position = 0;
	while (slot1->word[position + 1] != '\0') {
		printf("%c", slot1->word[position]);
		position++;
	}
	printf("'\n\n");
}

int main() {
	printf("using:\n1.txt\nout.txt\n\n");
	int amountReadedWords = 0;
	Word *hashRange[amount];
	for (int i = 0; i < amount; i++) {
		hashRange[i] = nullptr;
	}
	if (MakeHashTable(amountReadedWords, hashRange) == 0)
		return 0;
	clearMemory(hashRange);
	printStatic(amountReadedWords, hashRange);
	return 0;
}