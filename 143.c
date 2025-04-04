/*
https://projecteuler.net/problem=143 a bit complicated to explain without 
the diagram

***Notes***
The real key insight comes from the wiki on Fermat-Torricelli points,
which reveals that the inside angles formed by the lines p,q,r are guaranteed
to meet at 120 degree angles, so using the law of cosines we can note that
c^2 = p^2 + q^2 + pq
b^2 = p^2 + r^2 + pr
a^2 = q^q + r^2 + qr
There are lots of interesting optimizations that exist on the problem thread,
but I couldn't realize any of them on my own so this is the brute force code 
I came up with which, unfortunately is terribly slow at ~25 seconds. 
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t isPerfectSquare( uint64_t n ) {
	int temp = n % 10; 
	if ( temp == 2 || temp == 3 || temp == 7 || temp == 8 ) return 0;
	double s = sqrt(n);

	if ((uint64_t)s * (uint64_t)s == n) return (uint64_t) s;
	return 0;
}

int main() {
	static int cache[ 120001 ];
	uint64_t a2, b2, c2, result = 0;
	for ( uint64_t p = 100; p < 120000; ++p) {
		for ( uint64_t q = 100; q < p && p+q < 120000; ++q) {
			c2 = p*p + q*q + p*q;
			if ( !isPerfectSquare( c2 ) ) continue;
			for ( uint64_t r = 100; r < q && p+q+r < 120000; ++r) {
				if ( cache[ p+q+r ] ) continue;
				a2 = q*q + r*r + q*r;
				b2 = p*p + r*r + p*r;
				if ( isPerfectSquare( a2 ) && isPerfectSquare( b2 ) ) {
					result += p + q + r;
					cache[ p+q+r ] = 1;
					// int n = (p + q + r) * 2;
					// while ( n  < 120000 && !cache[ n ] ) {
					// 	cache[ n ] = 1;
					// 	result += n;
					// 	n += p + q + r;
					// }
				}
			}
		}
	}
	printf("Result: %lu\n", result);
}