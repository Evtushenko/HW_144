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
	int amountPoints = 0; // �������
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
	bool firstExist = false;
	// create increase Roads
	for (int i = 0; i < amountPoints; i++) {
		for (int j = i + 1; j < amountPoints; j++) {
			if (matrix[i][j] != 0) {
				if (!firstExist) {
					addFirst(&begin, &end, i, j, matrix[i][j]);
					firstExist = true;
				}
				else {
					addSort(&begin, &end, i, j, matrix[i][j]);
				}
			}
		}
	}


	Roads *slot = begin;
	// show roads
	while (slot) {
		cout << "Road: from " << slot->from << " to " << slot->to << " distance " << slot->distance << endl;
		slot = slot->next;
	}

	// ������� ������� �� ��������� ���������, ������� � ������
	Points *beginP = nullptr;
	Points *endP = nullptr;
	Roads *top = begin;

	for (int i = 0; i < amountPoints; i++) {
		addEnd(&beginP, &endP, i);
	}

	Points *first = nullptr;
	Points *second = nullptr;

	while (amountPoints != 1) {
		first = find(beginP, top->from);
		second = find(beginP, top->to);
		char a = 0;
		if (first != second) {
			cout << "sum ";
			for (int i = 0; i < maxAmountVertex; i++) {
				if (first->Point[i] != -1) {
					a = 'A' + first->Point[i];
					cout << a << " ";
				}
				else
					break;
			}
			cout << " with ";
			for (int i = 0; i < maxAmountVertex; i++) {
				if (second->Point[i] != -1) {
					a = 'A' + second->Point[i];
					cout << a << " ";
				}
				else
					break;
			}
			cout << endl;
			sum(first, second);
			del(&beginP, &endP, second);
			amountPoints--;
		}
		pop(&top);
	}

	return 0;
}