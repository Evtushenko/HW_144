#pragma once
#include <iostream>
#include <cstdlib>

int const amountElements = 5;

/**
@brief Mother - class, has 4 chindren
@detailed has 2 function for users and 2 for chindren classes
*/
class Sorter {
public:
    /**
    @brief constructor
    */
    Sorter();
    /**
    @brief virtual destructor
    */
    virtual ~Sorter() = 0;
    /**
    @brief function sorting
    @detailed has 4 realizations in chindress classes
    */
    virtual void sorting() = 0;
    /**
    @brief function printing elenements of array
    @detailed prints all elements from array witch situated in mother class
    */
    void print() const;
    /**
    @brief read elements from keybord
    @detailed reads 5 elements defaulty
    */
    void readKeybord();

    /**
    @brief read elements from test's int array
    @detailed reads 5 elements defaulty
    */
    void fillArray(int elements[]);
    /**
    @brief return protected arrayElements
    */
    int *returnArray();
protected:
    /**
    @brief array for storing elements
    @detailed 5 as default
    */
    int arrayElements[amountElements];
    /**
    @brief change value of two ints
    @detailed common for chindren classes
    @param 2 int type elements of base array
    */
    void swap(int &first, int &second);
};
