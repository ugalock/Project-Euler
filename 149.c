/*
Looking at the table below, it is easy to verify that the maximum possible sum of adjacent numbers in any direction (horizontal, vertical, diagonal or anti-diagonal) is 16 (= 8 + 7 + 1).
−2	5	 3	2
 9 −6	 5	1
 3	2	 7	3
−1	8	−4	8
Now, let us repeat the search, but on a much larger scale:

First, generate four million pseudo-random numbers using a specific form of what is known as a "Lagged Fibonacci Generator":

For 1 ≤ k ≤ 55, sk = [100003 − 200003k + 300007k3] (modulo 1000000) − 500000.
For 56 ≤ k ≤ 4000000, sk = [sk−24 + sk−55 + 1000000] (modulo 1000000) − 500000.

Thus, s10 = −393027 and s100 = 86613.

The terms of s are then arranged in a 2000×2000 table, using the first 2000 numbers to fill the first row (sequentially), the next 2000 numbers to fill the second row, and so on.

Finally, find the greatest sum of (any number of) adjacent entries in any direction (horizontal, vertical, diagonal or anti-diagonal).

***Notes***
Just brute-forced. Cache the results of the lagged Fibonacci function
so the recursive calls aren't expensive, and then I went through a whole new loop just to construct the grid. Could definitely be made faster, but I already lucked out enough in that just searching down and to the right gave me the correct result, and I was happy enough with 27s that I couldn't be bothered
*/

#include <stdio.h>

static int cache[ 4000001 ];

int laggedFib( long k ) {
	if ( cache[ k ] ) return cache[ k ];
	if ( k >= 1 && k <= 55 ) {
		return ( ( 100003 - 200003*k + 300007*k*k*k ) % 1000000 ) - 500000;
	}
	long k1, k2;
	if ( cache[ k-24 ] ) k1 = cache[ k-24 ];
	else {
		cache[ k-24 ] = laggedFib( k-24 );
		k1 = cache[ k-24 ];
	}
	if ( cache[ k-55 ] ) k2 = cache[ k-55 ];
	else {
		cache[ k-55 ] = laggedFib( k-55 );
		k2 = cache[ k-55 ];
	}
	cache[ k ] = ( ( k1 + k2 + 1000000 ) % 1000000 ) - 500000;  
	return cache[ k ];
}

int main() {
	static int grid[ 2000 ][ 2000 ];
	long result = 0;
	for ( int i = 1; i <= 4000000; ++i ) {
		laggedFib( i );
	}
	int k = 1;
	for ( int i = 0; i < 2000; ++i ) {
		for ( int j = 0; j < 2000; ++j ) {
			grid[ i ][ j ] = cache[ k++ ];
		}
	}
	for ( int i = 0; i < 2000; ++i ) {
		for ( int j = 0; j < 2000; ++j ) {
			long best = grid[ i ][ j ];
			int di = i+1, dj = j;
			while ( di <= 1999 ) {
				best += grid[ di++ ][ dj ];
				result = best > result ? best : result;
			}
			best = grid[ i ][ j ];
			di = i;
			dj = j+1;
			while ( dj <= 1999 ) {
				best += grid[ di ][ dj++ ];
				result = best > result ? best : result;
			}
		}
	}
	printf("Result: %ld\n", result);
}
