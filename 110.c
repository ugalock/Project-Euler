/*
In the following equation x, y, and n are positive integers.

1 / x + 1 / y = 1 / n

It can be verified that when n = 1260 there are 113 distinct solutions and this is the least value of n for which the total number of distinct solutions exceeds one hundred.

What is the least value of n for which the number of distinct solutions exceeds four million?

NOTE: This problem is a much more difficult version of Problem 108 and as it is well beyond the limitations of a brute force approach it requires a clever implementation.

*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

static int primes[ 14 ] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 };

int comparator( const void *p, const void *q ) {
  int l = *(const int *)p;
  int r = *(const int *)q;
  return l - r;
}

int main() {
	static int exponents[ 14 ];
	int i, limit = 8000000;
	__uint128_t result = 1;
	__uint128_t best = (__uint128_t)1e18;
	for ( int j = 0; j < 5; ++j ) {
		exponents[ 13 ] = j;
		for ( int k = j; k < 5; ++k ) {
			exponents[ 12 ] = k;
			for ( int l = k; l < 5; ++l ) {
				exponents[ 11 ] = l;
				for ( int m = l; m < 5; ++m ) {
					exponents[ 10 ] = m;
					for ( int n = m; n < 5; ++n ) {
						exponents[ 9 ] = n;
						for ( int o = n; o < 5; ++o ) {
							exponents[ 8 ] = o;
							for ( int p = o; p < 5; ++p ) {
								exponents[ 7 ] = p;
								for ( int q = p; q < 5; ++q ) {
									exponents[ 6 ] = q;
									for ( int r = q; r < 5; ++r ) {
										exponents[ 5 ] = r;
										for ( int s = r; s < 5; ++s ) {
											exponents[ 4 ] = s;
											for ( int t = s; t < 5; ++t ) {
												exponents[ 3 ] = t;
												for ( int u = t; u < 5; ++u ) {
													exponents[ 2 ] = u;
													for ( int v = u; v < 5; ++v ) {
														exponents[ 1 ] = v;
														for ( int w = v; w < 5; ++w ) {
															exponents[ 0 ] = w;
															__uint128_t check = 1;
															for ( i = 0; i < 14; ++i ) {
																check *= ( 2 * exponents[ i ] + 1 );
															}
															if ( check >= limit ) {
																result = 1;
																for ( i = 0; i < 14; ++i ) {
																	result *= (__uint128_t)pow( primes[ i ], exponents[ i ] );
																}
																best = result < best ? result : best;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Results: %lu\n", (uint64_t)best);
	return 0;
}