#pragma once
#include "pointerList.h"
#include <iostream>

using namespace std;

/*! \class TableCell
 * it is actually PointerList with its size
*/
class TableCell : public PointerList {
public:
    TableCell() : PointerList() {
        sizeOfCell = 0;
    }
    int sizeOfCell;
};
