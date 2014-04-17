#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "tree.h"

using namespace std;

template <class T>
/**
@brief class AVL tree for storing Bag-classes
@detailed reires to Bag classes: operators <, > , ==
*/
class BagKeeper {
    friend class BagKeeperTest;
public:
    BagKeeper():root(nullptr){}
    ~BagKeeper() {
        //root->freeMemory(root);
    }

    void add(T input) {
        //cout << input.text() << endl << endl;
        root = root->insert(root,input);
    }

    void del(T input) {
        root = root->remove(root, input);
    }

    int find(T input);

private:
    Node<T> *root;
};

template <class T>
int BagKeeper<T>::find(T input) {
    int slot = root->searchBinary(root, input);
    root->zeroResult();
    return slot;
}

