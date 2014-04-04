#ifndef TREEMAKER_H
#define TREEMAKER_H
#include <fstream>
#include <iostream>
#include <string.h>
#include "tree.h"

int const maxlength = 50;
char const zero = '0';

class TestTreeMaker;

/**
@brief class for user working with Tree class
*/

class TreeMaker {
friend class TestTreeMaker;
public:
    TreeMaker();
    ~TreeMaker();
    /**
    @brief reading expression form text file
    @param name of file
    */
    int readFile(char *name);
    /**
    @brief bulding a calulate tree based on text file
    */
    void buildTree();
    /**
    @brief calculate expression using Calc Tree
    */
    int getResult();
private:
    char *inPutString;
    Tree *root;
    Tree *currentPoint;
    void addLeft(int value);
    void addRight(int value);
    /**
    @brief printing like exapmle scription
    */
    void printAbc(Tree *root);
    bool isFunction(char a);
    /**
    @brief takes char return it's number
    */
    int managerSymbol(char a);
    /**
    @brief going one lap around the tree, and calculating if it is possible
    */
    void calcTree(Tree *point);

};


#endif // TREEMAKER_H
