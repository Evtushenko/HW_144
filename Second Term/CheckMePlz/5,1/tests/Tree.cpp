#include "tree.h"

Tree::Tree(): left(NULL), right(NULL), parent(NULL) {}

void Tree::printChar() {
    std::cout << char(value);
}

void Tree::printInt() {
    std::cout << value;
}

bool Tree::isDigit(int a){
    return a >= 0 && a <= 9;
}

 void Tree::calculate() {
     if (left && isDigit(left->value) && right && isDigit(right->value)) {
         int result = 0;
         switch (value) {

         case '+':
             result = int(left->value) + int(right->value);
             break;

         case '-':
             result = int(left->value) - int(right->value);
             break;

         case '*':
             result = int(left->value) * int(right->value);
             break;

         case '\\':
             result = int(left->value) / int(right->value);
             break;
         }
         delete left;
         left = NULL;
         delete right;
         right = NULL;
         value = result;
     }
 }
