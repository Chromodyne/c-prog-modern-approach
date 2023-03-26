#include<stdio.h>

//Define our symbolic constant (macro) here. Remember how calculating array size works.
#define aSize (int) (sizeof(a) / sizeof(a[0]))
#define N 10

int main(void) {

    int a[N], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < aSize; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order: ");
    for (i = aSize - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;

}