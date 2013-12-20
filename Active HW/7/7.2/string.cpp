#include "stringFunctions.h"

using namespace std;
using namespace listFunctions;

enum Change { exitS, createS, printS, delS, sumS, copyS, sameS, lenghtS, emptyS, partS, charS };
Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {
	strings *begin = nullptr;
	strings *end = nullptr;
	int length = 0;
	cout << "/n do not use space-symbol\n";
	cout << "Welcome!\n 0=exit\n 1=create\n 2=print\n 3=delete\n 4=sum\n 5=clone\n 6=same \n 7=length \n 8=empty \n 9=make part \n 10=to char*\n";
	for (;;) {
		cout << "enter the state\n";
		int changeTemp = 0;
		Change state;
		cin >> changeTemp;
		state = intToChange(changeTemp);

		if (state == exitS) {
			cout << "L.A. GoodBay\n";
			break;
		}

		if (state == createS) {
			if (length != 0) {
				cout << "we have already one\n";
			}
			else {
				char buffer[maxBufferSize] = { -1 };
				cout << "enter the string\n";
				cin >> buffer;
				create(buffer, &begin, &end);
				length = strlen(buffer);
			}
		}

		if (state == printS) {
			if (length == 0) {
				cout << "nothing to print\n";
			}
			else {
				print(begin);
			}
		}

		if (state == delS) {
			if (length == 0) {
				cout << "nothing to delete\n";
			}
			else {
				strings *slot = nullptr;
				while (begin) {
					slot = begin;
					begin = begin->next;
					delete slot;
				}
				begin = nullptr;
				end = nullptr;
				length = 0;
			}
		}

		if (state == sumS) {
			if (length == 0) {
				cout << "nothing to sum \n";
			}
			else {
				length = plusS(&end, length);
			}
		}

		if (state == copyS) {
			if (length == 0) {
				cout << "nothing to clone \n";
			}
			else {
				clone(begin, &end, length);
				length *= 2;
			}
		}

		if (state == sameS) {
			if (length == 0) {
				cout << "firstly enter the string\n";
			}
			else {
				char buf2[maxBufferSize] = { -1 };
				cout << "enter the string\n";
				cin >> buf2;
				if (same(buf2, begin, end))
					cout << "same\n";
				else
					cout << "not same\n";
			}
		}

		if (state == lenghtS) {
			char buffer[maxBufferSize] = { -1 };
			cout << "enter the string\n";
			cin >> buffer;
			cout << "length  is " << strlen(buffer) << endl;
		}

		if (state == emptyS) {
			char buf2[maxBufferSize] = { -1 };
			cout << "enter the string\n";
			cin >> buf2;
			if (strlen(buf2) == 0) {
				cout << "empty\n";
			}
			else
				cout << "not empty\n";
		}

		if (state == partS) {
			if (length == 0) {
				cout << "error!\n";
			}
			else {
				cout << "enter start\n";
				int start = 0;
				cin >> start;
				cout << "enter finish\n";
				int finish = 0;
				cin >> finish;
				char *m = transform(begin, length);
				char *n = halfString(m, start, finish);
				cout << n << endl;
			}
		}

		if (state == charS) {
			if (length == 0) {
				cout << "error!";
			}
			else {
				char *p = &begin->string[0];
				char *m = transform(begin, length);
				cout << "cheking\n";
				cout << m << endl;
			}
		}

	}

	freeMemory(begin);
	return 0;
}