/*
By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and making use of the four arithmetic operations (+, −, *, /) and brackets/parentheses, it is possible to form different positive integer targets.

For example,

8 = (4 * (1 + 3)) / 2
14 = 4 * (3 + 1 / 2)
19 = 4 * (2 + 3) − 1
36 = 3 * 4 * (2 + 1)

Note that concatenations of the digits, like 12 + 34, are not allowed.

Using the set, {1, 2, 3, 4}, it is possible to obtain thirty-one different target numbers of which 36 is the maximum, and each of the numbers 1 to 28 can be obtained before encountering the first non-expressible number.

Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be obtained, giving your answer as a string: abcd.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static int numsFound[ 3025 ];

void getNums( double n, int nums[], int numLeft ) {
	if ( !numLeft ) {
		if ( n - (int)n == 0 && n > 0 ) numsFound[ (int)n ] = 1;
	} else {
		for ( int q = 0; q < numLeft; ++q ) {
		}
		int temp;
		for ( int i = 0; i < numLeft; ++i ) {
			if ( 1 ) {
				if ( numLeft > 1 ) {
					int newNums[ numLeft-1 ];
					temp = 0;
					for ( int j = 0; j < numLeft-1; ++j ) {
						if ( temp == i ) ++temp;
						newNums[ j ] = nums[ temp ];
						++temp;
					}
					double new = ( n * 1.0 )/(double)(nums[ i ]);
					getNums( new, newNums, numLeft - 1 );
				} else {
					double new = ( n * 1.0 )/(double)(nums[ i ]);
					getNums( new, NULL, numLeft - 1 );
				}
			} 
			if ( 1 ) {
				if ( numLeft > 1 ) {
					int newNums[ numLeft-1 ];
					temp = 0;
					for ( int j = 0; j < numLeft-1; ++j ) {
						if ( temp == i ) ++temp;
						newNums[ j ] = nums[ temp ];
						++temp;
					}
					double new = fabs( (double)(nums[ i ]) - n );
					getNums( new, newNums, numLeft - 1 );
				} else {
					double new = fabs( (double)(nums[ i ]) - n );
					getNums( new, NULL, numLeft - 1 );
				}
			}
			if ( numLeft > 1 ) {
				int newNums[ numLeft-1 ];
				temp = 0;
				for ( int j = 0; j < numLeft-1; ++j ) {
					if ( temp == i ) ++temp;
					newNums[ j ] = nums[ temp ];
					++temp;
				}
				double new = n + (double)(nums[ i ]);
				getNums( new, newNums, numLeft - 1 );
			} else {
				double new = n + (double)(nums[ i ]);
				getNums( new, NULL, numLeft-1 );
			}
			if ( numLeft > 1 ) {
				int newNums2[ numLeft-1 ];
				temp = 0;
				for ( int j = 0; j < numLeft-1; ++j ) {
					if ( temp == i ) ++temp;
					newNums2[ j ] = nums[ temp ];
					++temp;
				}
				double new = n * (double)(nums[ i ]);
				getNums( new, newNums2, numLeft - 1 );
			} else {
				double new = n * (double)(nums[ i ]);
				getNums( new, NULL, numLeft-1);
			}
		}
	}
}


int main() {
	int highest = 0, temp = 0;
	static char result[ 5 ];
	int nums[ 4 ];
	for ( int i = 1; i < 7; ++i ) {
		nums[ 0 ] = i;
		for ( int j = i+1; j < 8; ++j ) {
			nums[ 1 ] = j;
			for ( int k = j+1; k < 9; ++k ) {
				nums[ 2 ] = k;
				for ( int l = k+1; l < 10; ++l ) {
					nums[ 3 ] = l;
					memset( numsFound, 0, sizeof( numsFound ) );
					for ( int n = 0; n < 4; ++n ) {
						int newNums[ 3 ];
						temp = 0;
						for ( int q = 0; q < 3; ++q ) {
							if ( temp == n ) ++temp;
							newNums[ q ] = nums[ temp ];
							++temp;
						}
						double num = (double)(nums[ n ]);
						getNums( num, newNums, 3 );
					}
					int count = 0, m = 1;
					while ( numsFound[ m ] ) {
						++count;
						++m;
					}
					if ( count > highest ) {
						highest = count;
						for ( int p = 0; p < 4; ++p ) {
							result[ p ] = nums[ p ] + '0';
						}
					}
				}
			}
		}
	}
	printf("Result: %s with a count of %d\n", result, highest);

}

