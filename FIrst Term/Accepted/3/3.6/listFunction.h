#pragma once

namespace list{
	// �������� ��������� //
	struct Node {
		int value;
		Node *next;
	};
	Node* first(int number);
	void add(Node **endNode, int number);
	void sortInsert(Node *beginNode, int amount);
}