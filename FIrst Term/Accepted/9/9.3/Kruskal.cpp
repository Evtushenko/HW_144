#include "KruskalFunction.h"

using namespace std;
using namespace kruskal;

int main() {
	int matrix[maxAmountVertex][maxAmountVertex];
	for (int i = 0; i < maxAmountVertex; i++) {
		for (int j = 0; j < maxAmountVertex; j++) {
			matrix[i][j] = 0;
		}
	}

	ifstream inFile;
	char nameFile[maxBufferSize];
	cout << "enter name of file" << endl;
	cin.getline(nameFile, maxBufferSize);
	inFile.open(nameFile, ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	int amountPoints = 0; // вершины
	inFile >> amountPoints;
	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			inFile >> matrix[i][j];
		}
	}

	// cheking for corrent read //
	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	inFile.close();


	Roads *begin = nullptr;
	Roads *end = nullptr;
	buildRoads(&begin, &end, matrix, amountPoints);

	// создали столько же компонент связности, сколько и вершин
	Points *beginP = nullptr;
	Points *endP = nullptr;
	Roads *top = begin;
	for (int i = 0; i < amountPoints; i++) {
		addEnd(&beginP, &endP, i);
	}
	printLogic(&beginP, amountPoints, &top);
	memoryFree(beginP, &top);
	return 0;
}