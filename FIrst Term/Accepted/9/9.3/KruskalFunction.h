#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

namespace kruskal {

	int const maxAmountVertex = 10;
	int const maxBufferSize = 100;

	struct Roads {
		int from;
		int to;
		int distance;
		Roads *next;
	};

	struct Points {
		int Point[maxAmountVertex];
		Points *next;
	};

	void addEnd(Points **beginP, Points **endP, int value);
	Points *find(Points *&begin, int value);
	void addFirst(Roads **begin, Roads **end, int from, int to, int distance);
	void pop(Roads **begin);
	void addSort(Roads **beginNode, Roads **endNode, int from, int to, int distance);
	void sum(Points *&first, Points *&second);
	void memoryFree(Points *&beginP, Roads **beginR);
	void buildRoads(Roads **begin, Roads **end, int matrix [][maxAmountVertex], int amountPoints);
	void printLogic(Points **beginP, int amountPoints, Roads **top);
}