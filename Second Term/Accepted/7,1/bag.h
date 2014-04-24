#include <string.h>
#include <iostream>
/**
@brief example class whitch has all requires from BagKeeper
*/
using namespace std;
class Bag {
public:
    Bag(): name(NULL) {}
    Bag(char *input) : name(new char[strlen(input) + 1]) {
        memcpy(name, input, strlen(input) + 1);
        //cout << name << endl;
    }
    Bag(Bag const  &input): name(new char[strlen(input.name) + 1]) {
        memcpy(name, input.name, strlen(input.name) + 1);
    }

    ~Bag();
    char *text();
    friend bool operator < (const Bag &a, const Bag &b);
    friend bool operator > (const Bag &a, const Bag &b);
    friend bool operator == (const Bag &a, const Bag &b);
private:
    char *name;
};

