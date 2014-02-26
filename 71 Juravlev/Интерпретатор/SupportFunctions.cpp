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
	codeStrings *newC = new codeStrings;
	for (int i = 0 ; i < lengthCommand; i++)
		newC->codeText[i] = '\0';
	for (int i = 0; i < strlen(input); i++)
		newC->codeText[i] = input[i];
	return newC;
}

void addToReturnPoints(returnPoints **begin, returnPoints **end, int number, char name[lengthCommand]) {
	returnPoints *newR = new returnPoints;
	newR->next = nullptr;
	for (int i = 0; i < lengthCommand; i++) 
		newR->nameReturnPoint[i] = '\0';
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
	//printf("\n\n%s\n\n",name);
	//printf("\n\n%d\n\n",strlen(name));
	//printf("start test\n");
	while (helper) {
		bool result = true;
		//printf("start test\n");
		for (int i = 0; i < strlen(name)-1 && i < strlen(helper->nameReturnPoint)-1; i++) {
			//printf("==\n");
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