/**
@brief for storing AVL tree  nodes
*/

template <class T>
class BagKeeper;

class BagKeeperTest;

template <class T>
class Node {
    friend class BagKeeper<T>;
    friend class BagKeeperTest;
private:
        Node(T value): left(nullptr), right(nullptr), height(1), resultSearching(0) {
            key = new T(value);
        }
        Node* left;
        Node* right;
        unsigned char height;
        T *key;
        int resultSearching;
            unsigned char heightF(Node* pointer) {
                return pointer?pointer->height:0;
            }

            int balanceFactor(Node* pointer) {
                return heightF(pointer->right)-heightF(pointer->left);
            }
            void fixHeight(Node* pointer);

            Node<T> *rotateRight(Node* p);

            Node* rotateLeft(Node* q);

            Node* balance(Node* p);

            Node* insert(Node* p, T k);

            Node* findMin(Node* p) {
                return p->left?findMin(p->left):p;
            }

            Node* removeMin(Node* p);

            Node* freeMemory(Node *root);

            Node* remove(Node* p, T k);

            /**
            @brief find frequency of element in tree
            */
            int searchBinary(Node *node, T input);

            void zeroResult() {
                resultSearching = 0;
            }
    };

template <class T>
void Node<T>::fixHeight(Node* pointer) {
    unsigned char heightLeft = heightF(pointer->left);
    unsigned char heightRight = heightF(pointer->right);
    pointer->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

template <class T>
Node<T>* Node<T>::rotateRight(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

template <class T>
Node<T>* Node<T>::rotateLeft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

template <class T>
Node<T>* Node<T>::balance(Node* p) {
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

template <class T>
Node<T>* Node<T>::insert(Node* p, T k) {
    if( !p )
        return new Node(k);
    if( k < *(p->key) )
        p->left = insert(p->left, k);
    else
        p->right = insert(p->right, k);
    return balance(p);
}

template <class T>
Node<T>* Node<T>::removeMin(Node* p) {
    if( p->left == 0 )
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

template <class T>
Node<T>* Node<T>::freeMemory(Node *root) {
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

template <class T>
Node<T>* Node<T>::remove(Node* p, T k) {
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

template <class T>
int Node<T>::searchBinary(Node *node, T input) {
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

