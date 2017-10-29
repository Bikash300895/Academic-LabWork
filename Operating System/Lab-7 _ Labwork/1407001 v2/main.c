#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

int *primeNumber;


int main (int arg, char *argv[])
{

	int a;
	printf("Enter a number : ");

	scanf("%d",&a);
	
	//primeNumber = (int*) malloc(a * sizeof(int));
	struct data d = prime(a);

	int i;
	for(i=0; i<=a; i++){
		if(d.primes[i]==0){
			printf("%d is not prime \n", i);
		}
		else {
			printf("%d is prime \n", i);
		}
		
	}

	printf("The sum of the prime numbers is %d\n", d.total);
}
