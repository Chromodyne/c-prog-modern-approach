#include<stdio.h>
#include<ctype.h>

int main(void) {

    char ch;
    int numVowels = 0;

    printf("Please enter some text: ");

    while ((ch = getchar()) != '\n') {

        switch (toupper(ch)) {

            case 'A': case 'E': case 'I': case 'O': case 'U':

                numVowels++;
                break;

            default:

                break;

        }

    }

    printf("Your text contains %d vowels.\n", numVowels);

    return 0;

}