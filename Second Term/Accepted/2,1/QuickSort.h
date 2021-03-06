#include "Sorter.h"

/**
@brief Class of bubble Sort, inherited from Sorter
@detailed Has a special variables for working.
*/

class QuickSort : public Sorter {
public:
	/**
	@brief constructor
	@detailed indentify private variables
	*/
	QuickSort(): begin(0), end(amountElements-1) {};
	/**
	@brief destructor
	*/
	~QuickSort() {};
	/**
	@brief Quick sorting
	@detailed special elements picks in way of medium index
	*/
	void sorting();
private:
	int end;
	int begin;
};