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


int * prime(int n)
{

	//static int primeNumber[100];
	static int* primeNumber;
	primeNumber = (int*) malloc(n * sizeof(int));
	int i;

	for (i=0; i<=n; i++){
		primeNumber[i] = isPrime(i);
	}

	return primeNumber;
}
