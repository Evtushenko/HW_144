#include <string.h>

class Bug {
public:
    Bug(): name(NULL) {}
    Bug(char *input): name(input) {}
    ~Bug();
    char *text();
    friend bool operator < (const Bug &a, const Bug &b);
    friend bool operator > (const Bug &a, const Bug &b);
    friend bool operator == (const Bug &a, const Bug &b);
private:
    char *name;
};

