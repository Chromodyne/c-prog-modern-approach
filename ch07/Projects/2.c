#include<stdio.h>

int main(void) {

    
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    
    for (i = 0; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);

        //We want to pause after 24 iterations. If modulus 24 is true then we know we're ready to pause.
        if(i % 24 == 0) {
            printf("Press Enter to continue...");

            //Wait for enter to be pressed. Remember pressing enter gives us a linefeed.
            while (getchar() == '\n') {
                break;
            }

        }

    }

    return 0;

}