/*
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k.

For example, R(10) = 1111111111 = 11×41×271×9091, and the sum of these prime factors is 9414.

Find the sum of the first forty prime factors of R(109).
*/

#include <stdio.h>
#include <stdint.h>
#include "primesUnderMil.h"

__uint128_t power( __uint128_t x, __uint128_t y, __uint128_t p ) {
  __uint128_t res = 1;      
  x %= p;         
  while ( y > 0 ) {
    if ( y & 1 ) res = ( res * x ) % p;
    y >>= 1;
    x = ( x * x ) % p;
  }
  return res;
}

int main() {
	uint64_t result = 0;
	__uint128_t exp = 1000000000;
	int count = 0;
	for ( int i = 0; i < 78948; ++i ) {
		if ( power( 10, exp, (__uint128_t)primes[ i ] * 9 ) == 1 ) {
			++count;
			result += primes[ i ];
		}
		if ( count == 40 ) {
			printf("Result: %lu\n", result);
			return 0;
		}
	}
}