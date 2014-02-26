#include <stdio.h>
#include <stdlib.h>

int main() {

	float flHelper = 1.0;
	float mHelper = 0.0;
	short sign =  0;
	int helper = 0;
	int e = 0;
	int binaryExp = 0;
	int i = 0;
	int j = 0;
	union { int numberInt; float number; };
	scanf_s("%f", &number);

	if (number < 0) sign = 1;
	else sign = 0;
	

	for (i = 23; i < 31; i ++){
		helper = ((numberInt >> i) & 1);
		if (helper == 1){
			binaryExp = 1;
			for (j = 0; j < i - 23; j ++){
				binaryExp = binaryExp * 2;

			}
			e = e + binaryExp;
		}

	}
	
	printf("(-1)^%d*", sign);

	for (i = 22; i > 0; i--){

		helper = ((numberInt >> i) & 1);
		if (helper == 1){
			flHelper = 1.0;
			for (j = 0; j > i - 23; j--){
				flHelper = flHelper / 2;

			}
		}
		mHelper = mHelper + helper*flHelper;
	}

	printf("%lf*", mHelper + 1);
	printf("e%d", e - 127,"\n");

	return 0;
}