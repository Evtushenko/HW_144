#include "HuffmanFunctions.h"

using namespace std;
using namespace fuctionsHuffman;

int main() {
	cout << "using\nin.txt\nout.txt\n";
	ifstream inFile;
	ofstream outFile;
	inFile.open("in.txt", ios::in);
	outFile.open("out.txt", ios::out);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	char string[maxBufferSize];
	clearChar(string);
	int length = 0;
	while (!inFile.eof()) {
		inFile >> string[length];
		length++;
	}
	inFile.close();
	length--; // символ перехода

	// chars массив с кодом всех символов из строки
	// popular массив частоты встречаемости символов
	int popular[rangeCharCodes];
	clearInt(popular, rangeCharCodes);
	int chars[maxBufferSize];
	clearInt(chars, maxBufferSize);
	int amountChars = 0;
	for (int i = 0; i < length; i++) {
		if (popular[string[i]] == 0) {
			chars[amountChars] = string[i];
			amountChars++;
		}
		popular[string[i]]++;
	}

	// сортируем chars в порядке позрастания //
	sortBubble(popular, chars, amountChars);
	cout << "frequency (increase):\n";
	for (int i = 0; i < amountChars; i++) {
		cout << char(chars[i]) << " " << popular[chars[i]] << endl;
	}

	// создали список для формирования из него дерева //
	tree *begin = nullptr;
	tree *end = nullptr;
	for (int i = 0; i < amountChars; i++) {
		addEnd(chars[i], popular[chars[i]], &begin, &end);
	}

	int amountPoints = amountChars;
	tree *leftList = nullptr;
	tree *rightList = nullptr;
	tree *rootTree = nullptr;
	int memory = 0;
	while (amountPoints != 1) {
		memory = begin->priory + (begin->next)->priory;
		leftList = begin;
		begin = begin->next;
		rightList = begin;
		begin = begin->next;
		rootTree = addBefore(&begin, &end, memory, emptyChar);
		rootTree->left = leftList;
		leftList->code = emptyChar;
		leftList->parent = rootTree;
		rootTree->right = rightList;
		rightList->code = '1';
		rightList->parent = rootTree;
		amountPoints--;
	}
	// построили дереве rootTree - вершина //

	tree *answer = nullptr;
	tree *help = nullptr;
	codes *pointersCodes[rangeCharCodes];
	for (int i = 0; i < rangeCharCodes; i++) {
		pointersCodes[i] = nullptr;
	}
	for (int i = 0; i < amountChars; i++) {
		help = rootTree;
		answer = nullptr;
		pointersCodes[chars[i]] = createCodes();
		findC(help, char(chars[i]), &answer); // находим лист равный символу и получаем его код в обратном порядке //
		help = answer;
		int m = 0;
		while (help->parent) {
			pointersCodes[chars[i]]->s[m] = help->code;
			help = help->parent;
			m++;
		}
	}
	cout << endl;

	for (int i = 0; i < length; i++) {
		int lengthCode = 0;

		for (int j = 0; j < maxLengthCode; j++) {
			if (pointersCodes[int(string[i])]->s[j] == -1){
				lengthCode = j;
				break;
			}
		}
		for (int m = 0; m < lengthCode; m++) {
			cout << pointersCodes[int(string[i])]->s[lengthCode - 1 - m];
			outFile << (pointersCodes[int(string[i])]->s[lengthCode - 1 - m]);
		}
		outFile << " ";
		cout << endl;
	}

	char out[maxLengthOutString];
	clearChar(out);
	printAbc(rootTree, out);

	outFile << endl;
	for (int i = 0; i < strlen(out); i++) {
		outFile << out[i];
	}
	outFile.close();
	freeMemory(rootTree);
	for (int i = 0; i < rangeCharCodes; i++) {
		if (pointersCodes[i] != nullptr) {
			delete pointersCodes[i];
		}
	}
	return 0;
}