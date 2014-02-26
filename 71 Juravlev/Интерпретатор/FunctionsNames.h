#pragma once
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

// top, begin belong to readFromFile

const int lengthCommand = 10;
const long long amountDataCells = 2^18-1;
const int maxAmountStrings = 100;

struct stackMemory {
	stackMemory *previous;
	int value;
};

struct codeStrings {
	//codeStrings* next;
	char codeText[lengthCommand];
};

struct returnPoints {
	returnPoints *next;
	char nameReturnPoint[lengthCommand];
	int numberStringOfReturnPoint;
};

//         SMALL SUPPORT FUNCTIONS 
bool isDigit(char a);
void clearLine(char string[lengthCommand]);
int getIntFromChar(char string[], int start );
void showData(int dataList[]);
codeStrings *addCodeString(char input[lengthCommand]);
void addToReturnPoints(returnPoints **begin, returnPoints **end, int number, char name[lengthCommand]);
int findNumberReturnPoint(char name[lengthCommand], returnPoints *beginListRP);

//				MAJOR FUNCTIONS
int readLineFromFile();
void commandManager(stackMemory ** top, int dataList[], codeStrings *allStringsCode[maxAmountStrings],int amountReadedStrings );


//          STACK FUNCTIONS 
void addToStack(stackMemory ** top, int value, int &amountElementsStack); 
void removeStack(stackMemory ** top);
void showStack(stackMemory ** top);
int popStack(stackMemory ** top, int &amountElementsStack);