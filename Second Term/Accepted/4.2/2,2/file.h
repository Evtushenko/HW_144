#pragma once
#include "printSpiral.h"

/**
@brief printing in out.txt spirally.
@detailed file chindren realization of printOut.
*/
class File : public PrintSpiral {
public:

    /**
    @brief constructor
    */
    File() {};

    /**
    @brief destructor
    */
    ~File() {};

    /**
    @brief file printing spirally.
    */
    void outPrint();
};
