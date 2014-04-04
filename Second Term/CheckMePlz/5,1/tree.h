#ifndef TREE_H
#define TREE_H
#include <iostream>

class TreeMaker;
class TestTreeMaker;
class TestTree;

/**
@brief class for Tree element(leaf)
*/
class Tree {
friend class TreeMaker;
friend class TestTreeMaker;
friend class TestTree;
private:
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
    bool isDigit(int a);
    bool letCalc();
};

#endif // TREE_H
