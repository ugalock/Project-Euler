/*
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?
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

int main() {
	int d, n, count = 0;
	for ( d = 3; d < 12001; ++d ) {
		for ( n = d/3; n * 2 < d; ++n ) {
			if ( gcd( n, d ) == 1 && 3 * n > d ) { 
				++count;
			}
		}
	}
	printf("Count: %d\n", count);
	return 0;
}