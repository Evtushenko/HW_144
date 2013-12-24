#include "calcTreeFunctions.h"

using functions::Tree;
using namespace std;

void functions::clearChar(char s [], int length) {
	for (int i = 0; i < length; i++) {
		s[i] = '\0';
	}
}

void functions::calc(Tree *&node) {
	int answer = 0;
	if (node->function != '\0' && node->left && node->right && node->left->function == '\0' && node->right->function == '\0') {
		switch (node->function) {
		case '+':
			answer += node->left->value + node->right->value;
			break;
		case '-':
			answer += node->left->value - node->right->value;
			break;
		case '*':
			answer += node->left->value * node->right->value;
			break;
		case '/':
			answer += node->left->value / node->right->value;
			break;
		}
		node->function = '\0';
		node->value = answer;
		delete node->left;
		delete node->right;
		node->left = nullptr;
		node->right = nullptr;
	}
}

void functions::printAbc(Tree *root) {
	if (!root) {
		return;
	}
	else {
		cout << "(";
	}
	if (root->function != '\0') {
		cout << root->function;
	}
	else {
		cout << root->value;
	}
	printAbc(root->left);
	printAbc(root->right);
	cout << ")";
	return;
}

void functions::calcHelp(Tree *root) {
	if (!root) {
		return;
	}
	calcHelp(root->left);
	calc(root);
	calcHelp(root->right);
}

Tree *functions::newTree(int value, char symbol) {
	Tree *newT = new Tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->previous = nullptr;
	newT->value = value;
	newT->function = symbol;
	return newT;
}

int functions::getInt(int &position, const char s []) {
	int answer = 0;
	char number[maxNumberLength];
	clearChar(number, maxNumberLength);
	int i = 0;
	while (s[position] != ')'){
		number[i] = s[position];
		position++;
		i++;
	}
	for (i = 0; i < strlen(number); i++) {
		answer += (number[i] - '0')*pow(10, strlen(number) - 1 - i);
	}
	position++;
	return answer;
}

bool functions::isFunction(char c) {
	return c == '+' || c == '*' || c == '-' || c == '/';
}

bool functions::isDigit(char c) {
	return c >= '0' && c <= '9';
}

void functions::addTree(const char s []) {
	static Tree *root = nullptr;
	static Tree *currentNode = nullptr;
	static int position = 0;
	(s[position] == '(' && position == 0) ? position++ : 0;
	static int first = 0;
	if (isFunction(s[position])) {
		if (first == 0) {
			root = newTree(0, s[position]);
			currentNode = root;
			first++;
			position++;
		}
		else {
			bool was = false;
			if (currentNode->left != nullptr && currentNode->right == nullptr && !was) {
				Tree *newT = newTree(0, s[position]);
				currentNode->right = newT;
				newT->previous = currentNode;
				currentNode = newT;
				was = true;
			}
			if (currentNode->left == nullptr && !was) {
				Tree *newT = newTree(0, s[position]);
				currentNode->left = newT;
				newT->previous = currentNode;
				currentNode = newT;
			}
			position++;
		}
	}
	if (s[position] == '(') {
		if (!isDigit(s[position + 1])) {
			position++;
		}
		else {
			position++;
			int val = getInt(position, s);
			if (currentNode->left != nullptr && currentNode->right == nullptr) {
				Tree *newT = newTree(val, '\0');
				currentNode->right = newT;
				newT->previous = currentNode;
			}
			if (currentNode->left == nullptr) {
				Tree *newT = newTree(val, '\0');
				currentNode->left = newT;
				newT->previous = currentNode;
			}
		}
	}

	if (s[position] == ')') {
		if (currentNode->previous) {
			currentNode = currentNode->previous;
		}
		position++;
	}

	if (position < strlen(s)) {
		addTree(s);
	}
	else {
		cout << "we read is so \n";
		printAbc(root);
		cout << endl << endl;
		while (root->left != nullptr && root->right != nullptr) {
			calcHelp(root);
		}
		cout << "aswer: \n" << root->value << endl;
		delete root;
	}
}