/*
Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int comparator(const void *p, const void *q) {
  int l = *(const int *)p;
  int r = *(const int *)q;
  return l - r;
}


int main() {
	int i, j, check, index = 0, n = 0;
	char ( *lines )[ 24 ] = NULL;
	static int exp[ 1000 ][ 2 ];
	static int64_t digits[ 1000 ];
	FILE *f = fopen("99_base_exp.txt", "r");
	if ( !f ) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	} 
	if ( !( lines = malloc( 1000 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  } 
  while (n < 1000 && fgets( lines[ n ], 24, f)) {
    char *p = lines[ n ];
    int len = strlen( p );
    char base[ 10 ];
    char e[ 10 ];
    for ( i = 0; p[ i ] != ','; ++i ) { ; }
    index = i;
    memcpy( (void*)base, p, i );
  	base[ i ] = '\0';
    exp[ n ][ 0 ] = atoi( base );      
    while ( p[ index ] != '\n' ) {
    	++index;
    }
    p[ index ] = '\0';
    strncpy( e, &p[ i+1 ], sizeof( char ) * ( len - i ) );
    e[ index ] = '\0';
    exp[ n ][ 1 ] = atoi( e );
    p[ i ] = '\0';
    ++n;               
  }
  int64_t max = 0;
  for ( i = 0; i < 1000; ++i ) {
  	double d = log10(exp[ i ][ 0 ]);
  	digits[ i ] = exp[ i ][ 1 ] * d;
  	index = digits[ i ] >= max ? i : index;
  	max = digits[ i ] > max ? digits[ i ] : max;
  }
  printf("%ld %d\n", max, index+1);
  return 0;
}