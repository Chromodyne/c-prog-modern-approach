#include<stdio.h>

int main(void) {

	float current = 1.0f;
	float largest = 0.0f;

	while (current != 0) {

		printf("Enter a number: ");
		scanf("%f", &current);
		
		if (current > largest) {
			largest = current;
		}

		if (current == 0) {
			continue;
		}

	}

	printf("The largest number entered was: %.2f\n", largest);

	return 0;

}
