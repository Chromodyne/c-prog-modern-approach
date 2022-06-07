#include<stdio.h>

int fact(int n) {

    int total = n;

    if (n > 0) {

        for (n; n - 1 > 0; n--) {
                total *= n - 1;
        }

    } else {
            total = 1;
    }

     return total;

}

int main(void) {

    int number;
    int a;

    printf("Enter a number: ");
    scanf("%d", &number);

    a = fact(number);

    printf("%2d", a);

    return 0;

}