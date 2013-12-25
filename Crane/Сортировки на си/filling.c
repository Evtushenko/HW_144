#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	FILE *one, *two, *three;

	long int const n = 250000;
	long int i = 0;
	/*
	fopen_s(&one, "c:/tmp/one.txt", "w");

	for (i = 0; i < n; i++) {
		fprintf(one, "%d", i);
		fprintf(one," ");
	}
	fclose(one);
	*/

	/*
	fopen_s(&two, "c:/tmp/two.txt", "w");

	for (i = 0; i < n; i++) {
		fprintf(two, "%d", 249999-i);
		fprintf(two, " ");
	}
	fclose(two);
	*/

	/*
	fopen_s(&three, "c:/tmp/three.txt", "w");

	for (i = 0; i < n; i++) {
		fprintf(three, "%d", rand() % 1000 + 1);
		fprintf(three, " ");
	}
	fclose(three);
	*/
	return 0;
}