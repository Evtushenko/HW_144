#include "Sorter.h"
#include "BubbleSort.h"
#include "PlugSort.h"

using namespace std;

int main() {
	Sorter* bubble = new BubbleSort();
	bubble->sorting();
	delete bubble;

	Sorter* bead = new PlugSort();
	bead->sorting();
	delete bead;
	return 0;
}