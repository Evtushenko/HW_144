#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// меняем элементы массива местами //
void change(long int first, long int second, long int mas []){
	int tmp = mas[first];
	mas[first] = mas[second];
	mas[second] = tmp;
}
void Quicksort(int begin, long int end, long int s []){
	long int middle = s[(begin + end) / 2];
	long int i = begin;
	long int j = end;
	while (i < j)
	{
		while (s[i] < middle)
			++i;
		while (s[j] > middle)
			--j;
		if (i <= j)
		{
			if (i < j)
				change(i, j, s);
			++i;
			--j;
		}
	}
	if (i < end)
		Quicksort(i, end, s);
	if (j > begin)
		Quicksort(begin, j, s);
}
void read(char name [], long int amount, char out []) {
	FILE *file;
	printf("%s", name);
	if (fopen_s(&file, name, "r")){
		printf("\nCant find ", "%s", name, "file\n");
	}
	long int array[250000];
	fopen_s(&file, name, "r");
	for (int i = 0; i < amount; i++) {
		fscanf_s(file, "%d", &array[i]);
	}
	fclose(file);
	// Программа сортировки//
	double start = clock(); //Начало отсчета
	Quicksort(0, amount - 1, array);
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

int main(){
	printf("Enter the amount of elements");
	printf("\n");
	long int amount = 0;
	scanf_s("%d", &amount);



	char name1 [] = { "one.txt" };
	char out1 [] = { "QR1.txt" };
	read(name1, amount, out1);

	char name2 [] = { "two.txt" };
	char out2 [] = { "QR2.txt" };
	read(name2, amount, out2);

	char name3 [] = { "three.txt" };
	char out3 [] = { "QR3.txt" };
	read(name3, amount, out3);


	return 0;
}