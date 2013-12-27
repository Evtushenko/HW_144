#include "expressionFunction.h"

using namespace expression;
using namespace std;

int main() {
	cout << "uses rules:\n";
	cout << " E-> TE'\n";
	cout << " E'-> (+|-)TE'|e\n";
	cout << " T-> FT'\n";
	cout << " T'-> (*|/)FT'|e\n";
	cout << " F-> (E)|id\n";
	cout <<"enter the expression\n";

	char string[maxBufferSize];
	for (int i = 0; i < maxBufferSize; i++){
		string[i] = '\0';
	}
	cin.getline(string, maxBufferSize);

	int position = 0;
	if (isCorrect(position, string)) {
		cout << "correct\n";
	}
	else {
		cout << "incorrect\n";
	}
	return 0;
}