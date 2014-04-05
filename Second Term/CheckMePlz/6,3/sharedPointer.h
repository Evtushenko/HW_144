#include <iostream>
#include <cstdlib>

class SharedPointerTest;

template<typename T>
/**
@brief has copy-costructor, operator "=", intialization constructor
@detailed counting amout references to object
*/
class SharedPointer {
friend class SharedPointerTest;
public:
    SharedPointer(): pointer(nullptr), amount(new int (0)) {}
    SharedPointer(T *inputPointer): pointer(inputPointer), amount(new int (1)) {}
    SharedPointer(SharedPointer const &inputSP);
    ~SharedPointer();
    SharedPointer& operator =(SharedPointer const &inputSP);
private:
    T *pointer;
    int *amount;

};

template<typename T>
SharedPointer<T>:: SharedPointer(const SharedPointer &inputSP):
    pointer(inputSP.pointer), amount(inputSP.amount)
{
    ++(*amount);
}

template<typename T>
SharedPointer<T>:: ~SharedPointer() {
    --(*amount);
    if ((*amount) <= 0) {
        delete pointer;
        delete amount;
    }
}

template<typename T>
SharedPointer<T> &SharedPointer<T>:: operator =(SharedPointer const &inputSP) {
    if ( (pointer != inputSP.pointer) && (amount != inputSP.amount) ) {
        --(*amount);
        if (!*amount) {
            delete pointer;
            delete amount;
        }
        ++(*inputSP.amount);
        pointer = inputSP.pointer;
        amount = inputSP.amount;
     }
    return *this;
}



