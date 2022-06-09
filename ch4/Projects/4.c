//Chapter 4 - Project 4
//Write a program that converts a user's input integer into octal.

#include<stdio.h>

int main(void) {

    int userInput = 0;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &userInput);

    printf("In octal, your number is: %o\n", userInput);

    return 0;

}