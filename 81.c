/*
In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.

Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, n = 0;
	char ( *lines )[ 6 ] = NULL;
	static int nums[ 80 ][ 80 ];
	FILE *f = fopen("81_matrix.txt", "r");
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
  	}
  }
  for ( i = 79; i >= 0; --i ) {
  	for ( j = 79; j >= 0; --j ) {
  		if ( j == 79 && i == 79 ) {
  			nums[ i-1 ][ j ] += nums[ i ][ j ];
  			nums[ i ][ j-1 ] += nums[ i ][ j ];
  			continue;
  		} else if ( i == 79 ) {
  			nums[ i ][ j-1 ] += nums[ i ][ j ];
  			continue;
  		} else if ( j == 79 ) {
  			nums[ i-1 ][ j ] += nums[ i ][ j ];
  			continue;
  		}
  		nums[ i ][ j ] += nums[ i ][ j+1 ] >= nums[ i+1 ][ j ] ? nums[ i+1 ][ j ] : 
  			nums[ i ][ j+1 ];
  	}
  }
  printf("Result: %d\n", nums[ 0 ][ 0 ]);

  return 0;
}
