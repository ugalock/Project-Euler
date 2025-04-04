/*
Each of the six faces on a cube has a different digit (0 to 9) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.

For example, the square number 64 could be formed:

In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.

For example, one way this can be achieved is by placing {0, 5, 6, 7, 8, 9} on one cube and {1, 2, 3, 4, 8, 9} on the other cube.

However, for this problem we shall allow the 6 or 9 to be turned upside-down so that an arrangement like {0, 5, 6, 7, 8, 9} and {1, 2, 3, 4, 6, 7} allows for all nine square numbers to be displayed; otherwise it would be impossible to obtain 09.

In determining a distinct arrangement we are interested in the digits on each cube, not the order.

{1, 2, 3, 4, 5, 6} is equivalent to {3, 6, 4, 1, 2, 5}
{1, 2, 3, 4, 5, 6} is distinct from {1, 2, 3, 4, 5, 9}

But because we are allowing 6 and 9 to be reversed, the two distinct sets in the last example both represent the extended set {1, 2, 3, 4, 5, 6, 9} for the purpose of forming 2-digit numbers.

How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* nums = "0123456789";
static int contains9[ 22050 ];

int main() {
	char (*combos)[ 7 ] = NULL;
	combos = malloc( 22050 * sizeof *combos );
	int has6, has9, i, j, k, l, m, n, idx = 0, count = 0; 
	for ( i = 0; i < 5; ++i ) {
		for ( j = i+1; j < 6; ++j ) {
			for ( k = j+1; k < 7; ++k ) {
				for ( l = k+1; l < 8; ++l ) {
					for ( m = l+1; m < 9; ++m ) {
						for ( n = m+1; n < 10; ++n ) {
							char temp[ 7 ];
							has6 = 0;
							has9 = 0;
							temp[ 0 ] = nums[ i ];
							temp[ 1 ] = nums[ j ];
							temp[ 2 ] = nums[ k ];
							temp[ 3 ] = nums[ l ];
							temp[ 4 ] = nums[ m ];
							temp[ 5 ] = nums[ n ];
							temp[ 6 ] = 0;
							for ( int p = 0; p < 6; ++p ) {
								if ( temp[ p ] == 9 ) {
									has9 = 1;
									break;
								}
							}
							if ( has9 ) {
								contains9[ idx ] = 1;
							}
							strcpy( combos[ idx ], &temp[ 0 ] );
							++idx;
						}
					}
				}
			}
		}
	}
	for ( i = 0; i < 22050; ++i ) {
		for ( j = i; j < 22050; ++j ) {
			char* combo1 = combos[ i ];
			char* combo2 = combos[ j ];
			if ( combo1[ 0 ] != '0' && combo2[ 0 ] != '0' ) continue;
			int validCount[ 9 ] = { 0 };
			for ( k = 0; k < 6; ++k ) {
				for ( l = 0; l < 6; ++l ) {
					if ( combo1[ k ] == '0' || combo2[ l ] == '0' ) {
						if ( combo1[ k ] == '1' || combo2[ l ] == '1' ) {
							validCount[ 0 ] = 1;
						} else if ( combo1[ k ] == '4' || combo2[ l ] == '4' ) {
							validCount[ 1 ] = 1;
						} else if ( combo1[ k ] == '6' || combo2[ l ] == '6' ) {
							validCount[ 2 ] = 1;
						} else if ( combo1[ k ] == '9' || combo2[ l ] == '9' ) {
							validCount[ 2 ] = 1;
						}
					}
					if ( combo1[ k ] == '1' || combo2[ l ] == '1' ) {
						if ( combo1[ k ] == '6' || combo2[ l ] == '6' ) {
							validCount[ 3 ] = 1;
						} else if ( combo1[ k ] == '9' || combo2[ l ] == '9' ) {
							validCount[ 3 ] = 1;
						} else if ( combo1[ k ] == '8' || combo2[ l ] == '8' ) {
							validCount[ 8 ] = 1;
						}
					}
					if ( combo1[ k ] == '2' || combo2[ l ] == '2' ) {
						if ( combo1[ k ] == '5' || combo2[ l ] == '5' ) {
							validCount[ 4 ] = 1;
						}
					}
					if ( combo1[ k ] == '3' || combo2[ l ] == '3' ) {
						if ( combo1[ k ] == '6' || combo2[ l ] == '6' ) {
							validCount[ 5 ] = 1;
						} else if ( combo1[ k ] == '9' || combo2[ l ] == '9' ) {
							validCount[ 5 ] = 1; 
						}
					}
					if ( combo1[ k ] == '4' || combo2[ l ] == '4' ) {
						if ( combo1[ k ] == '6' || combo2[ l ] == '6' ) {
							validCount[ 6 ] = 1;
							validCount[ 7 ] = 1;
						} else if ( combo1[ k ] == '9' || combo2[ l ] == '9' ) {
							validCount[ 6 ] = 1;
							validCount[ 7 ] = 1;
						}
					}
				}
			}
			int sum = 0;
			for ( k = 0; k < 9; ++k ) {
				sum += validCount[ k ];
			}
			if ( sum == 9 ) ++count;
		}
	}
	int sum = 0; 
	for ( i = 0; i < 22050; ++i ) {
		if ( contains9[ i ] ) ++sum;
	}
	printf("Result: %d\n", count - sum);
}