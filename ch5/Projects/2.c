#include<stdio.h>


int main(void) {

	int numMins;
	int numHours;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d:%d", &numHours, &numMins);

	if (numHours > 12 && numHours < 24) {
		printf("The equivalent 12-hour time is: %d:%d PM\n", numHours - 12,  numMins);
	} else if (numHours < 12 && numHours >= 0) {
		printf("The equivalent 12-hour time is: %d:%d AM\n", numHours, numMins);
	} else if (numHours == 12) {
		printf("The equivalent 12-hour time is: %d:%d PM\n", numHours, numMins);
	}
 
	return 0;

}
