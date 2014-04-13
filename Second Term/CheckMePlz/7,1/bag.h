#include <string.h>
/**
@brief example class whitch has all requires from BagKeeper
*/
class Bag {
public:
    Bag(): name(NULL) {}
    Bag(char *input): name(input) {}
    ~Bag();
    char *text();
    friend bool operator < (const Bag &a, const Bag &b);
    friend bool operator > (const Bag &a, const Bag &b);
    friend bool operator == (const Bag &a, const Bag &b);
private:
    char *name;
};

