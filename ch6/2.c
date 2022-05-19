#include<stdio.h>


int main(void) {

	int m, n;
	int check;

	printf("Enter two numbers: ");
	scanf("%d %d", &m, &n);

	while (n != 0) {

		n = m % n;	

	}

	printf("Greatest Common Divsor: %d", n);

	return 0;

}
