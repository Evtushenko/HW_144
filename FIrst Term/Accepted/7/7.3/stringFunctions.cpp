#include "stringFunctions.h"

using namespace std;
using listFunctions::Word;

Word *listFunctions::create(char s []) {
	Word *creature = new Word;
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

void listFunctions::addEnd(Word *&last, char s []) {
	Word *creature = new Word;
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

Word *listFunctions::findLast(Word *&first){
	Word *helper = first;
	while (helper->next) {
		helper = helper->next;
	}
	return helper;
}

int listFunctions::calcLength(Word *&begin) {
	int answer = 0;
	Word *helper = begin;
	while (helper) {
		answer++;
		helper = helper->next;
	}
	return answer;
}

int listFunctions::hashCount(char string []) {
	int result = 0;
	for (int i = 0; string[i] != '\0'; ++i)
		result = (result + string[i]) % amount;
	return result;
}

bool listFunctions::findSame(Word *&begin, char buffer []) {
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

void listFunctions::printMax(Word *&begin) {
	Word *slot = begin;
	while (slot) {
		int position = 0;
		while (slot->word[position + 1] != '\0') {
			cout << slot->word[position];
			position++;
		}
		slot = slot->next;
		cout << endl;
	}
}

int listFunctions::writeHastTable(Word *hashRange [], int &amountReadedWords){
	ifstream inFile1;

	inFile1.open("1.txt", ios::in);
	if (!(inFile1.is_open())) {
		cout << "Where is your file ???" << endl;
		return 1;
	}
	for (int i = 0; i < amount; i++) {
		hashRange[i] = nullptr;
	}

	Word *slot = nullptr;
	char buffer[wordLen] = { -1 };
	int valueHash = 0;

	// записали в хэш таблицу //
	while (inFile1.good()) {
		inFile1 >> buffer;
		amountReadedWords++;
		valueHash = hashCount(buffer);
		if (hashRange[valueHash] == nullptr) {
			hashRange[valueHash] = create(buffer);
		}
		else {

			if (!findSame(hashRange[valueHash], buffer)) {
				slot = findLast(hashRange[valueHash]);
				addEnd(slot, buffer);
			}

		}
	}
	inFile1.close();
	return 0;
}

void listFunctions::freeMemory(Word *hashRange []) {
	for (int i = 0; i < amount; i++) {
		if (hashRange[i] != nullptr) {
			delete hashRange[i];

		}
	}
}

void listFunctions::printStatic(Word *hashRange [], int amountReadedWords) {
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
	cout << "amount readed words " << amountReadedWords << endl << endl;
	cout << "amount uniq words " << amountUniq << endl << endl;
	cout << "amount free slots " << amount - amountVacant << endl << endl;
	midLength = sumLength / amountVacant;
	cout << "max length " << maxLength << endl;
	cout << "words:\n";
	printMax(maxLenPoint);
	cout << endl;
	cout << "mid length " << midLength << endl << endl;
	printf("load factor %.4lf\n\n", loadFactor);
	cout << "Hit word " << amountHit << " times '";
	Word *slot1 = hitPointer;
	int position = 0;
	while (slot1->word[position + 1] != '\0') {
		cout << slot1->word[position];
		position++;
	}
	cout << "'\n\n";
}
