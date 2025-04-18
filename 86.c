/*
A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is shown on the diagram.

However, there are up to three "shortest" path candidates for any given cuboid and the shortest route doesn't always have integer length.

It can be shown that there are exactly 2060 distinct cuboids, ignoring rotations, with integer dimensions, up to a maximum size of M by M by M, for which the shortest route has integer length when M = 100. This is the least value of M for which the number of solutions first exceeds two thousand; the number of solutions when M = 99 is 1975.

Find the least value of M such that the number of solutions first exceeds one million.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int l, l2, w, w2, h, square, mod, count = 2060;
	double root;
	for ( l = 101; l < 10000; ++l ) {
		l2 = l * l;
		for ( w = 1; w <= l; ++w ) {
			w2 = w * w;
			for ( h = 1; h <= w; ++h ) {
				square = l2 + w2 + h * h + 2 * h * w;
				mod = square % 10;
				mod *= mod;
				if ( mod == 4 || mod == 9 ) continue;
				root = sqrt( square );
				if ( root == (int)root ) ++count;
			}
		}
		if ( count >= 1000000 ) {
			printf("M = %d\n", l);
			break;
		} 
	}

	printf("Count: %d", count);
	return 0;
}