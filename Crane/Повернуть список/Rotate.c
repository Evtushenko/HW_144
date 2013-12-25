#include <stdlib.h>
#include <stdio.h>

#define amount 5

struct List {
	List *next;
	int value;
};

void add(List **begin, List **end, int value) {
	if (*begin == nullptr) {
		List *newNode = (List *) malloc(sizeof(List));
		newNode->next = nullptr;
		newNode->value = value;
		*begin = newNode;
		*end = newNode;
	}
	else {
		List *newNode = (List *) malloc(sizeof(List));
		newNode->next = nullptr;
		newNode->value = value;
		(*end)->next = newNode;
		*end = newNode;
	}
}

void print(List *&begin) {
	List *slot = begin;
	while (slot) {
		printf("%d ", slot->value);
		slot = slot->next;
	}
	printf("\n");
}

void del(List *&begin) {
	List *slot = begin;
	while (begin) {
		slot = begin;
		begin = begin->next;
		free(slot);
	}
}

int main() {
	List *begin = nullptr;
	List *end = nullptr;
	for (int i = 0; i < amount; i++) {
		add(&begin, &end, i + 1);
	}
	print(begin);
	List *current = begin->next;
	List *res = current->next;
	begin->next = nullptr;

	while (res->next){
		current->next = begin;
		begin = current;
		current = res;
		res = current->next;
	}
	current->next = begin;
	res->next = current;
	print(res);
	del(begin);
	return 0;
}