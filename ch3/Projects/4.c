//Project 3.04 - Phone Number Modifier
//User enters number in format: (xxx) xxx-xxxx
//Program outputs number in format: xxx.xxx.xxxx

#include<stdio.h>

int main(void) {

    int areaCode, prefix, lastFour;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &areaCode, &prefix, &lastFour);

    printf("%d.%d.%d", areaCode, prefix, lastFour);

    return 0;

}