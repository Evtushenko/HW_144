#include "FunctionsNames.h"

void clearLine(char string[lengthCommand]) {
	for (int i = 0; i < lengthCommand; i++ ) {
		string[i]='\0';
	}
}

bool isDigit(char a) {
	return a >= '0' && a <= '9';
}

int getIntFromChar(char string[], int start ) {
	int number = 0;
	for (int i= start; i < strlen(string) ; i++ ) {
		if (isDigit(string[i]))
			number+=powl(10,strlen(string)-i-2)*int(string[i]-'0');
	}
	return number;
}

void showData(int dataList[]){
	printf("List of Data:\n");
	for (int i = 0; i < amountDataCells; i++)
		if (dataList[i] != 0 )
			printf("%d\n",dataList[i]);
}

codeStrings *addCodeString(char input[lengthCommand]) {
    codeStrings *newC = (codeStrings *) malloc(sizeof(codeStrings));
	for (int i = 0 ; i < lengthCommand; i++)
		newC->codeText[i] = '\0';
	strcpy(newC->codeText,input);
	for (int i = 0; i < strlen(input); i++)
		newC->codeText[i] = input[i];
	return newC;
}

void addToReturnPoints(returnPoints **begin, returnPoints **end, int number, char name[lengthCommand]) {
	returnPoints *newR = (returnPoints *) malloc(sizeof(returnPoints));
	newR->next = nullptr;
	for (int i = 0; i < lengthCommand; i++) 
		newR->nameReturnPoint[i] = '\0';
	strcpy(newR->nameReturnPoint,name);
	for (int i = 0; i < strlen(name); i++) 
		newR->nameReturnPoint[i] = name[i];
	newR->numberStringOfReturnPoint = number;
	if (*begin == nullptr) {
		*begin = newR;
		*end = newR;
	}
	else {
		(*end)->next = newR;
		*end = newR;
	}
}


int findNumberReturnPoint(char name[lengthCommand], returnPoints *beginListRP) {
	returnPoints *helper = beginListRP;
	while (helper) {
		bool result = true;
		for (int i = 0; i < strlen(name)-1 && i < strlen(helper->nameReturnPoint)-1; i++) {
			if (name[i] != helper->nameReturnPoint[i]) {
				result = false;
			}
		}
		if (result)
			return helper->numberStringOfReturnPoint;
		helper = helper->next;
	}
	return -1;
}

int getNumberFunction(char line[]) {
//enum Change { ldc, st, ld, add, sub, cmp, jmp, jnz, jz, jg, jl, ret};
//               0    1   2   3     4    5    6    7   8   9  10  11
	if (strlen(line) >= 4 && line[0] == 'l' && line[1] == 'd' && line[2] == 'c') {
		return 0;
	}
	if (strlen(line) >= 3 && line[0] == 's' && line[1] == 't')
		return 1;
	if (strlen(line) >= 3 && line[0] == 'l' && line[1] == 'd')
		return 2;
	if (strlen(line) >= 4 && line[0] == 'a' && line[1] == 'd' && line[2] == 'd')
		return 3;
	if (strlen(line) >= 4 && line[0] == 's' && line[1] == 'u' && line[2] == 'b')
		return 4;
	if (strlen(line) >= 4 && line[0] == 'c' && line[1] == 'm' && line[2] == 'p')
		return 5;
	if (strlen(line) >= 4 && line[0] == 'j' && line[1] == 'm' && line[2] == 'p') {
		return 6;
	}
	if (strlen(line) >= 4 && line[0] == 'j' && line[1] == 'n' && line[2] == 'z')
		return 7;
	if (strlen(line) >= 3 && line[0] == 'j' && line[1] == 'z')
		return 8;
	if (strlen(line) >= 3 && line[0] == 'j' && line[1] == 'g')
		return 9;
	if (strlen(line) >= 3 && line[0] == 'j' && line[1] == 'l')
		return 10;
	if (strlen(line) >= 4 && line[0] == 'r' && line[1] == 'e' && line[2] == 't')
		return 11;
	return -1;
}

void makeZero(int arr[], int amount) {
	for (int i = 0; i < amount; i++)
		arr[i] = -1;
}