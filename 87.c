/*
The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
*/
#include <stdio.h>
#include <math.h>
#include "primesUnderMil.h"

#define LIMIT 50000000
static short cache[ LIMIT ];

int main() {
	int i, j, i4, j3, k, k2, sum, count = 0; 
	for ( i = 0; i < 5000; ++i ) {
		i4 = primes[ i ];
		i4 *= i4 * i4 * i4;
		if ( i4 > LIMIT ) break;
		for ( j = 0; j < 5000; ++j ) {
			j3 = primes[ j ];
			j3 *= j3 * j3;
			if ( j3 > LIMIT ) break;
			for ( k = 0; k < 5000; ++k ) {
				k2 = primes[ k ];
				k2 *= k2;
				if ( k2 > LIMIT ) break;
				sum = i4 + j3 + k2; 
				if ( sum > LIMIT ) break;
				if ( !cache[ sum ] ) ++count; 
				cache[ sum ]++;
			}
		}
	}
	printf("Count: %d\n", count);
	return 0;
}