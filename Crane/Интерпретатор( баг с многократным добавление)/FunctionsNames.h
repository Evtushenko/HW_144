#pragma once
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

// top, begin belong to readFromFile

const int lengthCommand = 10;

struct stackMemory {
	stackMemory *previous;
	int value;
};

struct dataMemory {
	dataMemory *next;
	int adress;
	int value;
};

//         SMALL SUPPORT FUNCTIONS 
bool isDigit(char a);
void clearLine(char string[lengthCommand]);
int getIntFromChar(char string[], int start );

//				MAJOR FUNCTIONS
int readLineFromFile();
void commandManager(char line[lengthCommand], stackMemory ** top, dataMemory **begin);


//          STACK FUNCTIONS 
void addToStack(stackMemory ** top, int value);
void removeStack(stackMemory ** top);
void showStack(stackMemory ** top);
int popStack(stackMemory ** top);
//         DATA FUNCTIONS 
void addToData(dataMemory ** begin, int adress, int value);
void removeData(dataMemory ** top);
void showData(dataMemory ** top);