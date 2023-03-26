#include<stdbool.h>
#include<stdio.h>

int main(void) {

    bool digit_seen[10] = {false};
    int repeated_digits[10][3] = {{0}, {0}};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            repeated_digits[digit][0] = true;
            repeated_digits[digit][1]++;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("The repeated digits were: ");


    for (int i = 0; i < (sizeof(digit_seen) / sizeof(digit_seen[0])); i++) {
        if (repeated_digits[i][0]) {
                printf("%d ", i);
        }
    }

    printf("\nThe number of occurences were: ");
    printf("%d ", repeated_digits[0][0]);
    
    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {
            
            if (repeated_digits[i]) {
                //printf("%d ", repeated_digits[i][j]);
            } 
            
        }

    }

    //Todo: Use a multidimensional array to store boolean with an int for number of occurences.
    //We should use a nested for loop to iterate the multi-dimensional array.
 
    return 0;

}