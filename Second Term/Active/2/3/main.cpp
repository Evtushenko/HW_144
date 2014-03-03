#include "Sorter.h"

using namespace std;

int main() {

	cout << "using matrix.txt\n"; 

	Sorter* bubble = new Sorter();
	bubble->readFile();
	bubble->printMatrix();
	bubble->sortStupid();
	bubble->TransferToMatrix();
	bubble->printMatrix();
	delete bubble;
	
	return 0;
}