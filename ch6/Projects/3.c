//Chapter 6 - Project 3
#include<stdio.h>

//Function Prototype(s)
int compute_gcd(int numerator, int denominator);

int main(void) {

    int numerator, denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    
    int gcd = compute_gcd(numerator, denominator);

    printf("In lowest terms: %d/%d\n", numerator / gcd, denominator / gcd);

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