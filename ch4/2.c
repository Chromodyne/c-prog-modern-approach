#include<stdio.h>

int main() {

	int number;
	int firstDigit;
	int secondDigit;
	int thirdDigit;

	printf("Enter a three-digit number: ");
	scanf("%d", &number);

	firstDigit = number / 100;
	secondDigit = (number / 10) % 10;
	thirdDigit = number % 10;

	printf("The reversal is: %d%d%d\n", thirdDigit, secondDigit, firstDigit);

	return 0;

}
