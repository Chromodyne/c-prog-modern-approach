#include<stdio.h>

//Use a symbolic constant in case we decide to change the number of elements in the array later.
#define N 10

int main(void) {

    int numsEntered[N];

    printf("Enter 10 numbers: ");
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &numsEntered[i]);
    }

    printf("In reverse order: ");

    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", numsEntered[i]);
    }

    printf("\n");

    return 0;

}