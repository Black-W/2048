#include <stdio.h>
#include <stdbool.h>
int main(void) {
	unsigned long num;          // number to be checked
	unsigned long div;          // potential divisors
	bool isPrime;               // prime flag

	// printf("Please enter an integer for analysis; ");
	//printf("Enter q to quit.\n");
	while (scanf("%lu", &num) == 1) {
		for (div = 2, isPrime = true; (div * div) <= num; div++) {
			if (num % div == 0) {
				printf("not prime\n");
				isPrime= false; // number is not prime
				break;
			}
		}
		if(num<=1) {
			printf("not prime\n");
		}
		if (num>1&&isPrime)
			printf("prime\n", num);
		// printf("Please enter another integer for analysis; ");
		//printf("Enter q to quit.\n");
	}
	//printf("Bye.\n");

	return 0;
}
