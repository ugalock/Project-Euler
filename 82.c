/*
The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.

Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing a 80 by 80 matrix, from the left column to the right column.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, n = 0;
	char ( *lines )[ 6 ] = NULL;
	static int nums[ 80 ][ 80 ];
	static int path[ 80 ];
	FILE *f = fopen("82_matrix.txt", "r");
	if ( !f ) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	} 
	if ( !( lines = malloc( 6400 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 6400 && fgets( lines[ n ], 6, f)) {
    char *p = lines[ n ];                  
    p[ 4 ] = '\0'; 
  	++n;                         
  }
  n = 0;
  for ( i = 0; i < 80; ++i ) {
  	for ( j = 0; j < 80; ++j ) {
  		nums[ i ][ j ] = atoi( lines[ n ] );
  		++n;
  		if ( j == 79 ) {
	  		path[ i ] = nums[ i ][ j ];
  		}
  	}
  }
  long min = 10e10;
  for ( j = 78; j >= 0; --j ) {
  	path[ 0 ] += nums[ 0 ][ j ];
  	for ( i = 1; i < 80; ++i ) {
  		path[ i ] = path[ i-1 ] > path[ i ] ? path[ i ] + nums[ i ][ j ] : path[ i-1 ]
  			 + nums[ i ][ j ]; 
  	}
  	for ( i = 78; i >= 0; --i ) {
  		path[ i ] = path[ i ] > path[ i+1 ] + nums[ i ][ j ] ? path[ i+1 ] + nums[ i ][ j ]
  		 : path[ i ];
  		if ( !j ) {
  			min = path[ i ] < min ? path[ i ] : min;
  		}
  	}
  }
  
  printf("Result: %ld\n", min);

  return 0;
}