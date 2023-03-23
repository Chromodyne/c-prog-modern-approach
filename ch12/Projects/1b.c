#include<stdio.h>

#define STR_LEN 100

int main(void) {

    //Setup a character array to hold the message.
    char message[STR_LEN];

    //Used to keep track of the current character.
    char current_char;

    //Create a pointer to the message array.
    char * p = message;

    printf("Enter a message: ");

    while ((current_char = getchar()) != '\n' && p < message + STR_LEN) {
        *p++ = current_char;
    }

    printf("Reversal is: ");

    for (p = p - 1; p >= message; p--) {
        putchar(*p);
    }

    return 0;

}