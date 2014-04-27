#pragma once
#include "pointerList.h"
#include <iostream>

using namespace std;

/*! \class TableCell
 * it is actually PointerList with its size
*/
template <typename T>
class TableCell : public PointerList<T> {
public:
    TableCell() : PointerList<T>()
    {
        //cout << "T";
        sizeOfCell = 0;
    }
    int sizeOfCell;
};
