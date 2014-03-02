#include "console.h"
#include "file.h"
#include "printSpiral.h"

using namespace std;

PrintSpiral:: PrintSpiral() {
	mid = amountElements / 2;
	for (int i = mid; i >= 0; i--) {
		maxDistCentr[mid - i] = dist(i, i);
	}
}

Console:: Console (){
};

File:: File (){
};

float PrintSpiral::dist(int Xa, int Ya) const{
	float midDistance = 0;
	midDistance = sqrt((mid - Xa) * (mid - Xa) + (mid - Ya) * (mid - Ya));
	return midDistance;
}

void PrintSpiral::print() const {
	cout << "Matrix from file:\n";
	for (int i = 0; i < amountElements ; i++ ) {
		for (int j = 0; j < amountElements; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int PrintSpiral::readFromFile() {
	ifstream inFile;
	char nameFile[]="matrix.txt";
	inFile.open(nameFile, ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 1;
	}
	for (int i = 0; i < amountElements; i++) {
		for (int j = 0; j < amountElements; j++) {
			inFile >> matrix[i][j];
		}
	}
	inFile.close();
}

void Console::spiralOrder(int Xc, int Yc) const {
	int static raz = 1;
	if (raz ==  1)
		cout << matrix[mid][mid] << " ";
	Yc--;
	cout << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Xc--;
		cout << matrix[Xc][Yc] << " ";
	}
	Yc++;
	cout << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Yc++;
		cout << matrix[Xc][Yc] << " ";
	}
	Xc++;
	cout << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Xc++;
		cout << matrix[Xc][Yc] << " ";
	}
	Yc--;
	cout << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Yc--;
		cout << matrix[Xc][Yc] << " ";
	}

	raz++;
	if (raz <= mid)
		spiralOrder(mid, mid);
	else 
		cout << "\nThank you\n";
}

void File::spiralOrder(int Xc, int Yc) const {
	ofstream static outFile;
	outFile.open("out.txt", ios::out);
	int static raz = 1;
	if (raz ==  1)
		outFile << matrix[mid][mid] << " ";
	Yc--;
	outFile << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Xc--;
		outFile << matrix[Xc][Yc] << " ";
	}
	Yc++;
	outFile << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Yc++;
		outFile << matrix[Xc][Yc] << " ";
	}
	Xc++;
	outFile << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Xc++;
		outFile << matrix[Xc][Yc] << " ";
	}
	Yc--;
	outFile << matrix[Xc][Yc] << " ";
	while (dist(Xc, Yc) < maxDistCentr[raz]) {
		Yc--;
		outFile << matrix[Xc][Yc] << " ";
	}

	raz++;
	if (raz <= mid)
		spiralOrder(mid, mid);
	else { 
		cout << "\nsuccessfule writed to out.txt\n";
		outFile.close();
	}
}