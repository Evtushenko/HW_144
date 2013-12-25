#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Choose(size_t amount, size_t array []) {
	size_t min = 250000;
	size_t i = 0;
	size_t j = 0;
	size_t tmp = 0;
	for (i = 0; i < amount - 1; i++) {
		min = 250000;
		for (j = i; j < amount; j++) {
			if (array[j] < min) {
				min = array[j];
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void read(char name [], size_t amount, char out []) {
	FILE *file;
	printf("%s", name);
	if (fopen_s(&file, name, "r")){
		printf("\nCant find ", "%s", name, "file\n");
	}
	size_t array[250000];
	fopen_s(&file, name, "r");
	for (int i = 0; i < amount; i++) {
		fscanf_s(file, "%d", &array[i]);
	}
	fclose(file);
	// Программа сортировки//
	double start = clock(); //Начало отсчета
	Choose(amount, array);
	double timework = (clock() - start) / CLOCKS_PER_SEC; // Остановка отсчета времени
	// вывод времени
	printf("\n");
	printf("%.4lf", timework);
	printf("\n");
	// вывод в файл//
	file = nullptr;

	fopen_s(&file, out, "w");
	for (int i = 0; i < amount; i++) {
		fprintf(file, "%d", array[i]);
		fprintf(file, " ");
	}
	fclose(file);
}

int main() {
	printf("Enter the amount of elements");
	printf("\n");
	size_t amount = 0;
	scanf_s("%d", &amount);

	char name1 [] = { "one.txt" };
	char out1 [] = { "CR1.txt" };
	read(name1, amount, out1);

	char name2 [] = { "two.txt" };
	char out2 [] = { "CR2.txt" };
	read(name2, amount, out2);

	char name3 [] = { "three.txt" };
	char out3 [] = { "CR3.txt" };
	read(name3, amount, out3);

	return 0;
}