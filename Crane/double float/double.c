#include<stdio.h>
#include<stdlib.h>

int main() {

	double a = 0;
	double multiplicator = 1;
	double m = 0;
	int number = 0;
	int e = 0;
	int helper = 0;

	printf("Enter a number \n");
	scanf_s("%lf", &a); // ������� //

	long long int aInt = *((long long int *) & a);
	
	// ����� � 0 �� 51 ��� 
	for (int i = 51; i >= 0; i--){

		number = ((aInt >> i) & 1);
	}

	// ����� � 52 �� 63 ��� 
	for (int i = 52; i < 63; i++){
		number = ((aInt >> i) & 1);
		if (number == 1){
			helper = 1;
			for (int j = 0; j < i - 52; j++){
				helper = helper * 2;
			}
			e = e + helper;
		}
	}

	//printf("%d", e);
	if (a < 0)
		printf("-");
	if (a > 0)
		printf("+");


	for (int i = 51; i >= 0; i--){

		number = ((aInt >> i) & 1);
		if (number == 1){
			multiplicator = 1.0;
			for (int j = 0; j > i - 52; j--){
				multiplicator = multiplicator / 2;

			}
		}
		m = m + number*multiplicator;
	}

	printf("%lf*", m + 1);
	printf("2(%d)", e - 1023);
	printf("\n");

	return 0;
}