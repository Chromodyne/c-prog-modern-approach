#include<stdio.h>


int main() {

	int dollars = 0;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollars);

	int numTwenties, numTens, numFives, numOnes;

	numTwenties = (dollars / 20);
	dollars -= numTwenties * 20;
	numTens = (dollars / 10);
	dollars -= numTens * 10;
	numFives = (dollars / 5);
	dollars -= numFives * 5;
	numOnes = (dollars / 1);
	dollars = 0;

	printf("The number of each bill is: %d Twenties, %d Tens, %d Fives, %d Ones\n", numTwenties, numTens, numFives, numOnes);
	
	return 0;

}
