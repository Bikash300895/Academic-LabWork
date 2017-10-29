#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include "functions.h"

int isPrime(int n) {
  if (n < 2) return 0;
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}


int prime(int n)
{
	extern int *primeNumber;
	//int primeNumber[n];
	int i;

	for (i=0; i<=n; i++){
		primeNumber[i] = isPrime(i);
	}

	

	int sum = 0;
	for(i=0; i<=n; i++){
		if(primeNumber[i]==1){
			sum+=i;
		}
	}

	return sum;
}
