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

	Tree *rootTree = makeTree(popular, chars, amountChars);

	
	Codes *pointersCodes[rangeCharCodes];
	for (int i = 0; i < rangeCharCodes; i++) {
		pointersCodes[i] = nullptr;
	}
	getCodes(pointersCodes, chars, rootTree, amountChars);
	cout << endl;

	char out[maxLengthOutString];
	clearChar(out);
	int lengthOut = 0;
	printAbc(rootTree, out, lengthOut);
	for (int i = 0; i < lengthOut; i++) {
		outFile << out[i];
	}
	outFile << endl;

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
		if (i != length - 1) {
			outFile << " ";
		}
		cout << endl;
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