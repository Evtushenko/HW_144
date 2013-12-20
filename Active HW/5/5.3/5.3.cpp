#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
	char str[100];
	ifstream read;
	read.open("q.txt", ios::in);
	cout << " using:\n q.txt\n Simple commentaries:\n";
	if (read.is_open()) {
		bool hardComment = false;
		while (read.getline(str, 100)) {
			bool quotes = false;
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == '/' && i != strlen(str) - 1 && str[i + 1] == '*' && !quotes) {
					hardComment = true;
				}
				if (str[i] == '*' && i != strlen(str) - 1 && str[i + 1] == '/' && !quotes) {
					hardComment = false;
				}
				if (str[i] == '"' && quotes && !hardComment) {
					quotes = false;
					i++;
				}
				if (str[i] == '"' && !quotes && !hardComment) {
					quotes = true;
				}
				if (str[i] == '/' && i != strlen(str) - 1 && str[i + 1] == '/' && !quotes && !hardComment) {
					for (i; i < strlen(str); i++)
						cout << str[i];
					cout << endl;
					break;
				}
			}
		}
		read.close();
	}
	else {
		cout << "Cant find your file\n";
	}
	return 0;
}