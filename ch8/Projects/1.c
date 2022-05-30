#include<stdbool.h>
#include<stdio.h>

int main(void) {

    bool digit_seen[10] = {false};
    bool repeated_digits[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            repeated_digits[digit] = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digit.\n");
    printf("The repeated digits were: ");

    //Using array length calculation to give us a bit of future proofing. Can always make this a symbolic constant later.
    for (int i = 0; i < (sizeof(digit_seen) / sizeof(digit_seen[0])); i++) {
        if (repeated_digits[i]) {
                printf("%d ", i);
        }
    }
 
    return 0;

}