#include<stdio.h>

#define STR_LEN 100

int main(void) {

    //Setup a character array to hold the message.
    char message[STR_LEN];

    //Used to keep track of the current character.
    char current_char;
    int i = 0;

    printf("Enter a message: ");

    //Get input using a getchar() loop that terminates when it reaches a newline escape
    //sequence.
    while ((current_char = getchar()) != '\n') {
        
        //We use < instead of <= to keep at least one element for the null terminator.
        if(i < STR_LEN) {
            message[i++] = current_char;
        }
    }

    //Null terminate the string stored in message from the previous loop.
    message[i] = '\0';

    printf("Reversal is: ");

    //Start at the end of the character string excluding the null terminator and work
    //backwards printing out each character in the array.
    for (i = i - 1; i >= 0; i--) {
        putchar(message[i]);
    }

    return 0;

}