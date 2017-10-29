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


struct data prime(int n)
{
	//extern int *primeNumber;
	//int primeNumber[n];

	struct data d;
	d.total = 0;
	d.primes = (int*) malloc(n * sizeof(int));

	int i;

	for (i=0; i<=n; i++){
		d.primes[i] = isPrime(i);
	}

	

	int sum = 0;
	for(i=0; i<=n; i++){
		if(d.primes[i]==1){
			d.total+=i;
		}
	}

	return d;
}
