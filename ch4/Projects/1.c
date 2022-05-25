#include<stdio.h>

int main(void) {

    int userNumber;
    int digitOne, digitTwo;

    //Print the prompt and then store the value entered into userNumber
    printf("Please enter a two-digit number: ");
    scanf("%d", &userNumber);

    //Could have done this in the printf below for less lines of code but written like this for clarity.
    digitOne = userNumber / 10;         //The first digit is the number divided by 10.
    digitTwo = userNumber % 10;         //The second number is the remainder when divided by 10.

    //Print in reverse order.
    printf("The reversal is: %d%d\n", digitTwo, digitOne);

    return 0;

}