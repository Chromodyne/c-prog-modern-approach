#include<stdio.h>

int main() {
	
	int month;
	int day;
	int year;

	printf("Please enter a date (mm/dd/yyyy): ");
	scanf("%d /%d /%d", &month, &day, &year);
	printf("The date is: %.4d%.2d%.2d", year, month, day);

	return 0;

}
