/*
By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively, we form a square number: 1296 = 362. What is remarkable is that, by using the same digital substitutions, the anagram, RACE, also forms a square number: 9216 = 962. We shall call CARE (and RACE) a square anagram word pair and specify further that leading zeroes are not permitted, neither may a different letter have the same digital value as another letter.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, find all the square anagram word pairs (a palindromic word is NOT considered to be an anagram of itself).

What is the largest square number formed by any member of such a pair?

NOTE: All anagrams formed must be contained in the given text file.

1023454 -> 1234565
ALIAS -> 12314
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


static int potentialSquares[ 9 ][ 50000 ][ 2 ] = { 0 };
static char potentialSquaresMap[ 9 ][ 50000 ][ 2 ][ 11 ] = { 0 };

void mapNumbers() {
	int index, usedIndex, k;
	for ( int i = 1; i < 9; ++i ) {
		for ( int j = 0; potentialSquares[ i ][ j ][ 0 ] != 0; ++j ) {
			index = 0; 
			usedIndex = 0;
			char used[ 10 ];
			char s[ 10 ];
			snprintf(s, i+1, "%d", potentialSquares[ i ][ j ][ 0 ] );
			s[ i ] = 0;
			for ( k = 0; k < i; ++k ) {
				char c = s[ k ];
				int check = -1;
				for ( int l = 0; l < index; ++l ) {
					if ( used[ l ] == c ) {
						check = l;
					}
				}
				if ( check != -1 ) {
					potentialSquaresMap[ i ][ j ][ 0 ][ k ] = check + '0' + 1;
				} else {
					used[ index ] = c;
					potentialSquaresMap[ i ][ j ][ 0 ][ k ] = index + '0' + 1;
					++index;
				}
			}
			potentialSquaresMap[ i ][ j ][ 0 ][ i ] = 0;
			used[ index ] = 0;
			char s2[ 10 ];
			snprintf(s2, i+1, "%d", potentialSquares[ i ][ j ][ 1 ] );
			s2[ i ] = 0;
			for ( k = 0; k < i; ++k ) {
				for ( int l = 0; l < index; ++l ) {
					if ( s2[ k ] == used[ l ] )
						potentialSquaresMap[ i ][ j ][ 1 ][ k ] = l + '0' + 1;
				}
			}
			potentialSquaresMap[ i ][ j ][ 1 ][ i ] = 0;
		}
	}
}

int checkDigits( int a, int b ) {
	if ( (int)log10((double)a) != (int)log10((double)b) ) return 0;
	int digitsA = 0, digitsB = 0;
	int temp;
	while ( a ) {
		temp = a % 10;
		digitsA |= 1 << temp;
		a /= 10;
	}
	while ( b ) {
		temp = b % 10;
		digitsB |= 1 << temp;
		b /= 10;
	}
	return digitsA == digitsB;
}

void findPotentialSquares() {
	static int squares[ 9 ][ 10000 ] = { 0 }; 
	int square = 1, i = 1;
	int newd, d = (int)log10((double)i) + 1;
	int index = 0;
	while ( d < 9 ) {
		squares[ d ][ index ] = square;
		++i;
		square = i * i;
		newd = (int)log10( (double)square ) + 1;
		index = newd > d ? 0 : index + 1;
		d = newd;
	}

	for ( int i = 1; i < 9; ++i ) {
		index = 0;
		for ( int j = 0; squares[ i ][ j ] != 0; ++j ) {
			for ( int k = j+1; squares[ i ][ k ] != 0; ++k ) {
				if ( checkDigits( squares[ i ][ j ], squares[ i ][ k ] ) ) {
					potentialSquares[ i ][ index ][ 0 ] = squares[ i ][ j ];
					potentialSquares[ i ][ index ][ 1 ] = squares[ i ][ k ];
					++index;
				}
			}
		}
	}
}

int comparator(const void *p, const void *q)
{
  const char *l = (const char *)p;
  const char *r = (const char *)q;
  return strcmp( l, r );
}

int main() {
	int anagrams[ 100 ][ 2 ];
	char *s;
	int i, j, check, index = 0, n = 0;
	char ( *sorted )[ 24 ] = NULL;
	char ( *lines )[ 24 ] = NULL;
	static int lengths[ 1786 ];
	FILE *f = fopen("98_words.txt", "r");
	if ( !f ) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	} 
	if ( !( lines = malloc( 1786 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  } 
  if ( !( sorted = malloc( 1786 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 1786 && fgets( lines[ n ], 24, f)) {
    char *p = lines[ n ];
    for ( i = 0; p[ i ] != '\n'; ++i ) { ; }                  
    p[ i ] = '\0';
    s = strdup( p );
    lengths[ n ] = i;
		qsort( (void*)s, i, sizeof( char ), comparator );
		memcpy( sorted[ n ], (void*)s, i * sizeof( char ) );
    ++n;               
  }

  for ( i = 0; i < 1786; ++i ) {
  	s = sorted[ i ];
  	for ( j = i+1; j < 1786; ++j ) {
  		if ( !strcmp( s, sorted[ j ] ) ) {
  			anagrams[ index ][ 0 ] = i; 
  			anagrams[ index ][ 1 ] = j;
  			++index;
  		}
  	}
  }
  findPotentialSquares();
  mapNumbers();

  for ( i = 0; i < index; ++i ) {
  	char used[ 10 ];
  	int idx = 0;
  	char *str = lines[ anagrams[ i ][ 0 ] ];
  	int len = strlen( str );
  	for ( j = 0; j < len; ++j ) {
  		int check = -1;
  		char c = str[ j ];
  		for ( int k = 0; k < idx; ++k ) {
  			if ( used[ k ] == c ) {
  				check = k;
  			}
  		}
  		if ( check == -1 ) {
  			used[ idx ] = c;
  			lines[ anagrams[ i ][ 0 ] ][ j ] = idx + '0' + 1;
  			++idx;
  		} else {
  			lines[ anagrams[ i ][ 0 ] ][ j ] = check + '0' + 1;
  		}
  	}
  	char *str1 = lines[ anagrams[ i ][ 1 ] ];
  	for ( j = 0; j < len; ++j ) {
  		for ( int k = 0; k < idx; ++k ) {
  			if ( str1[ j ] == used[ k ] )
  				lines[ anagrams[ i ][ 1 ] ][ j ] = k + '0' + 1;
  		}
  	}
  }

  int max = 0;
  for ( i = 1; i < 9; ++i ) {
  	for ( j = 0; potentialSquares[ i ][ j ][ 0 ] != 0; ++j ) {
  		for ( int k = 0; k < index; ++k ) {
  			char *a1 = lines[ anagrams[ k ][ 0 ] ];
  			char *a2 = lines[ anagrams[ k ][ 1 ] ];
  			char *n1 = potentialSquaresMap[ i ][ j ][ 0 ];
  			char *n2 = potentialSquaresMap[ i ][ j ][ 1 ]; 
  			if ( ( !strcmp(a1, n1) && !strcmp(a2, n2) ) || 
  				( !strcmp(a1, n2) && !strcmp(a2, n1) ) ) {
  				max = potentialSquares[ i ][ j ][ 0 ] > max ? 
  					potentialSquares[ i ][ j ][ 0 ] : max;
  				max = potentialSquares[ i ][ j ][ 1 ] > max ? 
  					potentialSquares[ i ][ j ][ 1 ] : max;
  			}
  		}
  	}
  }
  printf("%d\n", max);
  return 0;
}