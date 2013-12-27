#include "KruskalFunction.h"

using kruskal::Roads;
using kruskal::Points;
using namespace std;

void kruskal::addEnd(Points **beginP, Points **endP, int value) {
	Points *newP = new Points;
	newP->Point[0] = value;
	for (int i = 1; i < maxAmountVertex; i++) {
		newP->Point[i] = -1;
	}
	newP->next = nullptr;

	if (*beginP == nullptr) {
		*beginP = newP;
		*endP = newP;
	}
	else {
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
	(*begin) = (*begin)->next;
	delete help;
}

// ƒобавить в список по пор€дку не в конец //
void kruskal::addSort(Roads **beginNode, Roads **endNode, int from, int to, int distance) {
	Roads *end = *endNode;
	Roads *newNode = new Roads;
	newNode->from = from;
	newNode->to = to;
	newNode->distance = distance;
	Roads * currentNode = *beginNode;

	// если элемент меньше первого, то он будет новым первым//
	if (distance < currentNode->distance) {
		newNode->next = currentNode;
		*beginNode = newNode;
		if (currentNode == *endNode) {
			*endNode = currentNode;
		}
	}
	else {
		// ≈сли новый больше первого //
		bool found = false; // результат поиска фолс //
		while (currentNode->next) {
			if ((currentNode->next)->distance > newNode->distance) {
				found = true;
				break;
			}
			// currentNode - предыдущий , а currentNode->next больше чем newNode //
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

// склеить строки
void kruskal::sum(Points *&first, Points *&second) {
	int i = 0; // номер свободного слота в первой //
	for (i; i < maxAmountVertex; i++) {
		if (first->Point[i] == -1) {
			break;
		}
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

void kruskal::memoryFree(Points *&beginP, Roads **beginR) {
	Points *helperP = nullptr;
	while (beginP) {
		helperP = beginP;
		beginP = beginP->next;
		delete helperP;
	}

	while (*beginR) {
		pop(&*beginR);
	}


}

void kruskal::buildRoads(Roads **begin, Roads **end, int matrix [][maxAmountVertex], int amountPoints) {
	bool firstExist = false;
	// create increase Roads
	for (int i = 0; i < amountPoints; i++) {
		for (int j = i + 1; j < amountPoints; j++) {
			if (matrix[i][j] != 0) {
				if (!firstExist) {
					addFirst(&*begin, &*end, i, j, matrix[i][j]);
					firstExist = true;
				}
				else {
					addSort(&*begin, &*end, i, j, matrix[i][j]);
				}
			}
		}
	}
	Roads *slot = *begin;
	// show roads
	while (slot) {
		cout << "Road: from " << slot->from << " to " << slot->to << " distance " << slot->distance << endl;
		slot = slot->next;
	}
}

void kruskal::printLogic(Points **beginP, int amountPoints, Roads **top){

	Points *first = nullptr;
	Points *second = nullptr;

	while (amountPoints != 1) {
		first = find(*beginP, (*top)->from);
		second = find(*beginP, (*top)->to);
		char a = 0;
		if (first != second) {
			cout << "sum ";
			for (int i = 0; i < maxAmountVertex; i++) {
				if (first->Point[i] != -1) {
					a = 'A' + first->Point[i];
					cout << a << " ";
				}
				else {
					break;
				}
			}
			cout << " with ";
			for (int i = 0; i < maxAmountVertex; i++) {
				if (second->Point[i] != -1) {
					a = 'A' + second->Point[i];
					cout << a << " ";
				}
				else {
					break;
				}
			}
			cout << endl;
			sum(first, second);
			amountPoints--;
		}
		pop(&*top);
	}
}