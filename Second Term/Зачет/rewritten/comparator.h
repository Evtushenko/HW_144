#include "human.h"

// материнский шаблон который ничего не делает
template <class T>
class Comparater{
public:
    Comparater() {}
    ~Comparater() {}
    //bool bigger(T a, T b) {
        //return true;
    //}
};

// специализация под int
template <>
class Comparater<int>
{
public:
    bool bigger(int a, int b) {
        return (a > b);
    }
};

// специализация под char
template <>
class Comparater<char>
{
public:
    bool bigger(char a, char b) {
        return int(a) < int(b);
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
