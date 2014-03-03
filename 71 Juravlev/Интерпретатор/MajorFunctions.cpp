#include "FunctionsNames.h"

enum Change { ldc, st, ld, add, sub, cmp, jmp, jnz, jz, jg, jl, ret};
//             0    1   2   3     4    5    6    7   8   9  10  11
Change intToChange(int one) {
	return static_cast<Change>(one);
}

int readLineFromFile() {
	stackMemory * top = nullptr;
	int *dataList = new int[amountDataCells];
	for (int i = 0; i < amountDataCells; i++)
		dataList[i] = 0;

	FILE *inFile;
	if (fopen_s(&inFile, "prg.txt", "r")) {
		printf("\nCant find file\n");
		return 1;
	}

	char line[lengthCommand];
	clearLine(line);

	codeStrings *allStringsCode[maxAmountStrings];
	for (int i = 0; i < maxAmountStrings; i++)
		allStringsCode[i] = nullptr;
	int amountReadedStrings = 0;

	while (fgets(line, lengthCommand, inFile) != nullptr) { // eat strings
		allStringsCode[amountReadedStrings++] = addCodeString(line);
		clearLine(line);
	}
	//printf("%s",allStringsCode[10]);
	//return 0;
	fclose(inFile);
	commandManager(&top, dataList,allStringsCode,amountReadedStrings);
	showStack(&top);
	showData(dataList);
	delete []dataList;
	for (int i = 0; i < amountReadedStrings; i++)
		free(allStringsCode[i]);
	removeStack(&top);
	return 0;
}


void commandManager(stackMemory ** top, int dataList[], codeStrings *allStringsCode[maxAmountStrings],int amountReadedStrings ) {
	int static timesCompleted = 0;
	bool static stopProgram = false;
	if (!stopProgram) {
	int static currentNumberString = 0;
	returnPoints static *beginListRP = nullptr;
	returnPoints static *endListRP = nullptr;
	int static amountReturnPoints = 0;

	char line[lengthCommand];
	clearLine(line);
	for (int i = 0; i < strlen(allStringsCode[currentNumberString]->codeText); i++){
		line[i] = allStringsCode[currentNumberString]->codeText[i];
	}
	printf("%s",line);

	// is it return point???
	bool returnPointFound = false;
	int positionSymbol = 0;
	for (int i= 0; i < strlen(line); i++ ){
		if (line[i] == ':') {
			returnPointFound = true;
			positionSymbol = line[i];
			printf("test\n");
			break;
		}
	}
	if (returnPointFound && currentNumberString < amountReadedStrings) {
		for (int i = positionSymbol; i < lengthCommand; i++)
			line[i] = '\0';
		addToReturnPoints(&beginListRP, &endListRP, currentNumberString, line);
		amountReturnPoints++;
	}

	// ldc <number> 
	//if (strlen(line) >= 4 && line[0] == 'l' && line[1] == 'd' && line[2] == 'c') {
	if (intToChange(getNumberFunction(line)) == ldc) {
		int number = getIntFromChar(line,4);
		addToStack(&(*top),number);
	}

	// st <adress> 
	if (intToChange(getNumberFunction(line)) == st) {
		int number = getIntFromChar(line,3);
		dataList[number] = popStack(&(*top));
	}

	// ld <adress>
	if (intToChange(getNumberFunction(line)) == ld) {
		int number = getIntFromChar(line,3);
		addToStack(&(*top), dataList[number]);
		dataList[number] = 0; // ??
	}

	// add
	if (intToChange(getNumberFunction(line)) == add) {	
		int number = 0;
		if ((*top) && (*top)->previous )
			printf("found out error!\n");
		else {
			number+=popStack(&(*top));
			number+=popStack(&(*top));
			addToStack(&(*top),number);
		}
	}

	// sub
	if (intToChange(getNumberFunction(line)) == sub) {
		int number = 0;
		if ((*top) && (*top)->previous )
			printf("found out error!\n");
		else {
			number+=popStack(&(*top));
			number-=popStack(&(*top));
			addToStack(&(*top),number);
		}
	}

	//cmp
	if (intToChange(getNumberFunction(line)) == cmp) {
		int number = 0;
		int number2 = 0;
		if ((*top) && (*top)->previous)
			printf("found out error!\n");
		else {
			number = (*top)->value;
			number2 = (*top)->previous->value;
			if (number == number2)
			addToStack(&(*top),0);
			if (number > number2)
			addToStack(&(*top),1);
			if (number < number2)
			addToStack(&(*top),-1);
		}
	}

	//jmp
	if (intToChange(getNumberFunction(line)) == jmp) {
		char nameReturnPoint[lengthCommand];
		clearLine(nameReturnPoint);
		for (int i = 4; i < strlen(line) ; i++) {
			nameReturnPoint[i - 4] = line[i];
		}
		if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
			printf("NOT FOUND RETURN POINT\n");
		else {
			currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
		}
	}

	//jnz
	if (intToChange(getNumberFunction(line)) == jnz) {
		if (*top && (*top)->value != 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 4; i < strlen(line) ; i++) {
				nameReturnPoint[i - 4] = line[i];
			}
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JNZ\n");
		}
	}

	//jz
	if (intToChange(getNumberFunction(line)) == jz) {
		if (*top && (*top)->value == 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 3; i < strlen(line) ; i++) {
				nameReturnPoint[i - 3] = line[i];
			}
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JZ\n");
		}
	}

	//jg
	if (intToChange(getNumberFunction(line)) == jg) {
		if (*top && (*top)->value > 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 3; i < strlen(line) ; i++) {
				nameReturnPoint[i - 3] = line[i];
			}
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JG\n");
		}
	}

	//jl
	if (intToChange(getNumberFunction(line)) == jl) {
		if (*top && (*top)->value < 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 3; i < strlen(line) ; i++) {
				nameReturnPoint[i - 3] = line[i];
			}
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JL\n");
		}
	}

	if (strlen(line) >= 1 && line[0] == ';') {
		printf("\ncommentary: ");
		for (int i=0 ; i < strlen(line); i++)
			printf("%c",line[i]);
		printf("\n");
	}


	currentNumberString++;
	timesCompleted++;
	// found out not-ending
	if (timesCompleted > amountReadedStrings*2) {
		returnPoints  * slot = nullptr;
			while(beginListRP) {
				slot = beginListRP;
				beginListRP = beginListRP->next;
				free(slot);
			}
		stopProgram = true;
	}

	if (currentNumberString == amountReadedStrings - 1 && !(intToChange(getNumberFunction(line)) == ret) )
		printf("NOT FOUND END OF PROGRAM! CRITICAL ERROR!\n");
	if (currentNumberString < amountReadedStrings)
		commandManager(&(*top),dataList,allStringsCode,amountReadedStrings);
}
}

