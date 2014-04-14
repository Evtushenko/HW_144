#include "exceptionZero.h"
#include "exceptionDimension.h"
#include <iostream>

using namespace std;


class TestVector;

template <class T>
/**
@brief class for calculating vectoring expressions
*/
class MyVector {
    friend class TestVector;
public:
    MyVector(): dimension(0), arrayVector(nullptr) {}
    ~MyVector();
    MyVector(MyVector & inputVector);
    MyVector(T *inputArray, int inputDimension);

    /**
    @brief sum values of dimensions of vectors
    */
    template <class U>
    friend MyVector<U>& operator+=(MyVector<U>& left, MyVector<U>& right) throw (ExceptionZero, ExceptionDimension);

    /**
    @brief 	subtract values of dimensions of vectors
    */
    template <class U>
    friend MyVector<U>& operator -= (MyVector<U>& left, MyVector<U>& right) throw (ExceptionZero, ExceptionDimension);

     /**
     @brief returns the value of scalar multiplication
     */
    template <class U>
    friend U operator * ( MyVector<U>  &a, MyVector<U> &b) throw (ExceptionZero, ExceptionDimension);

private:
    int const dimension;
    T *arrayVector;
    /**
    @brief true if all numbers are zero
    */
    bool isZero();
};

template <typename T>
bool MyVector<T>::isZero() {
    for (int i = 0 ; i < dimension; i++) {
        if (arrayVector[i])
            return false;
    }
    return true;
}

template <typename T>
MyVector<T>::~MyVector() {
    //if (arrayVector)
        delete[] arrayVector;
}

template <typename T>
MyVector<T>::MyVector(MyVector & inputVector): dimension(inputVector.dimension) {
    if (arrayVector)
        delete[] arrayVector;
    int *slot = new int[inputVector.dimension];
    for (int i = 0; i < inputVector.dimension; i++)
        slot[i] = inputVector.arrayVector[i];
    arrayVector = slot;
}

template <typename T>
MyVector<T>::MyVector(T *inputArray, int inputDimension): dimension(inputDimension) {
    T *slot = new T[inputDimension];
    for (int i = 0; i < inputDimension; i++)
        slot[i] = inputArray[i];
    arrayVector = slot;
}

template <class U>
MyVector<U> &operator+=(MyVector<U> &left, MyVector<U> &right) throw (ExceptionZero, ExceptionDimension) {
    if (right.isZero() )
        throw ExceptionZero();

    if (left.dimension != right.dimension)
        throw ExceptionDimension();

    for (int i = 0; i < left.dimension; i++) {
        left.arrayVector[i] = left.arrayVector[i] + right.arrayVector[i];
    }
    return left;
}

template <class U>
MyVector<U>& operator -= (MyVector<U>& left, MyVector<U>& right) throw (ExceptionZero, ExceptionDimension)  {
    if (right.isZero())
        throw ExceptionZero();

    if (left.dimension != right.dimension)
        throw ExceptionDimension();

    for (int i = 0; i < left.dimension; i++) {
        left.arrayVector[i] = left.arrayVector[i] - right.arrayVector[i];
    }
    return left;
}

template <class Z>
Z operator * ( MyVector<Z>  &a, MyVector<Z> &b) throw (ExceptionZero, ExceptionDimension) {
    if (a.isZero())
               throw ExceptionZero();
           if (b.isZero())
               throw ExceptionZero();
           if (a.dimension != b.dimension)
               throw ExceptionDimension();

           Z result = 0;
           for (int i = 0 ; i < a.dimension ; i++) {
               result += a.arrayVector[i] * b.arrayVector[i];
           }
           if (result < 0 )
               result = -result;
           return result;
}
