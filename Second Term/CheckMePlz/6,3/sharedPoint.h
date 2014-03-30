#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class SharedPointerTest;

template <typename T>
class SharedPoint {
friend class SharedPointerTest;
public:
    SharedPoint(T *inputPointer) :pointStorage(new PointStorage(inputPointer)) {}
    SharedPoint(SharedPoint const &inputSharedPointer) : pointStorage(inputSharedPointer.pointStorage) {
        pointStorage->amount++;
    }
    ~SharedPoint() {
        pointStorage->amount--;
        if (pointStorage->amount <= 0) {
            delete pointStorage;
        }
    }  
private:
    SharedPoint& operator = (SharedPoint const &inputSharedPoint) {
            pointStorage->amount--;
            pointStorage = inputSharedPoint.pointStorage;
            pointStorage->amount++;
            return *this;
    }
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

