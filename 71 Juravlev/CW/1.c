#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int const lengthAlphabet = 26;
int const maxLengthRoot = 8;
int const minLengthRoot = 3;
int const maxSymbolsKeepingComponents = 30;
int const minAmountComponents = 1;
int const maxAmountComponents = 3;

void clear(char s []) {
	for (int i = 0; i < strlen(s); i++) {
		s[i] = '\0';
	}
}


bool letter(char a) {
	return int(a) >= int('a') && int(a) <= int('z');
}

int readSuffixesPrexixes(char suffixes [], char prefixes [], int amountSuffix, int amountPrefix) {
	FILE *file;
	if (fopen_s(&file, "suf.txt", "r")){
		printf("\nCant find suf.txt \n");
		return 1;
	}

	char line[maxSymbolsKeepingComponents / 3];
	clear(line);
	int index = 0;
	int positionS = 0;
	while (fgets(line, maxSymbolsKeepingComponents / 3, file) != nullptr && index < amountSuffix) {
		index++;
		for (int i = 0; i < strlen(line); i++) {
			if (letter(line[i])) {
				suffixes[positionS] = line[i];
				positionS++;
			}
		}
		suffixes[positionS] = '?';
		positionS++;
	}
	fclose(file);

	positionS = 0;
	if (fopen_s(&file, "pre.txt", "r")){
		printf("\nCant find pre.txt \n");
		return 1;
	}

	while (fgets(line, maxSymbolsKeepingComponents / 3, file) != nullptr && index < amountSuffix + amountPrefix) {
		index++;
		for (int i = 0; i < strlen(line); i++) {
			if (letter(line[i])) {
				prefixes[positionS] = line[i];
				positionS++;
			}
		}
		prefixes[positionS] = '?';
		positionS++;
	}
	fclose(file);
	return 0;
}

int printingWords(char suffixes [], char prefixes [], int amountSuffix, int amountPrefix, int amountWords) {
	int lengthRoot = rand() % (maxLengthRoot + 1 - minLengthRoot) + minLengthRoot;
	printf("length of word %d\n", lengthRoot);
	char root[maxLengthRoot+1];
	clear(root);
	for (int i = 0; i < lengthRoot; i++) {
		root[i] = char(rand() % lengthAlphabet + int('a'));
	}
	root[lengthRoot] = '\0';
	int wordNumber = 1;
	printf("\nlist of words:\n\n1.");
	for (int i = 0; i < lengthRoot; i++) {
		printf("%c", root[i]);
	}
	printf("(root)\n");

	int posP = 0;
	int posS = 0;
	int currentAmountPrefix = 0;
	int currentAmountSuffix = 0;

	while (currentAmountPrefix < amountPrefix && wordNumber < amountWords) {
		char string[maxSymbolsKeepingComponents] = { '\0' };
		int positionString = 0;

		printf("%d.", ++wordNumber);
		while (prefixes[posP] != '?' && prefixes[posP] != '\0') {
			printf("%c", prefixes[posP]);
			string[positionString] = prefixes[posP];
			positionString++;
			posP++;
		}
		posP++;
		printf("-");
		string[positionString] = '-';
		positionString++;
		for (int i = 0; i < lengthRoot; i++) {
			string[positionString] = root[i];
			positionString++;
			printf("%c", root[i]);
		}
		printf("\n");
		currentAmountPrefix++;
		int posS2 = 0;
		int currentAmountSuffix2 = 0;
		while (currentAmountSuffix2 < amountSuffix && wordNumber < amountWords) {
			printf("%d.", ++wordNumber);
			for (int i = 0; i < strlen(string); i++) {
				printf("%c", string[i]);
			}
			printf("-");
			while (suffixes[posS2] != '?' && suffixes[posS2] != '\0') {
				printf("%c", suffixes[posS2]);
				posS2++;
			}
			posS2++;
			printf("\n");
			currentAmountSuffix2++;
		}
	}

	while (currentAmountSuffix < amountSuffix && wordNumber < amountWords) {
		printf("%d.", ++wordNumber);
		for (int i = 0; i < lengthRoot; i++) {
			printf("%c", root[i]);
		}
		printf("-");
		while (suffixes[posS] != '?' && suffixes[posS] != '\0') {
			printf("%c", suffixes[posS]);
			posS++;
		}
		posS++;
		printf("\n");
		currentAmountSuffix++;
	}

	if (wordNumber < amountWords)
		printf("no enough components of words\n");
	printf("\n");
	return 0;
}

int main() {
	printf("\nWords don't come easy to me...\n                    F.R. David\n\n");
	printf("using\nsuf.txt\npre.txt\n\n");
	srand(time(NULL));

	printf("enter amount of words\n");
	int amountWords = 0;
	scanf_s("%d", &amountWords);

	int amountSuffix = rand() % maxAmountComponents + minAmountComponents;
	printf("amount of suffix %d \n", amountSuffix);

	int amountPrefix = rand() % maxAmountComponents + minAmountComponents;
	printf("amount of prefix %d \n", amountPrefix);

	char suffixes[maxSymbolsKeepingComponents];
	clear(suffixes);
	char prefixes[maxSymbolsKeepingComponents];
	clear(prefixes);
	if (readSuffixesPrexixes(suffixes, prefixes, amountSuffix, amountPrefix) == 1)
		return 1;
	printingWords(suffixes, prefixes, amountSuffix, amountPrefix, amountWords);
	return 0;
}