#include "FunctionsNames.h"

int readLineFromFile() {
	stackMemory * top = nullptr;
	dataMemory *begin = nullptr;
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
		commandManager(line,&top, &begin);
		clearLine(line);
	}
	fclose(inFile);
	showStack(&top);
	//addToData(&begin, 4, 14);
	showData(&begin);
	removeStack(&top);
	removeData(&begin);
	//printf("\n%d\n",begin->next->next->next->next->next->value);
	return 0;
}


void commandManager(char line[lengthCommand], stackMemory ** top, dataMemory **begin) {
	//printf("%s",line);
	
	// ldc <number> 
	if (strlen(line) >= 4 && line[0] == 'l' && line[1] == 'd' && line[2] == 'c') {
		int number = getIntFromChar(line,4);
		//printf("%d\n\n",number);
		addToStack(&(*top),number);
	}

	// st <adress> 
	if (strlen(line) >= 3 && line[0] == 's' && line[1] == 't') {
		int number = getIntFromChar(line,3);
		//printf("%d\n\n",number);
		addToData(&(*begin), number, popStack(&(*top)));
		//addToStack(&(*top),number);
	}
}