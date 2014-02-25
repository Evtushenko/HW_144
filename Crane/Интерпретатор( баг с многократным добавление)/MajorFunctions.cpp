#include "FunctionsNames.h"

int readLineFromFile() {
	stackMemory * top = nullptr;
	int *dataList = new int[amountDataCells];
	for (int i = 0; i < amountDataCells; i++)
		dataList[i] = 0;
	FILE *inFile;
	if (fopen_s(&inFile, "prg.txt", "r")){
		printf("\nCant find file\n");
		return 1;
	}
	char *line = new char[lengthCommand];
	clearLine(line);
	while (fgets(line, lengthCommand, inFile) != nullptr) { // eat strings
		//printf("%s",line);
		//printf("\nl = %d", strlen(line));
		//printf("\n");
		commandManager(line,&top, dataList);
		clearLine(line);
	}
	fclose(inFile);
	showStack(&top);
	showData(dataList);
	delete []dataList;
	removeStack(&top);
	return 0;
}


void commandManager(char line[lengthCommand], stackMemory ** top, int dataList[]) {
	int static amountElementsStack = 0;
	printf("%s",line);
	
	// ldc <number> 
	if (strlen(line) >= 4 && line[0] == 'l' && line[1] == 'd' && line[2] == 'c') {
		int number = getIntFromChar(line,4);
		//printf("%d\n\n",number);
		addToStack(&(*top),number,amountElementsStack);
	}

	// st <adress> 
	if (strlen(line) >= 3 && line[0] == 's' && line[1] == 't') {
		int number = getIntFromChar(line,3);
		//printf("%d\n\n",number);
		//addToData(&(*begin), number, popStack(&(*top)));
		//addToStack(&(*top),number);
		dataList[number] = popStack(&(*top),amountElementsStack);
	}

	// ld <adress>
	if (strlen(line) >= 3 && line[0] == 'l' && line[1] == 'd' && line[2] != 'c') {
		//printf("OK\n");
		int number = getIntFromChar(line,3);
		addToStack(&(*top), dataList[number],amountElementsStack );
		dataList[number] = 0; // ??
	}

	// add
	if (strlen(line) >= 3 && line[0] == 'a' && line[1] == 'd' && line[2] == 'd') {
		int number = 0;
		if (amountElementsStack  < 2 )
			printf("found out error!\n");
		else {
			number+=popStack(&(*top),amountElementsStack);
			number+=popStack(&(*top),amountElementsStack);
			addToStack(&(*top),number,amountElementsStack);
		}
	}

	// sub
	if (strlen(line) >= 3 && line[0] == 's' && line[1] == 'u' && line[2] == 'b') {
		int number = 0;
		if (amountElementsStack  < 2 )
			printf("found out error!\n");
		else {
			number+=popStack(&(*top),amountElementsStack);
			number-=popStack(&(*top),amountElementsStack);
			addToStack(&(*top),number,amountElementsStack);
		}
	}
	//printf("in stack %d elements\n\n",amountElementsStack);
}