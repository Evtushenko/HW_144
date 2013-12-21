#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int const maxAmountVertex = 26;
int const maxBufferSize = 100;

int main() {

	int adjacencyMatrix[maxAmountVertex][maxAmountVertex];
	char names[maxAmountVertex];
	for (int i = 0; i < maxAmountVertex; i++) {
		names[i] = '\0';
	}

	ifstream inFile;
	char nameFile[maxBufferSize];
	cout << "enter name of file" << endl;
	cin.getline(nameFile, maxBufferSize);
	inFile.open(nameFile, ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 1;
	}

	cout << "enter start point" << endl;
	int currentString = 0;
	cin >> currentString;
	int amountPoints = 0; // вершины
	inFile >> amountPoints;
	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			inFile >> adjacencyMatrix[i][j];
		}
	}

	int intToChar = 'A';
	int current = 1;
	names[currentString] = 'A';

	bool setToZero = false;
	while (current < amountPoints) {
		bool findSomething = false;
		for (int i = 0; i < amountPoints; i++) {
			if ((adjacencyMatrix[currentString][i] == 1) && (names[i] == 0)) {
				currentString = i;
				names[i] = current + intToChar;
				current++;
				findSomething = true;
				break;
			}
		}
		if (!findSomething && !setToZero) {
			currentString = 0;
			setToZero = true;
		}
		if (!findSomething && setToZero) {
			currentString++;
		}
	}
	
	for (int i = 0; i < amountPoints; i++) {
		cout << names[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			cout << adjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
	inFile.close();
	return 0;
}