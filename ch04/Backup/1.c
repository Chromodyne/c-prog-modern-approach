#include<stdio.h>

int main() {

	int number;
	int firstDigit;
	int secondDigit;

	printf("Enter a two-digit number: ");
	scanf("%d", &number);

	firstDigit = number / 10;
	secondDigit = number % 10;

	printf("The reversal is: %d%d\n", secondDigit, firstDigit);

	return 0;

}
