//Exercise 3 - ISBN Number Breakdown
#include<stdio.h>

int main(void) {

    int gs1Prefix, groupIdentifer, pubCode, itemNumber, checkDigit;

    printf("Enter ISBN13: ");
    scanf("%d-%d-%d-%d-%d", &gs1Prefix, &groupIdentifer, &pubCode, &itemNumber, &checkDigit);

    printf("GS1 Prefix: %d\n", gs1Prefix);
    printf("Group Identifier: %d\n", groupIdentifer);
    printf("Publisher Code: %d\n", pubCode);
    printf("Item Number: %d\n", itemNumber);
    printf("Check Digit: %d", checkDigit);

    return 0;

}