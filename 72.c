/*
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 21 elements in this set.

How many elements would be contained in the set of reduced proper fractions for 
d ≤ 1,000,000?
*/
#include <stdio.h>

unsigned gcd(unsigned u, unsigned v)
{
  int shift;
  if ( u == 0 ) return v;
  if ( v == 0 ) return u;
  shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    v >>= __builtin_ctz(v);
    if ( u > v ) {
      unsigned t = v;
      v = u;
      u = t;
    }  
    v = v - u;
  } while ( v != 0 );
  return u << shift;
}

int totient(int n) {
  float result = n;

  for (int p = 2; p * p <= n; ++p) {
       
    if (n % p == 0) {
         
        while (n % p == 0)
            n /= p;
        result *= (1.0 - (1.0 / (float)p));
    }
  }

  if (n > 1)
    result *= (1.0 - (1.0 / (float)n));

  return (int)result;
}

int main() {
	printf("Starting...\n");
	int d;
	long long count = 0;
	for ( d = 2; d < 1000001; ++d ) {
		count += totient( d );
		if ( !( d % 10000 ) ) printf("%d\n%lld\n", d, count);
	}
	printf("Count: %lld\n", count);
	return 0;
}