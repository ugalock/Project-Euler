/*
A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int a, b, i, j, k, l, n = 0;
	char ( *lines )[ 5 ] = NULL;
	FILE *f = fopen("79_keylog.txt", "r");
	if ( !f ) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	} 
	if ( !( lines = malloc( 50 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 50 && fgets( lines[ n ], 5, f)) {
    char *p = lines[ n ];                  
    p[ 3 ] = '\0'; 
  	n++;                         
  }
  int count[ 10 ] = { 0 };
  char ( *front )[ 10 ] = NULL;
  front = calloc( 1000, sizeof( char ) );
  for ( i = 0; i < 10; ++i ) {
  	char num = i + '0';
		a = 0;
  	for ( j = 0; j < 50; ++j ) {
  		n = 0;
  		for ( k = 0; k < 3; ++k ) {
  			if ( count[ lines[ j ][ k ] - '0' ] == 0 ) {
  				count[ lines[ j ][ k ] - '0' ]++;
  			}
  			if ( lines[ j ][ k ] == num ) {
  				n = k;
  			}
  		}
  		if ( n ) {
  			b = 0;
  			while ( b < n ) {
  				for ( l = 0; l < a; ++l ) {
  					if ( front[ i ][ l ] == lines[ j ][ b ] ) break;
  				}
  				if ( l == a ) {
	  				front[ i ][ a ] = lines[ j ][ b ];
	  				++a;
  				}
  				++b;
  			}
  		}
  	}
		front[ i ][ a ] = '\0';
  }
  char result[ 10 ];
  for ( i = 0; i < 10; ++i ) {
  	result[ i ] = '\0';
  	for ( j = 0; j < 10; ++j ) {
  		if ( !count[ j ] ) continue;
  		a = 0;
  		while ( front[ j ][ a ] ) {
  			++a;
  		}
  		if ( a == i ) result[ i ] = j + '0';

  	}
  }
  printf("Result: %s\n", result);
  return 0;
}
