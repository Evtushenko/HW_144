#include <QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class BugKeeper {
    friend class BugKeeperTest;
public:
    BugKeeper():root(nullptr), resultSearching(0) {}
    ~BugKeeper() {
        freeMemory(root);
    }
    /*
    void add(T input) {
        root = searchBinary(root, T input);
    }
    void del(T input) {
        root = remove(root, T input);
    }
    int find(T input) {
        return searchBinary(root,T input);
    }
    */

private:
    struct Node {
            Node(T value): left(nullptr), right(nullptr), height(1) {
                key = new T(value);
            }
            Node* left;
            Node* right;
            unsigned char height;
            T *key;
        };
    Node *root;
    int resultSearching;
    unsigned char height(Node* pointer) {
            return pointer?pointer->height:0;
        }

        int balanceFactor(Node* pointer) {
            return height(pointer->right)-height(pointer->left);
        }
        void fixHeight(Node* pointer) {
            unsigned char heightLeft = height(pointer->left);
            unsigned char heightRight = height(pointer->right);
            pointer->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
        }

        Node* rotateRight(Node* p) {
            Node* q = p->left;
            p->left = q->right;
            q->right = p;
            fixHeight(p);
            fixHeight(q);
            return q;
        }

        Node* rotateLeft(Node* q) {
            Node* p = q->right;
            q->right = p->left;
            p->left = q;
            fixHeight(q);
            fixHeight(p);
            return p;
        }

        Node* balance(Node* p) {
            fixHeight(p);
            if( balanceFactor(p) == 2 ) {
                if( balanceFactor(p->right) < 0 )
                    p->right = rotateRight(p->right);
                return rotateLeft(p);
            }
            if( balanceFactor(p) == -2 ) {
                if( balanceFactor(p->left) > 0  )
                    p->left = rotateLeft(p->left);
                return rotateRight(p);
            }
            return p;
        }

        Node* insert(Node* p, T k) {
            if( !p )
                return new Node(k);
            if( k < *(p->key) )
                p->left = insert(p->left, k);
            else
                p->right = insert(p->right, k);
            return balance(p);
        }

        Node* findMin(Node* p) {
            return p->left?findMin(p->left):p;
        }

        Node* removeMin(Node* p) {

            if( p->left == 0 )
                return p->right;
            p->left = removeMin(p->left);
            return balance(p);
        }

        Node* freeMemory(Node *root) {
            if (!root)
                return root;
            if (root->left == root->right) {
                free(root);
                return nullptr;
            }
            root->left = freeMemory(root->left);
            root->right = freeMemory(root->right);
            delete root;
            return nullptr;
        }


        Node* remove(Node* p, T k)
        {
            if( !p )
                return 0;
            if( k < *(p->key) )
                p->left = remove(p->left, k);
            else if( k > *(p->key) )
                p->right = remove(p->right, k);
            else
            {
                Node* q = p->left;
                Node* r = p->right;
                delete p;
                if( !r )
                    return q;
                Node* min = findMin(r);
                min->right = removeMin(r);
                min->left = q;
                return balance(min);
            }
            return balance(p);
        }


        int searchBinary(Node *node, T input) {
            if ( *(node->key) == input) {
                resultSearching++;
            }
            if ( node->left && ( *(node->left->key) == *(node->key) ||  *(node->key) > input )  ) {
                searchBinary(node->left, input);
            }
            if ( node->right && ( *(node->right->key) == *(node->key) ||  *(node->key) < input )  ) {
                searchBinary(node->right, input);
            }
            return resultSearching;
        }
};
