/*
Consider the consecutive primes p1 = 19 and p2 = 23. It can be verified that 1219 is the smallest number such that the last digits are formed by p1 whilst also being divisible by p2.

In fact, with the exception of p1 = 3 and p2 = 5, for every pair of consecutive primes, p2 > p1, there exist values of n for which the last digits are formed by p1 and n is divisible by p2. Let S be the smallest of these values of n.

Find ∑ S for every pair of consecutive primes with 5 ≤ p1 ≤ 1000000.

***Notes***
From wikipiedia: https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Computation

Given x == a1 ( mod n1 ) and x == a2 ( mod n2 ) for coprime n1,n2, Bezout's identity asserts the existence of two integers m1,m2 s.t. m1n1 + m2n2 = 1 where m1,m2 can be derived from the extended Euclidean algorithm. This implies that our desired solution x is given by x = a1m2n2 + a2m1n1

So from our example we have 19 == a1 ( mod 100 ) and 0 == a2 ( mod 23 )
so our solution is ( 19 x 23 x m2 ) % ( 100 * 23 ) since we want the smallest solution
*/

#include <stdio.h>
#include <stdint.h>
#include "primesUnderMil.h"

__uint128_t testPairs( int n, int m, int e ) {
	for ( int i = 1; ; ++i ) {
		__uint128_t num = i * e + n;
		if ( num % m == 0 ) return num; 
	}
}

int64_t extendedEuclid( int64_t a, int64_t b ) {
	int64_t s = 0, t = 1, r = b, old_s = 1, old_t = 0, old_r = a, q, temp;
	while ( r ) {
		q = old_r / r;
		temp = old_r;
		old_r = r;
		r = temp - q * r;
		temp = old_s;
		old_s = s;
		s = temp - q * s;
		temp = old_t;
		old_t = t;
		t = temp - q * t;
	}
	return old_t;
}

int print_int128(__int128_t n) {
  if (n == 0)  return printf("0\n");

  char str[40] = {0}; 
  char *s = str + sizeof(str) - 1;
  while ( n ) {
    *--s = "0123456789"[n % 10];
    n /= 10;                     
  }
  return printf("%s\n", s);
}

int main() {
	primes[ 78498 ] = 1000003;
	int64_t result = 0;
	int64_t e = 10;
	for ( int i = 2; i < 78498; ++i ) {
		if ( primes[ i ] > e ) e *= 10;
		
		int64_t a = ( primes[ i+1 ] - primes[ i ] ) * extendedEuclid( primes[ i+1 ], e ) % primes[ i+1 ];
		if ( a < 0 ) a += primes[ i+1 ];
		result += a < 0 ? (a + primes[ i+1 ]) * e + primes[ i ] : a * e + primes[ i ];
	}
	printf("Result: %ld\n", result);

	return 0;
}