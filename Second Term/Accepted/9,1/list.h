#pragma once

//template <typename UniversalType>

class List
{
public:
    virtual void addElement(int number) = 0;
    virtual void deleteElement(int number) = 0;
    virtual void printList() = 0;
    int numberOfElements;
};
