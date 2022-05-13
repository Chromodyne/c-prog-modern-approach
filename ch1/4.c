#include<stdio.h>

#define TAX_RATE 0.05f

int main() {

	float money;

	printf("Please enter dollars and cents: ");
	scanf("%f", &money);

	printf("%.2f\n", (money * TAX_RATE) + money);

	return 0;

}
