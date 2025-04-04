/*
The radical of n, rad(n), is the product of the distinct prime factors of n. For example, 504 = 2^3 × 3^2 × 7, so rad(504) = 2 × 3 × 7 = 42.

If we calculate rad(n) for 1 ≤ n ≤ 10, then sort them on rad(n), and sorting on n if the radical values are equal, we get:

Unsorted								Sorted
n 		rad(n)					n 		rad(n) 		k
1			1								1			1					1
2			2								2			2					2
3			3								4			2					3
4			2								8			2					4
5			5								3			3					5
6			6								9			3					6
7			7								5			5					7
8			2								6			6					8
9			3								7			7					9
10		10							10		10				10

Let E(k) be the kth element in the sorted n column; for example, E(4) = 8 and E(6) = 9.

If rad(n) is sorted for 1 ≤ n ≤ 100000, find E(10000).
*/

#include <stdio.h>
#include <stdlib.h>
#include "primesUnderMil.h"

struct rad {
	int r;
	int i;
};

static struct rad radicals[ 100001 ];

int comparator( const void *p, const void *q ) {
  struct rad l = *(const struct rad *)p;
  struct rad r = *(const struct rad *)q;
  return l.r - r.r;
}

int main() {
	for ( int i = 0; i < 100001; ++i ) {
		radicals[ i ].r = 1;
		radicals[ i ].i = i;
	}
	for ( int i = 0; primes[ i ] < 100000; ++i ) {
		int num = primes[ i ];
		while ( num < 100001 ) {
			radicals[ num ].r *= primes[ i ];
			num += primes[ i ];
		}
	}
	qsort( (void*)radicals, 100001, sizeof( struct rad ), comparator );
	printf("Result: %d\n", radicals[ 10000 ].i );
	return 0;
}