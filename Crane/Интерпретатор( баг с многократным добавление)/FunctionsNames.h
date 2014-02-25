#pragma once
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

// top, begin belong to readFromFile

const int lengthCommand = 10;
const long long amountDataCells = 2^18-1;

struct stackMemory {
	stackMemory *previous;
	int value;
};

//         SMALL SUPPORT FUNCTIONS 
bool isDigit(char a);
void clearLine(char string[lengthCommand]);
int getIntFromChar(char string[], int start );
void showData(int dataList[]);

//				MAJOR FUNCTIONS
int readLineFromFile();
void commandManager(char line[lengthCommand], stackMemory ** top, int dataList[]);


//          STACK FUNCTIONS 
void addToStack(stackMemory ** top, int value, int &amountElementsStack); 
void removeStack(stackMemory ** top);
void showStack(stackMemory ** top);
int popStack(stackMemory ** top, int &amountElementsStack);