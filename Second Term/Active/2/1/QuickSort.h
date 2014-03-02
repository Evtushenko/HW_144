#include "Sorter.h"

class QuickSort : public Sorter {
public:
	QuickSort();
	~QuickSort();
	void sorting();
private:
	int end;
	int begin;
};