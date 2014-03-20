#pragma once
#include "PrintSpiral.h"

/**
@brief printing in console spirally.
@detailed console chindren realization of printOut.
*/
class Console : public PrintSpiral {
public:

    /**
    @brief constructor
    */
    Console() {};

    /**
    @brief destructor
    */
    ~Console() {};

    /**
    @brief printing in console spirally.
    */
    void outPrint();
};
