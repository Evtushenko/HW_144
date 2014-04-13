#include "Bag.h"
#include <iostream>

using namespace std;

Bag::~Bag() {
    delete name;
}
bool operator < ( const Bag  &a, const Bag &b) {
    int l1 = strlen(a.name);
    int l2 = strlen(b.name);
    return l1 < l2;
}

bool operator > ( const Bag  &a, const Bag &b) {
    int l1 = strlen(a.name);
    int l2 = strlen(b.name);
    return l1 > l2;
}

bool operator == (const Bag &a, const Bag &b) {
    char *f = a.name;
    char *g = b.name;
    int length = strlen(f);
    if (strlen(f) != strlen(g))
        return false;
    for (int i = 0 ; i < length; i++)
        if (f[i] != g[i])
            return false;
    //cout << f << endl;
    //cout << g << endl;
    return true;
}

char *Bag::text() {
    return name;
}
