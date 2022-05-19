#include<stdio.h>

int main(void) {

    int len = 0;

    printf("Enter a message: ");

    while ((getchar()) != '\n') {
        len++;
    }

    printf("The number of characters entered was: %d\n", len);

    return 0;
    
}