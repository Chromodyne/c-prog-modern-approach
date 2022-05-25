#include<stdio.h>

int main() {

	int number;

	printf("Please enter a number between 0 and 32767: ");
	scanf("%d", &number);

	printf("In octal, your number is: %5o\n", number); 

	return 0;

}
