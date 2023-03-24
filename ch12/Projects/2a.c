#include<stdio.h>

#define STR_LEN 100

int main(void) {

    char message[STR_LEN];
    char reversed[STR_LEN];
    char current_char;
    int i = 0, j = 0;

    printf("Enter a message: ");

    while ((current_char = getchar()) != '\n') {
        
        //We use < instead of <= to keep at least one element for the null terminator.
        if(i < STR_LEN) {
            message[i++] = current_char;
        }
    }
    
    i = 0;

    for (j = i - 1; i < STR_LEN; i++) {

        if (message[i] != message[j]) {
            printf("Not a palindrome...");
            return 0;
        }
    
        j--;

    }
    printf("Palindrome!");

    return 0;

}