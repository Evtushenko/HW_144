#include "file.h"

using namespace std;

void File::outPrint() {
	readFromFile();
	printIn();
	this->spiralOrder();
	ofstream static outFile;
	outFile.open("out.txt", ios::out);
	for (int i = 0; i < amountElements*amountElements; i++) {
		outFile << queuePrinting[i] << " ";
	}
	cout << "\nsuccessfule writed to out.txt\n";
	outFile.close();
}
