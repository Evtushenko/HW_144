#ifndef TREE_H
#define TREE_H
#include <iostream>

/**
@brief class for Tree element(leaf)
*/
class Tree
{
public:
    Tree();
    Tree *left;
    Tree *right;
    Tree *parent;
    int value;
    /**
    @brief just printing value of class element if it's char
    */
    void printChar();
    /**
    @brief just printing value of class element if it's number
    */
    void printInt();
    /**
    @brief if class elements is function and his children both are numbers it will be calulated
    children will be deleted, result will be a new value of current element
    */
    void calculate();
private:
     bool isDigit(int a);
};

#endif // TREE_H
