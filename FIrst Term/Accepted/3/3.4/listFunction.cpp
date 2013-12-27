#include <iostream>
#include "listFunction.h"

using namespace std;

using list::Node;
// ������� ������ �������� //
Node* list::first(int number) {
	Node *newNode = new Node;
	newNode->valueNode = number;
	newNode->next = nullptr;
	return newNode;
}

// �������� � ������ �� ������� �� � ����� //
void list::addSort(Node **beginNode, Node **endNode, int number){
	Node *end = *endNode;
	Node *newNode = new Node;
	newNode->valueNode = number;
	Node * currentNode = *beginNode;

	// ���� ������� ������ �������, �� �� ����� ����� ������//
	if (number < currentNode->valueNode) {
		newNode->next = currentNode;
		*beginNode = newNode;
		if (currentNode == *endNode) {
			*endNode = currentNode;
		}
	}
	else {
		// ���� ����� ������ ������� //
		bool found = false; // ��������� ������ ���� //
		while (currentNode->next) {
			if ((currentNode->next)->valueNode > newNode->valueNode) {
				found = true;
				break;
			}
			// currentNode - ���������� , � currentNode->next ������ ��� newNode //
			currentNode = currentNode->next;
		}
		if (found) {
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			if (currentNode->next == end) {
				*endNode = currentNode->next;
			}
		}
	}
	if ((*endNode)->valueNode <= number) {
		newNode->valueNode = number;
		newNode->next = nullptr;
		(*endNode)->next = newNode;
		*endNode = newNode;
	}
}

// ����� �������� �� ����� //
Node* list::find(Node * const beginNode, int number) {
	Node *helpNode = beginNode;
	while (helpNode) {
		if (helpNode->valueNode == number)
			break;
		helpNode = helpNode->next;
	}
	return helpNode;
}

// ���������� �� �������?? //
bool list::exist(Node *beginNode, int key) {
	bool right = false;
	Node *helpNode = beginNode;
	while (helpNode) {
		if (helpNode->valueNode == key) {
			right = true;
		}
		helpNode = helpNode->next;
	}
	return right;
}

// �������� //
void list::del(Node **beginNode, Node **endNode, int key) {
	Node *pkey = find(*beginNode, key);
	Node *start = *beginNode;

	// ������� ������ //
	if (start == pkey) {
		*beginNode = start->next;
		delete start;
	}
	else {
		bool found = false;
		while (start->next) {
			if (start->next == pkey) {
				found = true;
				break;
			}
			start = start->next;
		}
		// start - ���������� ��� ���������� start->next ��������� //
		if (found) {
			start->next = (pkey)->next;
			delete pkey;
		}
	}
}