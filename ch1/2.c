#include<stdio.h>

#define FOUR_THIRDS (4.0f / 3.0f)
#define PI 3.1416f


int main() {

	int radius = 10;
	
	printf("%f", FOUR_THIRDS * PI * (radius * radius * radius)); 

	return 0;

}
