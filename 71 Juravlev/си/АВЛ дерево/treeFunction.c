#include <stdio.h>
#include <stdlib.h>
#include "treeFunction.h"

//using namespace std;
//using treeName::tree;

//Increase//
void printInc(tree *root) {
	if (!root)
		return;
	printInc(root->left);
	printf("%d ",root->value);
	printInc(root->right);
}

//Free//

tree* freeMemory(tree *root) {
	if (!root)
		return root;
	if (root->left == root->right)
	{
		free(root);
		return nullptr;
	}
	root->left = freeMemory(root->left);
	root->right = freeMemory(root->right);
	free(root);
	return nullptr;
}

void printDec(tree *root) {
	if (!root)
		return;
	printDec(root->right);
	printf("%d ", root->value);
	printDec(root->left);
}

// существует ли??
bool exists(tree *node, int key){
	if (node == nullptr)
		return 0;
	while (node) {
		if (node->value == key)
			return true;
		if (key > node->value)
			node = node->right;
		else
			node = node->left;
	}
	return false;
}

tree *printAbc(tree *root) {
	if (!root) {
		printf(" null");
		return root;
	}
	else
		printf("(%d",root->value);
	printAbc(root->left);
	printAbc(root->right);
	printf(")");
	return root;
}

char height(tree *node) {
	return node ? node->height : 0;
}

int balanceFactor(tree *node) {
	return height(node->right) - height(node->left);
}

void updateHeight(tree *node) {
	char heightLeft = height(node->left);
	char heightRight = height(node->right);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

tree *turnRight(tree *node) {
	tree* slot = node->left;
	node->left = slot->right;
	slot->right = node;
	updateHeight(node);
	updateHeight(slot);
	return slot;
}

tree *turnLeft(tree *node) {
	tree* slot = node->right;
	node->right = slot->left;
	slot->left = node;
	updateHeight(node);
	updateHeight(slot);
	return slot;
}

tree *balance(tree *node) {
	updateHeight(node);
	if (balanceFactor(node) == 2) {
		if (balanceFactor(node->right) < 0)
			node->right = turnRight(node->right);
		return turnLeft(node);
	}
	if (balanceFactor(node) == -2) {
		if (balanceFactor(node->left) > 0)
			node->left = turnLeft(node->left);
		return turnRight(node);
	}
	return node;
}

tree *insert(tree *node, int key)  {
	if (!node) {
		tree *newNode = (tree *) malloc(sizeof(tree));
		//return new tree(key);
		newNode->value = key; 
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->height = 1;
		return newNode;
	}
		
	if (key < node->value)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return balance(node);
}

tree *findMin(tree *node) {
	return node->left ? findMin(node->left) : node;
}

tree *removeMin(tree *node) {
	if (node->left == nullptr)
		return node->right;
	node->left = removeMin(node->left);
	return balance(node);
}

tree *remove(tree *node, int key) {
	if (!node)
		return 0;
	if (key < node->value)
		node->left = remove(node->left, key);
	else
		if (key > node->value)
			node->right = remove(node->right, key);
		else {
			tree* slot1 = node->left;
			tree* slot2 = node->right;
			free(node);
			if (!slot2)
				return slot1;
			tree* min = findMin(slot2);
			min->right = removeMin(slot2);
			min->left = slot1;
			return balance(min);
		}
		return balance(node);
}

void inorder(tree *root) {
	if (!root)
		return;
	inorder(root->left);
	if (root->value)
		printf("%d ", root->value);
	inorder(root->right);
}

void preorder(tree *root) {
	if (!root)
		return;
	if (root->value)
		printf("%d ", root->value);
	preorder(root->left);
	preorder(root->right);
}

void postorder(tree *root) {
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	if (root->value)
		printf("%d ", root->value);
}

void enqueue(tree **begin, tree **end, tree *&node) {
	if (*begin == nullptr) {
		node->next = nullptr;
		*begin = node;
		*end = node;
	}
	else {
		node->next = nullptr;
		(*end)->next = node;
		*end = node;
	}
}

void dequeue(tree **begin, tree **end) {
	if (*begin == *end) {
		*begin = nullptr;
		*end = nullptr;
	}
	else {
		*begin = (*begin)->next;
	}
}

void wideOrder(tree *root) {
	tree *beginQ = nullptr;
	tree *endQ = nullptr;
	enqueue(&beginQ, &endQ, root);
	while (beginQ != nullptr) {
		tree *x = beginQ;
		dequeue(&beginQ, &endQ);
		printf("%d ", x->value);
		if (x->left != nullptr) {
			enqueue(&beginQ, &endQ, x->left);
		}
		if (x->right != nullptr) {
			enqueue(&beginQ, &endQ, x->right);
		}
	}
}
