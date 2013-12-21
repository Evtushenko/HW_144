#include <iostream>
#include <cstdlib>
#include <string.h>

int const binaryExponent = 256;
int const maxStringLength = 100;
int const primeNumber = 7;

using namespace std;

void algorithmRK(char fullString[], char subString[]){
	int lengthSubString = strlen(subString);
	int lengthFullString = strlen(fullString);
	int hashSubString = 0;
	int hashFullString = 0;
	int hash = 1;

	for (int i = 0; i < lengthSubString - 1; i++){
		hash = (binaryExponent * hash) % primeNumber;
	}

	for (int i = 0; i < lengthSubString; i++){
		hashSubString = (binaryExponent*hashSubString + subString[i]) % primeNumber;
		hashFullString = (binaryExponent*hashFullString + fullString[i]) % primeNumber;

	}

	for (int i = 0; i <= lengthFullString - lengthSubString; i++){
		if (hashFullString == hashSubString){
			int j = 0;
			for (j; j < lengthSubString; j++){
				if (fullString[i + j] != subString[j]) {
					break;
				}
			}
			if (j == lengthSubString)
				cout << "Pattern matched at index " << i << endl;
		}
		if (i < lengthFullString - lengthSubString){
			hashFullString = (binaryExponent * (hashFullString - fullString[i] * hash) + fullString[i + lengthSubString]) % primeNumber;
			if (hashFullString < 0)
				hashFullString = (hashFullString + primeNumber);
		}
	}
}

int main() {
	char fullString[maxStringLength];
	char subString[maxStringLength];
	cout << "Enter the string" << endl;
	gets_s(fullString);
	cout << "Enter the sub-string you wish to search for" << endl;
	gets_s(subString);
	algorithmRK(fullString, subString);
	return 0;
}