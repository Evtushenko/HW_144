#pragma once

	struct tree{
		int value;
		char height;
		tree *left;
		tree *right;
		tree *next;
		//tree(int number) { value = number; left = right = nullptr; height = 1; }
	};

	void printInc(tree *root);
	void printDec(tree *root);
	bool exists(tree *r, int key);
	tree *printAbc(tree *root);
	tree *freeMemory(tree *root);
	char height(tree *node);
	int balanceFactor(tree *node);
	void updateHeight(tree* node);
	tree *turnRight(tree *node);
	tree *turnLeft(tree *node);
	tree *balance(tree* node);
	tree *insert(tree *node, int key);
	tree *findMin(tree *node);
	tree *removeMin(tree *node);
	tree *remove(tree *node, int key);
	void inorder(tree *root);
	void preorder(tree *root);
	void postorder(tree *root);
	void enqueue(tree **begin, tree **end, tree *&node);
	void dequeue(tree **begin, tree **end);
	void wideOrder(tree *root);