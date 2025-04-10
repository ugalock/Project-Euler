/*
In a triangular array of positive and negative integers, we wish to find a sub-triangle such that the sum of the numbers it contains is the smallest possible.

In the example below, it can be easily verified that the marked triangle satisfies this condition having a sum of −42.

We wish to make such a triangular array with one thousand rows, so we generate 500500 pseudo-random numbers sk in the range ±219, using a type of random number generator (known as a Linear Congruential Generator) as follows:

t := 0
for k = 1 up to k = 500500:
    t := (615949*t + 797807) modulo 220
    sk := t−219

Thus: s1 = 273519, s2 = −153582, s3 = 450905 etc

Our triangular array is then formed using the pseudo-random numbers thus:
s1
s2  s3
s4  s5  s6 
s7  s8  s9  s10
...

Sub-triangles can start at any element of the array and extend down as far as we like (taking-in the two elements directly below it from the next row, the three elements directly below from the row after that, and so on).
The "sum of a sub-triangle" is defined as the sum of all the elements it contains.
Find the smallest possible sub-triangle sum.
*/

#include <stdio.h>
#include <stdint.h>

int main() {
	static int64_t triangle[ 1000 ][ 1000 ];
	static int64_t sums[ 1001 ][ 1001 ], t = 0;
	int64_t result = 0;
	for ( int i = 0; i < 1000; ++i ) {
		for ( int j = 0; j <= i; ++j ) {
			t = ( 615949*t + 797807 ) % 1048576;
			triangle[ i ][ j ] = t - 524288;
			sums[ i ][ j+1 ] = sums[ i ][ j ] + triangle[ i ][ j ];
		}
	}
	for ( int i = 0; i < 1000; ++i ) {
		for ( int j = 0; j <= i; ++j ) {
			long curr = 0; 
			for ( int k = i; k <= 1000; ++k ) {
				curr += sums[ k ][ k+j+1-i ] - sums[ k ][ j ];
				result = result > curr ? curr : result;
			}
		}
	}
	printf("%ld\n", result);	
}