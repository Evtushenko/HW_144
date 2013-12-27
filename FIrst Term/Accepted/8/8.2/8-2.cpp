#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int const maxAmountTowns = 10;
int const maxBufferSize = 100;
int const maxDistance = 10000;

int main() {
	int matrix[maxAmountTowns][maxAmountTowns];
	ifstream inFile;
	char nameFile[maxBufferSize];
	cout << "enter name of file" << endl;
	cin.getline(nameFile, maxBufferSize);
	inFile.open(nameFile, ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	int amountTowns = 0;
	int amountRoads = 0;
	inFile >> amountTowns >> amountRoads;

	for (int i = 0; i < amountTowns; i++) {
		for (int j = 0; j < amountTowns; j++) {
			matrix[i][j] = 0;
		}
	}

	int from = 0;
	int to = 0;
	int distance = 0;
	for (int i = 0; i < amountRoads; i++) {
		inFile >> from >> to >> distance;
		matrix[from - 1][to - 1] = distance;
		matrix[to - 1][from - 1] = distance;
	}

	//Алгоритм Флойда-Уоршелла
	for (int k = 0; k < amountTowns; k++)
		for (int i = 0; i < amountTowns; i++)
			for (int j = 0; j < amountTowns; j++)
				if (matrix[i][k] && matrix[k][j] && i != j)
					if (matrix[i][k] + matrix[k][j] < matrix[i][j] || matrix[i][j] == 0)
						matrix[i][j] = matrix[i][k] + matrix[k][j];

	cout << endl << "Min distances" << endl;
	for (int i = 0; i < amountTowns; ++i, printf("\n"))
		for (int j = 0; j < amountTowns; ++j)
			cout << matrix[i][j] << " ";

	int leftList[maxAmountTowns];
	int weWere[maxAmountTowns];
	for (int i = 0; i < amountTowns; i++) {
		leftList[i] = 0;
		weWere[i] = 0;
	}

	int amountTownVisited = 1;
	leftList[0] = 1;
	int currentString = 0;
	weWere[0] = 1;

	while (amountTownVisited < amountTowns) {
		int min = maxDistance;
		int minNumber = 0;
		for (int i = 0; i < amountTowns; i++) {
			if ((matrix[currentString][i] < min) && (matrix[currentString][i] != 0) && (weWere[i] == 0)) {
				min = matrix[currentString][i];
				minNumber = i;
			}
		}
		leftList[amountTownVisited] = minNumber + 1;
		weWere[minNumber] = 1;
		amountTownVisited++;
		currentString = minNumber;
	}

	cout << "Our army has visited" << endl;
	for (int i = 0; i < amountTowns; i++) {
		cout << i + 1 << ". " << leftList[i] << endl;
	}
	inFile.close();
	return 0;
}