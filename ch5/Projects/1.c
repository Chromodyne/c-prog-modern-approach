#include<stdio.h>

int main() {

	int number;
	int numDigits;

	printf("Enter a number: ");
	scanf("%d", &number);

	if (number > 0 && number <= 9) {
		numDigits = 1;
	} else if (number >= 10 && number < 100) {
		numDigits = 2;
	} else if (number >= 100 && number < 1000) {
		numDigits = 3;
	} else if (number >= 1000 && number < 10000) {
		numDigits = 4;
	}
	printf("The number %d has %d digits.\n", number, numDigits); 

	return 0;

}
