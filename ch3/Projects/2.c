#include<stdio.h>

int main(void) {

    //Initializing these to zero just for safety.
    int itemNumber = 0;
    float unitPrice = 0.0f;

    int month, day, year = 0;

    //Get our input from the user on values.
    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    printf("Enter unit price: ");
    scanf("%f", &unitPrice);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);

    printf("Item\tUnit\t Purchase\n");
    printf("\tPrice\t Date\n");
    printf("%d\t%.2f\t%2d/%2d/%4d", itemNumber, unitPrice, month, day, year);

    return 0;

}