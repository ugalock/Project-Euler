/*
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.

Let us consider repunits of the form R(10n).

Although R(10), R(100), or R(1000) are not divisible by 17, R(10000) is divisible by 17. Yet there is no value of n for which R(10n) will divide by 19. In fact, it is remarkable that 11, 17, 41, and 73 are the only four primes below one-hundred that can be a factor of R(10n).

Find the sum of all the primes below one-hundred thousand that will never be a factor of R(10n).

***Notes***
My first impulse without a lot of thought was that since every R(n) for r > 2 can be decomposed into some form of R(k) x some binary string of the form 
{ 101, 1001, 10101, 10001, ... } for k < n, so my thought was to just test the largest 128 bit R(n) with my powmod function thinking I was going to have to bite the bullet and use GMP, but it worked! There's a much more thorough reasoning on the problem thread as to how to solve this analytically that I won't go through, I'll just take my luck and move on.  
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
	__uint128_t exp = 100000000000000000;
	for ( int i = 0; primes[ i ] < 100000; ++i ) {
		if ( power( 10, exp, (__uint128_t)primes[ i ] * 9 ) != 1 ) result += primes[ i ];
	}
	printf("Result: %lu\n", result);
}