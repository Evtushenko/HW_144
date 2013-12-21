#include "KruskalFunction.h"

using kruskal::Roads;
using kruskal::Points;

void kruskal::addEnd(Points **beginP, Points **endP, int value) {
	if (*beginP == nullptr) {
		Points *newP = new Points;
		newP->Point[0] = value;
		for (int i = 1; i < maxAmountVertex; i++)
			newP->Point[i] = -1;
		newP->next = nullptr;
		*beginP = newP;
		*endP = newP;
	}
	else {
		Points *newP = new Points;
		newP->Point[0] = value;
		for (int i = 1; i < maxAmountVertex; i++)
			newP->Point[i] = -1;
		newP->next = nullptr;
		(*endP)->next = newP;
		*endP = newP;
	}
}

Points *kruskal::find(Points *&begin, int value) {
	Points *help = begin;
	while (help) {
		for (int i = 0; i < maxAmountVertex; i++) {
			if (help->Point[i] == -1){
				break;
			}
			if (help->Point[i] == value) {
				return help;
			}
		}
		help = help->next;
	}
	return help;
}

void kruskal::addFirst(Roads **begin, Roads **end, int from, int to, int distance) {
	Roads *newR = new Roads;
	newR->from = from;
	newR->to = to;
	newR->distance = distance;
	newR->next = nullptr;
	*begin = newR;
	*end = newR;
}

void kruskal::pop(Roads **begin) {
	Roads *help = *begin;
	if ((*begin)->next)
		(*begin) = (*begin)->next;
	delete help;
}

// �������� � ������ �� ������� �� � ����� //
void kruskal::addSort(Roads **beginNode, Roads **endNode, int from, int to, int distance) {
	Roads *end = *endNode;
	Roads *newNode = new Roads;
	newNode->from = from;
	newNode->to = to;
	newNode->distance = distance;
	Roads * currentNode = *beginNode;

	// ���� ������� ������ �������, �� �� ����� ����� ������//
	if (distance < currentNode->distance) {
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
			if ((currentNode->next)->distance > newNode->distance) {
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
	if ((*endNode)->distance <= distance) {
		newNode->distance = distance;
		newNode->next = nullptr;
		(*endNode)->next = newNode;
		*endNode = newNode;
	}
}

// �������� //
void kruskal::del(Points **beginNode, Points **endNode, Points *&pkey) {
	Points *start = *beginNode;

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

// ������� ������
void kruskal::sum(Points *&first, Points *&second) {
	int i = 0; // ����� ���������� ����� � ������ //
	for (i; i < maxAmountVertex; i++) {
		if (first->Point[i] == -1)
			break;
	}

	int j = 0;
	while (second->Point[j] != -1) {
		if (second->Point[j] != -1) {
			first->Point[i] = second->Point[j];
			i++;
		}
		j++;
	}
}