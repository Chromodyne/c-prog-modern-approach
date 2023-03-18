//Chapter 11 - Project 1
#include<stdio.h>

//Function Prototype(s)
void pay_amount(int dollars, int * twenties, int * tens, int * fives, int * ones);

int main(void) {

	int dollars = 0;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollars);

	int twenties = 0, tens = 0, fives = 0, ones = 0;

	//Remember to use the address operator (&) for the necessary variables since the function expects a pointer for each.
	pay_amount(dollars, &twenties, &tens, &fives, &ones);

	printf("The number of each bill is: %d Twenties, %d Tens, %d Fives, %d Ones\n", twenties, tens, fives, ones);
	
	return 0;

}

void pay_amount(int dollars, int * twenties, int * tens, int * fives, int * ones) {

	//Always dereference your pointers using the indirection operator (*) to modify the actual value stored at the address.
	*twenties = (dollars / 20);
	dollars -= *twenties * 20;
	*tens = (dollars / 10);
	dollars -= *tens * 10;
	*fives = (dollars / 5);
	dollars -= *fives *  5;
	*ones = (dollars / 1);
	dollars = 0;

}