/*
The radical of n, rad(n), is the product of distinct prime factors of n. For example, 504 = 23 × 32 × 7, so rad(504) = 2 × 3 × 7 = 42.

We shall define the triplet of positive integers (a, b, c) to be an abc-hit if:

    GCD(a, b) = GCD(a, c) = GCD(b, c) = 1
    a < b
    a + b = c
    rad(abc) < c

For example, (5, 27, 32) is an abc-hit, because:

    GCD(5, 27) = GCD(5, 32) = GCD(27, 32) = 1
    5 < 27
    5 + 27 = 32
    rad(4320) = 30 < 32

It turns out that abc-hits are quite rare and there are only thirty-one abc-hits for c < 1000, with ∑c = 12523.

Find ∑c for c < 120000.

***Notes***
It's essential to note that GCD(a,b) and a + b = c implies that GCD(a,c) == GCD(b,c) == 1
Because of this relationship it's also apparent that rad(abc) == rad(a)*rad(b)*rad(c)
*/

#include <stdio.h>
#include <stdint.h>
#include "primesUnderMil.h"

uint64_t gcd(uint64_t u, uint64_t v) {
  int shift;
  if ( u == 0 ) return v;
  if ( v == 0 ) return u;
  shift = __builtin_ctzl(u | v);
  u >>= __builtin_ctzl(u);
  do {
    v >>= __builtin_ctzl(v);
    if ( u > v ) {
      uint64_t t = v;
      v = u;
      u = t;
    }  
    v = v - u;
  } while ( v != 0 );
  return u << shift;
}

int main() {
	uint64_t result = 0;
	static uint64_t rad[ 120001 ] = { [ 0 ... 120000 ] = 1 };
	for ( int i = 0; primes[ i ] < 120000; ++i ) {
		for ( int n = primes[ i ]; n < 120000; n += primes[ i ] ) {
			rad[ n ] *= primes[ i ];
		}
	}
	
	for ( uint64_t a = 1; a < 120000; ++a ) {
		for ( uint64_t b = a + 1; b < 120000-a ; ++b ) {
			uint64_t c = a + b;
			if ( rad[ a ] * rad[ b ] * rad[ c ] < c ) {
				if ( gcd( a, b ) == 1 ) result += c; 
			}
		}
	}
	printf("Result: %lu\n", result);
	return 0;
}