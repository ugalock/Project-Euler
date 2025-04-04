/*
A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers, {a1, a2, ... , ak} is called a product-sum number: N = a1 + a2 + ... + ak = a1 × a2 × ... × ak.

For example, 6 = 1 + 2 + 3 = 1 × 2 × 3.

For a given set of size, k, we shall call the smallest N with this property a minimal product-sum number. The minimal product-sum numbers for sets of size, k = 2, 3, 4, 5, and 6 are as follows.

k=2: 4  = 2 × 2 = 2 + 2
k=3: 6  = 1 × 2 × 3 = 1 + 2 + 3
k=4: 8  = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4
k=5: 8  = 1 × 1 × 2 × 2 × 2 = 1 + 1 + 2 + 2 + 2
k=6: 12 = 1 × 1 × 1 × 1 × 2 × 6 = 1 + 1 + 1 + 1 + 2 + 6
********************************************************
k=7: 12 = 1 x 1 x 1 x 1 x 1 x 3 x 4 = 1 + 1 + 1 + 1 + 1 + 3 + 4
k=8: 12 = 1 x 1 x 1 x 1 x 1 x 2 x 2 x 3 = 1 + 1 + 1 + 1 + 1 + 2 + 2 + 3
k=9: 15 = 1 x 1 x 1 x 1 x 1 x 1 x 1 x 3 x 5 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 3 + 5
k=10:16 = 1 x 1 x 1 x 1 x 1 x 1 x 1 x 1 x 4 x 4 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 4 + 4
k=11:16 = 1 x 1 x 1 x 1 x 1 x 1 x 1 x 1 x 2 x 2 x 4 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 2 + 2 + 4
k=12:16 = 1 x 1 x 1 x 1 x 1 x 1 x 1 x 1 x 2 x 2 x 2 x 2 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 2 + 2 + 2 + 2

Hence for 2≤k≤6, the sum of all the minimal product-sum numbers is 4+6+8+12 = 30; 
**note that 8 is only counted once in the sum**

In fact, as the complete set of minimal product-sum numbers for 2≤k≤12 is {4, 6, 8, 12, 15, 16}, the sum is 61.

What is the sum of all the minimal product-sum numbers for 2≤k≤12000?
Notes:
k(n) = a(1) x a(2) x ... x a(n) = a(1) + a(2) + ... a(n) where a(1) <= a(2) ... <= a(n)
n < k(n) <= 2 x a(n)
if n is even, k(n) is a multiple of 4
let m be the number of 1's E a(n) and p = n - m
*/ 

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "primesUnderMil.h"

static int cache[ 12001 ];
static int memo[ 13000 ];

void findFactors( int n, int factors[], int numFactors, int original ) {
	if ( n == 1 ) {
		int sum = 0;
		for ( int i = 0; i < numFactors; ++i ) {
			sum += factors[ i ];
		}
		int k = original - sum;
		if ( k + numFactors > 12000 ) {
			return;
		} else if ( cache[ k+numFactors ] == 0 || cache[ k+numFactors ] > original ) {
			cache[ k+numFactors ] = original;
			return;
		} 
	} else {
		for ( int i = 2; i <= n; ++i ) {
			if ( n % i == 0 ) {
				int newFactors[ numFactors+1 ];
				for ( int j = 0; j < numFactors; ++j ) {
					newFactors[ j ] = factors[ j ];
				}
				newFactors[ numFactors ] = i;
				int new = n / i;
				findFactors( new, newFactors, numFactors+1, original );
			}
		}
	}
	return;
}

int main() {
	int n, i, k, sum = 0;
	k = 0;
	for ( i = 2; i <= 12200; ++i ) {
		if ( i == primes[ k ] ) {
			++k;
			continue;
		} else {
			for ( int j = 2; j <= i/2; ++j ) {
				if ( i % j == 0 ) {
					int factors[ 2 ] = { j };
					n = i / j;
					findFactors( n, factors, 1, i );
				}
			}
		}
	}
	for ( i = 2; i < 12001; ++i ) {
		if ( !memo[ cache[ i ] ] ) {
			sum += cache[ i ];
			memo[ cache[ i ] ]++;
		}
	}
		
	printf("%d\n", sum);
	return 0;
}



