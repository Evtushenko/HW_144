#include "PointerList.h"

/*! \class TableCell
 * it is actually PointerList with its size
*/
template <typename T>
class TableCell : public PointerList<T>{
public:
    TableCell(){
        sizeOfCell = 0;
    }
    int sizeOfCell;
};
