#include<stdio.h>

int main(void) {

    int m1, m2, d1, d2, y1, y2;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &m1, &d1, &y1);

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &m2, &d2, &y2);

    if (m1 > m2 && y1 > y2) {
        printf("%1d/%1d/%1d is earlier than %01d/%01d/%03d", m1, d1, y1, m2, d2, y2);
    } else if ()

    return 0;

}