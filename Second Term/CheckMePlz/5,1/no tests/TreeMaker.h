#ifndef TREEMAKER_H
#define TREEMAKER_H
#include <fstream>
#include <iostream>
#include <string.h>
#include "Tree.h"

int const maxlength = 50;
char const zero = '0';

/**
@brief class for user working with Tree class
*/

class TreeMaker
{
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
    Tree *root;
    char *inPutString;
    /**
    @brief printing like exapmle scription
    */
    void printAbc(Tree *root);
    bool isFunction(char a);
    Tree *currentPoint;
    void addLeft(int value);
    void addRight(int value);
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
