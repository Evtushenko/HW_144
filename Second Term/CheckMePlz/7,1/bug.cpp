#include "bug.h"
#include <iostream>

using namespace std;

Bug::~Bug() {
    delete name;
}
bool operator < ( const Bug  &a, const Bug &b) {
    int l1 = strlen(a.name);
    int l2 = strlen(b.name);
    return l1 < l2;
}

bool operator > ( const Bug  &a, const Bug &b) {
    int l1 = strlen(a.name);
    int l2 = strlen(b.name);
    return l1 > l2;
}

bool operator == (const Bug &a, const Bug &b) {
    char *f = a.name;
    char *g = b.name;
    if (strlen(f) != strlen(g))
        return false;
    for (int i = 0 ; i < strlen(f); i++)
        if (f[i] != g[i])
            return false;
    //cout << f << endl;
    //cout << g << endl;
    return true;
}

char *Bug::text() {
    return name;
}
