#include "human.h"

template <class T>
class Comparater{
public:
    Comparater() {}
    ~Comparater() {}
    bool bigger(T a, T b) {
        return true;
    }
};

// специализация под int
template <>
class Comparater<int>
{
public:
    bool bigger(int a, int b) {
        if (a > b)
            return true;
        else
            return false;
    }
};

// специализация под char
template <>
class Comparater<char>
{
public:
    bool bigger(char a, char b) {
        if (int(a) < int(b))
            return true;
        else
            return false;
    }
};


// специализация под Human
template <>
class Comparater<Human>
{
public:
    bool bigger(Human a, Human b) {
        if (a.age * a.power < b.age * b.power)
            return true;
        else
            return false;
    }
};
