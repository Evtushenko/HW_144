#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// меняем элементы массива местами //
void change(size_t first, size_t second, size_t mas []){
	size_t tmp = mas[first];
	mas[first] = mas[second];
	mas[second] = tmp;
}
//Heapsort//
void HeapSort(size_t array [], size_t amount) {
	size_t shift = 0;
	bool useful = false;

	while (shift + 2 < amount) {
		useful = false;
		size_t i = 0;
		for (i = 0; i < amount; i++){
			if (i * 2 + 2 + shift < amount){
				if ((array[i + shift] > array[i * 2 + 1 + shift]) || (array[i + shift] > array[i * 2 + 2 + shift])){
					if (array[i * 2 + 1 + shift] < array[i * 2 + 2 + shift]){
						change(i + shift, i * 2 + 1 + shift, array);
						useful = true;
					}
					else if (array[i * 2 + 2 + shift] < array[i * 2 + 1 + shift]){
						change(i + shift, i * 2 + 2 + shift, array);
						useful = true;
					}
				}
			}
			else if (i * 2 + 1 + shift < amount){
				if (array[i + shift] > array[i * 2 + 1 + shift]){
					change(i + shift, i * 2 + 1 + shift, array);
					useful = true;
				}
			}
		}
		if (!useful) shift++;
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
	HeapSort(array, amount);
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
	char out1 [] = { "HR1.txt" };
	read(name1, amount, out1);

	char name2 [] = { "two.txt" };
	char out2 [] = { "HR2.txt" };
	read(name2, amount, out2);

	char name3 [] = { "three.txt" };
	char out3 [] = { "HR3.txt" };
	read(name3, amount, out3);

	return 0;
}