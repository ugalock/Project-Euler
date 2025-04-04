/*
Let S(A) represent the sum of elements in set A of size n. We shall call it a special sum set if for any two non-empty disjoint subsets, B and C, the following properties are true:

    S(B) ≠ S(C); that is, sums of subsets cannot be equal.
    If B contains more elements than C then S(B) > S(C).

If S(A) is minimised for a given n, we shall call it an optimum special sum set. The first five optimum special sum sets are given below.

n = 1: {1}
n = 2: {1, 2}
n = 3: {2, 3, 4}
n = 4: {3, 5, 6, 7}
n = 5: {6, 9, 11, 12, 13}

It seems that for a given optimum set, A = {a1, a2, ... , an}, the next optimum set is of the form B = {b, a1+b, a2+b, ... ,an+b}, where b is the "middle" element on the previous row.

By applying this "rule" we would expect the optimum set for n = 6 to be A = {11, 17, 20, 22, 23, 24}, with S(A) = 117. However, this is not the optimum set, as we have merely applied an algorithm to provide a near optimum set. The optimum set for n = 6 is A = {11, 18, 19, 20, 22, 25}, with S(A) = 115 and corresponding set string: 111819202225.

Given that A is an optimum special sum set for n = 7, find its set string.

NOTE: This problem is related to Problem 105 and Problem 106.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

static inline uint64_t pop64(uint64_t y) {
	y -= ((y >> 1) & 0x5555555555555555ull);
	y = (y & 0x3333333333333333ull) + (y >> 2 & 0x3333333333333333ull);
	return ((y + (y >> 4)) & 0xf0f0f0f0f0f0f0full) * 0x101010101010101ull >> 56;
}

int testPartition( int nums[ 7 ], unsigned partition, int sum ) {
	int bCount = pop64( partition );
	int aMax = 7 - bCount;
	int aIndex = 0;
	int a[ 6 ];
	int aCount, bSum = 0, aSum = 0;
	// printf("%u %d\n", partition, bCount);
	for ( int i = 0; i < 7; ++i ) {
		if ( partition & ( 1 << (unsigned)i ) ) {
			bSum += nums[ i ];
			// printf("%d ", nums[ i ]);
		} else {
			a[ aIndex ] = nums[ i ];
			++aIndex;
		}
	}
	for ( unsigned i = 1; i < pow( 2, aMax ); ++i ) {
		aCount = pop64( i );
		aSum = 0;
		for ( int j = 0; j < aMax; ++j ) {
			if ( i & ( 1 << (unsigned)j ) ) aSum += a[ j ];
		}
		if ( aSum == bSum ) return 0;
		else if ( aCount < bCount && aSum > bSum ) return 0;
		else if ( aCount > bCount && aSum < bSum ) return 0;
	}
	return 1;
}

int main() {
	int nums[ 7 ], sum = 0;
	for ( int i = 20; i < 40; ++i ) {
		nums[ 0 ] = i;
		for ( int j = i+1; j < 50; ++j ) {
			nums[ 1 ] = j;
			for ( int k = j+1; k < 50; ++k ) {
				nums[ 2 ] = k;
				for ( int l = k+1; l < 50; ++l ) {
					nums[ 3 ] = l;
					for ( int m = l+1; m < 50; ++m ) {
						nums[ 4 ] = m;
						for ( int n = m+1; n < 50; ++n ) {
							nums[ 5 ] = n;
							for ( int o = n+1; o < 50; ++o ) {
								nums[ 6 ] = o;
								sum = i+j+k+l+m+n+o;
								for ( unsigned p = 1; p < 64; ++p ) {
									int check = testPartition( nums, p, sum );
									if ( !check ) break;
									else if ( check && p == 63 ) {
										for ( int a = 0; a < 7; ++a ) printf("%d", nums[ a ]);
										printf("\n");
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0; 
}