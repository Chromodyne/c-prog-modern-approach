#include<stdio.h>

int main(void) {

    //Integers are proven to be stored in a 32-bit signed type.
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    //Overflows at ~46340
    for (i = 0; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
    }

    return 0;

}