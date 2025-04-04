/*
Let pn be the nth prime: 2, 3, 5, 7, 11, ..., and let r be the remainder when 
(pn−1)^n + (pn+1)^n is divided by pn^2.

For example, when n = 3, p^3 = 5, and 4^3 + 6^3 = 280 ≡ 5 mod 25.

The least value of n for which the remainder first exceeds 109 is 7037.

Find the least value of n for which the remainder first exceeds 10^10.
***Notes***
Same analysis as Problem 120, for all odd n check if 2 * pn * n > 10^10
*/

#include <stdio.h>
#include <stdint.h>
#include "primesUnderMil.h"

int main() {
	uint64_t limit = 5000000000;
	for ( int i = 7036; primes[ i ] != 0; i += 2 ) {
		if ( (uint64_t)primes[ i ] * ( i + 1 ) > limit ) {
			printf("Result: %d\n", i+1 );
			return 0;
		}
	}
}