#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

void print(int number, char *words []) {
	int divisor = 100;

	if (number / divisor != 0) {
		cout << words[number / 100] << " hundred ";
		number %= divisor;
		if (number) {
			cout << "and ";
		}
	}
	divisor = 10;
	if (number / divisor != 0) {
		if (number / divisor == 1) {
			cout << words[10 + number % divisor] << " ";
			return;
		}
		else {
			cout << words[18 + number / divisor] << " ";
		}

		if (number % divisor != 0) {
			cout << "- ";
		}

	}
	if (number % divisor != 0) {
		cout << words[number % divisor] << " ";
	}
}

int main() {
	char **words = new char *[33];
	for (int i = 0; i < 33; i++)
		words[i] = new char[10];
	cout << "enter the number" << endl;
	int number;
	cin >> number;
	if (!number)
		cout << words[0] << endl;
	else
	{

		if (number < 0){
			cout << "minus ";
			number = number * (-1);
		}

		// создали массив слов //
		words[0] = "zero";
		words[1] = "one";
		words[2] = "two";
		words[3] = "three";
		words[4] = "four";
		words[5] = "five";
		words[6] = "six";
		words[7] = "seven";
		words[8] = "eight";
		words[9] = "nine";
		words[10] = "ten";
		words[11] = "eleven";
		words[12] = "twelve";
		words[13] = "thirteen";
		words[14] = "fourteen";
		words[15] = "fifteen";
		words[16] = "sixteen";
		words[17] = "seventeen";
		words[18] = "eighteen";
		words[19] = "nineteen";
		words[20] = "twenty";
		words[21] = "thirty";
		words[22] = "forty";
		words[23] = "fifty";
		words[24] = "sixty";
		words[25] = "seventy";
		words[26] = "eighty";
		words[27] = "ninety";

		int firstPart = number / 1000;
		int secondPart = number % 1000;

		if (firstPart != 0) {
			print(firstPart, words);
			cout << "thousand ";
		}
			print(secondPart, words);
	}

	// "free memory" doesn't work(- 

	/*for (int i = 0; i < 33; i++)
	{
	delete [] words[i];
	words[i] = nullptr;
	}
	delete [] words;
	words=nullptr;*/

	return 0;
}