/*
In the following equation x, y, and n are positive integers.

1 / x + 1 / y = 1 / n

For n = 4 there are exactly three distinct solutions:
1 / 5 + 1 / 20 = 1 / 4
1 / 6 + 1 / 12 = 1 / 4
1 / 8 + 1 / 8 = 1 / 4

What is the least value of n for which the number of distinct solutions exceeds one-thousand?

NOTE: This problem is an easier version of Problem 110; it is strongly advised that you solve this one first.
*/

#include <stdio.h>
#include "primesUnderMil.h"

int main() {
	for ( int n = 65536; ; ++n ) {
		int i, f, num = n, result = 1;
		for ( i = 0; i < 78499; ++i ) {
			if ( num == 1 ) {
				if ( result >= 2000 ) {
					printf("Result: %d\n", n);
					return 0;
				} else {
					break;
				}
			}
			f = 0;
			while ( num % primes[ i ] == 0 ) {
				++f;
				num /= primes[ i ];
			}
			result *= ( 2 * f + 1 );
		}
	}
}