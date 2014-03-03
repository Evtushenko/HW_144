#pragma once
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

// top, begin belong to readFromFile

// strcmp где можно
// список команд, чтобы ускорить работу
// поробовать написать прогу

const int lengthCommand = 10;
const long long amountDataCells = 1024*256;
const int maxAmountStrings = 100;

struct stackMemory {
	stackMemory *previous;
	int value;
};

struct codeStrings {
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
int getNumberFunction(char line[]);

//				MAJOR FUNCTIONS
int readLineFromFile();
void commandManager(stackMemory ** top, int dataList[], codeStrings *allStringsCode[maxAmountStrings],int amountReadedStrings );



//          STACK FUNCTIONS 
void addToStack(stackMemory ** top, int value); 
void removeStack(stackMemory ** top);
void showStack(stackMemory ** top);
int popStack(stackMemory ** top);
