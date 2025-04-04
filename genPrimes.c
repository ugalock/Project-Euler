#include <stdio.h>
#include <stdlib.h>

int power(long x, unsigned long y, long p) {
  long res = 1;      
  x = x % p;  
              
  while (y > 0) {
    if (y & 1)
        res = (res*x) % p;

    y = y>>1;
    x = (x*x) % p;
  }
  return res;
}

int miillerTest(long d, long n) {
    long a = 2 + rand() % (n - 4);
    long x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return 1;

    while (d != n-1) {
      x = (x * x) % n;
      d *= 2;

      if (x == 1)      return 0;
      if (x == n-1)    return 1;
    }
    return 0;
}

int isPrime(long n, int k) {
  if (n <= 1 || n == 4)  return 0;
  if (n <= 3) return 1;

  long d = n - 1;
  while (d % 2 == 0)
      d /= 2;

  for (int i = 0; i < k; i++)
       if (miillerTest(d, n) == 0)
            return 0;

  return 1;
}

int main() {
	int k = 10;
	printf("static int primes[404204977] = { 1000000007");
	for ( long i = 1000000009; i < 9999999967; i += 2 ) {
		if ( isPrime( i, k ) ) printf(",%ld", i);
		if ( !( i % 1000001 ) ) fprintf(stderr, "%ld\n", i / 1000001);
	}
	printf(",9999999967 };\n");
}

