#include <stdio.h>
#include <stdlib.h>
#include "treeFunction.h"

#define exitProgramm 0 
#define add 1
#define del 2 
#define exist 3
#define showInc 4
#define showDec 5
#define showABC 6
#define showOrders 7
#define showWide 8

int main() {

	printf("Welcome!\n Enter the number of state \n");
	printf("0 = exit\n");
	printf("1 = add\n");
	printf("2 = delete\n");
	printf("3 = exists?\n");
	printf("4 = show increase\n");
	printf("5 = show decrease\n");
	printf("6 = show (a b c)\n");
	printf("7 = show orders\n");
	printf("8 = show Wide\n");

	tree *root = nullptr;
	int value = 0;
	int amount = 0;

	for (;;) {
		printf("Enter number of state\n");
		int  c= -1;
		scanf_s("%d", &c);

		if (!((c >= 0) && (c <= 8))) {
			printf("Wrong command!\n");
			return 0;
		}

		if (c == exitProgramm) {
			printf("L.A.Goodbay\n");
			break;
		}

		if (c == add) {
			printf("Enter the value\n");
			scanf_s("%d",&value);
			if (exists(root, value)) {
				printf("sorry we already have this one\n");
			}
			else {
				root = insert(root, value);
				amount++;
			}
		}

		if (c == del) {
			if (amount == 0) {
				printf("Empty tree!\n");
				break;
			}
			printf("Enter the value\n");
			scanf_s("%d",&value);
			if (!exists(root, value)) {
				printf("Not found\n");
			}
			else {
				while (exists(root, value)) {
					root = remove(root, value);
					amount--;
				}
			}
			if (amount == 0) {
				printf("I have deleted all \n");
			}
		}

		if (c == exist) {
			if (amount == 0) {
				printf("Empty tree!\n");
				break;
			}
			printf("Enter the value\n");
			scanf_s("%d",&value);
			if ((amount > 0) && (exists(root, value))) {
				printf("It is here\n");
			}
			else {
				printf("It is NOT here\n");
			}
		}

		if (c == showInc) {
			if (amount == 0) {
				printf("Tree is null\n");
				break;
			}
			else {
				printInc(root);
				printf("\n");
			}
		}

		if (c == showDec) {
			if (amount == 0) {
				printf("Tree is null\n");
				break;
			}
			else {
				printDec(root);
				printf("\n");
			}
		}

		if (c == showABC) {
			if (amount == 0) {
				printf("Tree is null\n");
				break;
			}
			else {
				printAbc(root);
				printf("\n");
			}
		}

		if (c == showOrders) {
			printf("inorder\n");
			inorder(root);
			printf("\n");
			printf("preorder\n");
			preorder(root);
			printf("\n");
			printf("postorder\n");
			postorder(root);
			printf("\n");
		}

		if (c == showWide) {
			wideOrder(root);
		}
	}
	root = freeMemory(root);
	return 0;
}