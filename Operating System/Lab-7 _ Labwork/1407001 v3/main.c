#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"




int main (int arg, char *argv[])
{
	int *primeNumber;
	int a;
	printf("Enter a number : ");

	scanf("%d",&a);
	
	//primeNumber = (int*) malloc(a * sizeof(int));;
	primeNumber = prime(a);

	int i;
	for(i=0; i<=a; i++){
		if(primeNumber[i]==0){
			printf("%d is not prime \n", i);
		}
		else {
			printf("%d is prime \n", i);
		}
		
	}
	int sum = 0;
	for(i=0; i<=a; i++){
		if(primeNumber[i]==1){
			sum+=i;
		}
	}

	printf("The sum of the prime numbers is %d\n", sum);
}
