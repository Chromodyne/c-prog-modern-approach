//Chapter 6 - Project 3
#include<stdio.h>

//Function Prototype(s)
void reduce(int numerator, int denominator, int * reduced_numerator, int * reduced_denominator);

int main(void) {

    int numerator, denominator, reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    
    reduce

    printf("In lowest terms: %d/%d\n",);

    return 0;

}

//This function computes the GCD for two numbers using the euclidean algorithm. Not optimized.
int compute_gcd(int numerator, int denominator) {

    int current = 0;

    while(denominator != 0) {
        current = numerator % denominator;
        numerator = denominator;
        denominator = current;
    }

    return numerator;

}
 
void reduce(int numerator, int denominator, int * reduced_numerator, int * reduced_denominator) {

    int current = 0;

    while(denominator != 0) {
        current = numerator % denominator;
        numerator = denominator;
        denominator = current;
    }

    *reduced_numerator = numerator;
    *

}