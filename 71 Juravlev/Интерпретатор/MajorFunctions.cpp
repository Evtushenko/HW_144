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

	codeStrings *allStringsCode[maxAmountStrings];
	for (int i = 0; i < maxAmountStrings; i++)
		allStringsCode[i] = nullptr;
	int amountReadedStrings = 0;

	while (fgets(line, lengthCommand, inFile) != nullptr) { // eat strings
		//printf("%s",line);
		//printf("\nl = %d", strlen(line));
		//printf("\n");
		allStringsCode[amountReadedStrings++] = addCodeString(line);
		clearLine(line);
	}
	fclose(inFile);
	commandManager(&top, dataList,allStringsCode,amountReadedStrings);
	showStack(&top);
	showData(dataList);
	delete []dataList;
	removeStack(&top);
	//printf("%s\n",allStringsCode[0]->codeText);
	//printf("%d\n",strlen(allStringsCode[0]->codeText));
	return 0;
}


void commandManager(stackMemory ** top, int dataList[], codeStrings *allStringsCode[maxAmountStrings],int amountReadedStrings ) {
	int static timesCompleted = 0;
	bool static stopProgram = false;
	if (!stopProgram) {
	int static currentNumberString = 0;
	int static amountElementsStack = 0;
	returnPoints static *beginListRP = nullptr;
	returnPoints static *endListRP = nullptr;
	int static amountReturnPoints = 0;
	
	char *line = new char[lengthCommand];
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
		//printf("\n\n%d\n\n",beginListRP->numberStringOfReturnPoint);
	}

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

	//cmp
	if (strlen(line) >= 3 && line[0] == 'c' && line[1] == 'm' && line[2] == 'p') {
		int number = 0;
		int number2 = 0;
		if (amountElementsStack  < 2 )
			printf("found out error!\n");
		else {
			number = (*top)->value;
			number2 = (*top)->previous->value;
			if (number == number2)
			addToStack(&(*top),0,amountElementsStack);
			if (number > number2)
			addToStack(&(*top),1,amountElementsStack);
			if (number < number2)
			addToStack(&(*top),-1,amountElementsStack);
		}
	}

	//jmp
	if (strlen(line) >= 3 && line[0] == 'j' && line[1] == 'm' && line[2] == 'p') {
		char nameReturnPoint[lengthCommand];
		clearLine(nameReturnPoint);
		for (int i = 4; i < strlen(line) ; i++) {
			nameReturnPoint[i - 4] = line[i];
		}
		//printf("%s\n",nameReturnPoint);
		//printf("\n\n%d\n\n",findNumberReturnPoint("call", beginListRP));
		if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
			printf("NOT FOUND RETURN POINT\n");
		else {
			currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
		}
		//printf("\n\n%d\n\n",findNumberReturnPoint(nameReturnPoint, beginListRP));
	}

	//jnz
	if (strlen(line) >= 3 && line[0] == 'j' && line[1] == 'n' && line[2] == 'z') {
		if (*top && (*top)->value != 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 4; i < strlen(line) ; i++) {
				nameReturnPoint[i - 4] = line[i];
			}
			//printf("%s\n",nameReturnPoint);
			//printf("\n\n%d\n\n",findNumberReturnPoint("call", beginListRP));
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JNZ\n");
		}
		//printf("\n\n%d\n\n",findNumberReturnPoint(nameReturnPoint, beginListRP));
	}

	//jz
	if (strlen(line) >= 2 && line[0] == 'j' && line[1] == 'z') {
		if (*top && (*top)->value == 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 3; i < strlen(line) ; i++) {
				nameReturnPoint[i - 3] = line[i];
			}
			//printf("%s\n",nameReturnPoint);
			//printf("\n\n%d\n\n",findNumberReturnPoint("call", beginListRP));
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JZ\n");
		}
		//printf("\n\n%d\n\n",findNumberReturnPoint(nameReturnPoint, beginListRP));
	}

	//jg
	if (strlen(line) >= 2 && line[0] == 'j' && line[1] == 'g') {
		if (*top && (*top)->value > 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 3; i < strlen(line) ; i++) {
				nameReturnPoint[i - 3] = line[i];
			}
			//printf("%s\n",nameReturnPoint);
			//printf("\n\n%d\n\n",findNumberReturnPoint("call", beginListRP));
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JG\n");
		}
		//printf("\n\n%d\n\n",findNumberReturnPoint(nameReturnPoint, beginListRP));
	}

	//jl
	if (strlen(line) >= 2 && line[0] == 'j' && line[1] == 'l') {
		if (*top && (*top)->value < 0) {
			char nameReturnPoint[lengthCommand];
			clearLine(nameReturnPoint);
			for (int i = 3; i < strlen(line) ; i++) {
				nameReturnPoint[i - 3] = line[i];
			}
			//printf("%s\n",nameReturnPoint);
			//printf("\n\n%d\n\n",findNumberReturnPoint("call", beginListRP));
			if (findNumberReturnPoint(nameReturnPoint, beginListRP) == -1)
				printf("NOT FOUND THIS RETURN POINT\n");
			else {
				currentNumberString -=findNumberReturnPoint(nameReturnPoint, beginListRP); //
			}
		}
		else {
			printf("ERROR WITH JL\n");
		}
		//printf("\n\n%d\n\n",findNumberReturnPoint(nameReturnPoint, beginListRP));
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
		stopProgram = true;
	}
	if (currentNumberString == amountReadedStrings - 1 && !(strlen(line) >=3 && line[0] == 'r' && line[1] == 'e' && line[2] == 't'))
		printf("NOT FOUND END OF PROGRAM! CRITICAL ERROR!\n");
	if (currentNumberString < amountReadedStrings -1)
		commandManager(&(*top),dataList,allStringsCode,amountReadedStrings);
	
	//printf("\n%d\n",currentNumberString);

}
}