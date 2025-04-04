/*
It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?
*/
#include <stdio.h>
#include <string.h>
#include "primesUnderMil.h"

int main() {
	int i, j, k, result;
	static int combos[ 100000 ];
	result = 0;
	for ( i = 1; i < 1000000; ++i ) {
		int temp = 0;
		while ( primes[ temp ] <= i ) ++temp;
		combos[ 0 ] = 1;
		for ( j = 0; j <= temp; ++j ) {
			k = primes[ j ];
			while ( k <= i ) {
				combos[ k ] += combos[ k - primes[ j ] ];
				++k;
			}
			if ( combos[ i ] >= 5000 ) {
				result = i;
			}
		}
		memset( combos, 0, sizeof(int)*100000 );
		if ( result ) {
			printf("Result: %d\n", result);
			break;
		}
	}
	return 0;
}