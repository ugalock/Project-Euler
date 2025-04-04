/*
By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:

Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
*/
#include <stdio.h>
#include <stdlib.h>

#define TARGET 2000000


int main() {
	int64_t smallest, closest, bestH, bestW, bestArea, count;
	int i, j;
	i = 3000;
	j = 1;
	smallest = 2000000;
	while ( i > j ) {
		count = i * j * ( i+1 ) * ( j+1 ) / 4;	
		if ( abs( count - TARGET ) < smallest ) {
			smallest = abs( count - TARGET );
			closest = count;
			bestH = i;
			bestW = j;
			bestArea = i * j;
		}
		if ( count > TARGET ) --i;
		else
			++j;
	}
	printf("closest count: %ld (off by %ld) is achieved by a %ld x %ld rect that forms an area of %ld\n", closest, smallest, bestH, bestW, bestArea);
	return 0;
}