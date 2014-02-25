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