/*
A row measuring seven units in length has red blocks with a minimum length of three units placed on it, such that any two red blocks (which are allowed to be different lengths) are separated by at least one black square. There are exactly seventeen ways of doing this.

How many ways can a row measuring fifty units in length be filled?

***Notes***
n = #blocks
n 					f( n )
0						1
1						1
2						1
3						2
4						4
5						7
6						11
7						17
8						27
9						44
10					72

so for f( n ) = f( n-4 ) - f( n-2 ) + 2*f( n-1 ) as given by:
https://oeis.org/A005252
*/

#include <stdio.h>
#include <stdint.h>

int main() {
	static uint64_t cache[ 51 ] = { 1, 1, 1, 2 };
	for ( int i = 4; i <= 50; ++i ) {
		cache[ i ] = cache[ i-4 ] - cache[ i-2 ] + 2 * cache[ i-1 ];
	}

	printf("Result: %lu\n", cache[ 50 ] );
	return 0;
}