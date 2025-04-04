/* 
It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?
*/
#include <stdio.h>

int main() {
	int i;
	long j;
	static int combos[ 101 ];
	combos[ 0 ] = 1;
	for ( i = 1; i <= 100; ++i ) {
		j = i;
		while ( j <= 100 ) {
			combos[ j ] += combos[ j - i ];
			++j;
		}
	}
	printf("Number of combos: %d\n", combos[ 100 ]-1 );
	return 0;
}