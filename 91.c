/*
The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.

There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; that is,
0 ≤ x1, y1, x2, y2 ≤ 2.

Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_X
#define MAX_X 50
#endif
#ifndef MAX_Y
#define MAX_Y 50
#endif

int comparator(const void *p, const void *q) {
  int l = *(const int *)p;
  int r = *(const int *)q;
  return l - r;
}

int main() {
	int count = 0;
	int sides[ 3 ] = { 0 };
	int origin[ 2 ] = { 0 };
	int x1y1[ 2 ] = { 0 };
	int x2y2[ 2 ] = { 0 };
	for ( int x1 = 0; x1 <= MAX_X; ++x1 ) {
		x1y1[ 0 ] = x1;
		for ( int x2 = 0; x2 <= MAX_X; ++x2 ) {
			x2y2[ 0 ] = x2;
			for ( int y1 = 0; y1 <= MAX_Y; ++y1 ) {
				x1y1[ 1 ] = y1;
				for ( int y2 = 0; y2 <= MAX_Y; ++y2 ) {
					x2y2[ 1 ] = y2;
					if ( ( x1y1[ 0 ] == 0 && x2y2[ 0 ] == 0 ) || ( x1y1[ 1 ] == 0 && x2y2[ 1 ] == 0 ) ) continue;
					sides[ 0 ] = x1y1[ 0 ] * x1y1[ 0 ] + x1y1[ 1 ] * x1y1[ 1 ];
					sides[ 1 ] = x2y2[ 0 ] * x2y2[ 0 ] + x2y2[ 1 ] * x2y2[ 1 ];
					sides[ 2 ] = abs( x2y2[ 0 ] - x1y1[ 0 ] ) * abs( x2y2[ 0 ] - x1y1[ 0 ] ) + abs( x2y2[ 1 ] - x1y1[ 1 ] ) * abs( x2y2[ 1 ] - x1y1[ 1 ] );
					qsort( (void*)sides, 3, sizeof(int), comparator );
					if ( sides[ 0 ] + sides[ 1 ] == sides[ 2 ] && sides[ 0 ] ) ++count;
				}
			}
		}
	}
	printf("Result: %d\n", count/2);
}