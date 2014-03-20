#include "TreeMaker.h"

using namespace  std;

enum SymbolKinds {digit, function, open, close};

TreeMaker::TreeMaker()
{
    inPutString = NULL;
    currentPoint = NULL;
    root = NULL;
    currentPoint = NULL;
}

TreeMaker::~TreeMaker()
{
   getResult();
   delete root;
   //delete inPutString;
}

void TreeMaker::printAbc(Tree *root) {
    if (!root) {
        return;
    }
    else {
    }
    if (isFunction(root->value)) {
        cout << "(";
        root->printChar();
    }
    else {
        root->printInt();
    }
    printAbc(root->left);
    printAbc(root->right);
    if (isFunction(root->value))
        cout << ")";
    return;
}

int TreeMaker::managerSymbol(char a){
    if (a >= '0' && a <= '9')
        return 0;
    if (a == '+' || a == '*' || a == '-' || a == '/')
        return 1;
    if (a == '(')
        return 2;
    if (a == ')')
        return 3;
    return -1;
}

int TreeMaker::readFile(char *name) {
    ifstream inFile;
    inFile.open(name, ios::in);
    if (!(inFile.is_open())) {
         cout << "Where is your file ???" << endl;
         return 1;
    }
    char line[maxlength];
    for (int i = 0; i < maxlength; i ++)
        line[i] = '\0';
    int position = 0;
    while (inFile.good()) {
        inFile >> line[position++];
    }
    int length = strlen(line);
    char *slot = new char[length];
    for (int i = 0 ; i < length; i++)
        slot[i] = line[i];
    inPutString = slot;
    length = strlen(inPutString);
    for (int i = strlen(line); i < length; i++) {
        inPutString[i] = '\0';
    }
    inFile.close();
    return 0;
}

void TreeMaker::addLeft(int value) {
    Tree * newT = new Tree;
    newT->parent = currentPoint;
    newT->value = value;
    currentPoint->left = newT;
}

void TreeMaker::addRight(int value){
    Tree * newT = new Tree;
    newT->parent = currentPoint;
    newT->value = value;
    currentPoint->right = newT;
}


void TreeMaker::buildTree() {
    int position = 0;
    int length = strlen(inPutString);

    // добавил в вершину символ не скобку
    while (inPutString[position] == ')')
        position++;
    currentPoint = new Tree;
    currentPoint->value = inPutString[position++];
    root = currentPoint;
    while (position < length) {
        switch(managerSymbol(inPutString[position])) {
            case digit:
                if (!currentPoint->left) {
                    addLeft(int(inPutString[position])-int('0'));
                }
                else
                    if (!currentPoint->right) {
                        addRight(int(inPutString[position]) - int('0'));
                    }
                break;
            case function:
                currentPoint->value = inPutString[position];
                break;
            case open:
                if (!currentPoint->left) {
                    addLeft(zero);
                    currentPoint = currentPoint->left;
                }
                else
                    if (!currentPoint->right) {
                        addRight(zero);
                        currentPoint = currentPoint->right;
                    }
                break;
            case close:
                if (currentPoint->parent)
                    currentPoint = currentPoint->parent;
                break;
        }
        position++;
    }
    Tree *slot = root;
    cout << "built:\n";
    printAbc(slot);
    cout << endl;
}

bool TreeMaker::isFunction(char a) {
    return a == int('+') || a == int('-') || a == int('*') || a == int('/');
}

int TreeMaker::getResult() {
    if (root) {
    while (root->left || root->right) {
        calcTree(root);
    }
    if (root)
        return root->value;
    else
        return -1;
    }
    return -1;
}

void TreeMaker::calcTree(Tree *point) {
    if (!point)
        return;
    calcTree(point->left);
    point->calculate();
    calcTree(point->right);
}

