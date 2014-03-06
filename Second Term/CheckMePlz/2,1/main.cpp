#include "Sorter.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "PlugSort.h"
#include "BubbleSort.h"

using namespace std;

enum Change { exitProgramm, Psort, Bsort, Qsort, Hsort};

Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {

	cout << "Welcome!" << endl << "Choose the number of state" << endl;
	cout << "0 = exit" << endl;
	cout << "1 = Plug Sort" << endl;
	cout << "2 = Bubble Sort" << endl;
	cout << "3 = Quick Sort" << endl;
	cout << "4 = Heap Sort" << endl;

	Sorter* bubble = new BubbleSort();
	Sorter* plug = new PlugSort();
	Sorter* quick = new QuickSort();
	Sorter* heap = new HeapSort();


	for (;;) {
		cout << "Enter number of state" << endl;
		int changeTemp = 0;
		Change c;
		cin >> changeTemp;

		if (!((changeTemp >= 0) && (changeTemp <= 4))) {
			cout << "Wrong command!" << endl;
			return 0;
		}

		c = intToChange(changeTemp);

		if (c == exitProgramm) {
			delete bubble;
			delete plug;
			delete quick;
			delete heap;
			cout << "L.A.Goodbay" << endl;
			break;
		}

		if (c == Psort) {
			plug->readKeybord();
			plug->sorting();
			plug->print();
			cout << "\n\n";
		}

		if (c == Bsort) {
			bubble->readKeybord();
			bubble->sorting();
			bubble->print();
			cout << "\n\n";
		}

		if (c == Qsort) {
			quick->readKeybord();
			quick->sorting();
			quick->print();
			cout << "\n\n";
		}

		if (c == Hsort) {
			heap->readKeybord();
			heap->sorting();
			heap->print();
			cout << "\n\n";
		}
	}
	return 0;
}