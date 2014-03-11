#include "Sorter.h"
#include "BubbleSort.h"

using namespace std;

Sorter::~Sorter() {
	for (int i = 0; i < lengthString; i++)
		delete arrayColumns[i];
}

Sorter::Sorter() {
	currentNumber = 0;
	for (int i = 0; i < lengthString; i++)
		 arrayColumns[i] = nullptr;
}

bool operator>(const ListColumns &first, const ListColumns &second) {
	bool result = true;
	for ( int i = 0 ; i < lengthString; i++) {
		if (first.elementsOfColumn[i] < second.elementsOfColumn[i]){
			result = false;
			break;
		}
		if (first.elementsOfColumn[i] > second.elementsOfColumn[i]){
			break;
		}
	}
	return result;
}

void Sorter::TransferToMatrix(){
	int string = 0;
	for (int j = 0; j < lengthString ; j++) {
		for (int i = 0; i < lengthString; i++)
			matrix[i][string] = arrayColumns[j]->elementsOfColumn[i];
		string++;
	}
}

void Sorter::change(ListColumns* one, ListColumns* two){
	int slot[lengthString];
	for (int i = 0; i < lengthString; i++)
		slot[i]= one->elementsOfColumn[i];
	for (int i = 0; i < lengthString; i++)
		one->elementsOfColumn[i] = two->elementsOfColumn[i];
	for (int i = 0; i < lengthString; i++)
		two->elementsOfColumn[i] = slot[i];
}

void Sorter::printMatrix() const{
	cout << "Matrix from file:\n";
	for (int i = 0; i < lengthString ; i++ ) {
		for (int j = 0; j < lengthString; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Here is the columns of Matrix:\n";
	for (int j = 0; j < lengthString; j++) {
		for (int i = 0; i < lengthString; i++) {
			cout << arrayColumns[j]->elementsOfColumn[i] << " ";
		}
		cout << endl;
	}
}

int Sorter::readFile() {
	ifstream inFile;
	char nameFile[]="matrix.txt";
	inFile.open(nameFile, ios::in);

	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 1;
	}

	for (int i = 0; i < lengthString; i++) {
		for (int j = 0; j < lengthString; j++) {
			inFile >> matrix[i][j];
		}
	}

	for (int i = 0; i < lengthString; i++) {
		ListColumns *newE = new ListColumns;
		arrayColumns[currentNumber] = newE;	
		for (int j = 0; j < lengthString; j++) {
			arrayColumns[currentNumber]->elementsOfColumn[j] = matrix[j][i];
		}
		currentNumber++;
	}
	return 0;
}



