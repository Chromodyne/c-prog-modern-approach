#include<stdio.h>

int main(void) {

    int userNumber;
    int digitOne, digitTwo, digitThree;

    //Print the prompt and then store the value entered into userNumber.
    printf("Please enter a three-digit number: ");
    scanf("%d", &userNumber);

    //Could have done this in the printf below for less lines of code but written like this for clarity.
    digitOne = userNumber / 100;         //The first digit is the number divided by 10.
    digitTwo = (userNumber / 10) % 10;   //Divide the number by 10 then take the remainder of the same operation for digit 2.      
    digitThree = userNumber % 10;        //The third digit is the remainder when divided by 10.

    //Print in reverse order.
    printf("The reversal is: %d%d%d\n", digitThree, digitTwo, digitOne);

    return 0;
    
}