#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class SharedPointerTest;

/**
@brief shared pointer ~ std::shared_ptr
*/
template <typename T>
class SharedPoint {
friend class SharedPointerTest;
public:
    SharedPoint(T *inputPointer) :pointStorage(new PointStorage(inputPointer)) {}
    /**
    @brief constuctor of copying
    */
    SharedPoint(SharedPoint const &inputSharedPointer) : pointStorage(inputSharedPointer.pointStorage) {
        pointStorage->amount++;
    }
    ~SharedPoint() {
        pointStorage->amount--;
        if (pointStorage->amount <= 0) {
            delete pointStorage;
        }
    }
    /**
    @brief assigment
    */
    SharedPoint& operator = (SharedPoint const &inputSharedPoint) {
            pointStorage->amount--;
            pointStorage = inputSharedPoint.pointStorage;
            pointStorage->amount++;
            return *this;
    }
private: 
    /**
    @brief for storing amount of references and pointer to element
    */
    struct PointStorage {
        PointStorage(T *inputPointer) : pointerFromStorage(inputPointer), amount(1) {}
        ~PointStorage() {
            delete pointerFromStorage;
        }
        T *pointerFromStorage;
        int amount;
    };
    PointStorage* pointStorage;
};

