/*
or a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.

For example, it would appear that there are at least six ways of writing the number sixteen:

IIIIIIIIIIIIIIII
VIIIIIIIIIII
VVIIIIII
XIIIIII
VVVI
XVI

However, according to the rules only XIIIIII and XVI are valid, and the last example is considered to be the most efficient, as it uses the least number of numerals.

The 11K text file, roman.txt (right click and 'Save Link/Target As...'), contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals; see About... Roman Numerals for the definitive rules for this problem.

Find the number of characters saved by writing each of these in their minimal form.

Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.
*/

#include <stdio.h>
#include <string.h>

static int bestRomans[ 5000 ];

static char* romans[ 13 ] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
static int nums[ 13 ] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

void makeBestRomans() {
	int i, j, num, n, idx, count;
	char *roman; 
	for ( i = 1; i < 5000; ++i ) {
		static char curr[ 24 ];
		idx = 0;
		n = 0;
		num = i;
		while ( num != 0 ) {
			if ( num >= nums[ idx ] ) {
				roman = romans[ idx ];
				for ( j = 0; roman[ j ] != 0; ++j ) {
					curr[ n ] = roman[ j ];
					++n;
				}
				num -= nums[ idx ];
			} else {
				++idx;
			}
		}
		bestRomans[ i ] = n;
	}
}

int getValue( char c ) {
	switch( c ) {
		case( 'M' ):
			return 1000;
		case( 'D' ):
			return 500;
		case( 'C' ):
			return 100;
		case( 'L' ):
			return 50;
		case( 'X' ):
			return 10;
		case( 'V' ):
			return 5;
		case( 'I' ):
			return 1;
	}
	return -1;
}


int main() {
	int i, count, num, result = 0, n = 0;
	char *curr;
	char ( *lines )[ 24 ] = NULL;
	FILE *f = fopen("89_roman.txt", "r");
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
    for ( i = 0; p[ i ] != '\n'; ++i ) { ; }                  
    p[ i ] = '\0'; 
  	n++;                         
  }
  makeBestRomans();
  for ( i = 0; i < 1000; ++i ) {
  	curr = lines[ i ];
  	n = 0;
  	num = 0;
  	count = 0;
  	while( curr[ n ] ) {
  		int v1, v2 = 0;
  		v1 = getValue( curr[ n ] );
  		if ( curr[ n+1 ] ) v2 = getValue( curr[ n+1 ] );
  		if ( v1 >= v2 ) {
  			num += v1;
  			++count;
  		} else {
  			num += v2 - v1;
  			count += 2;
  			++n;
  		}
  		++n;
  	}
  	result += count - bestRomans[ num ];
  }
  printf("Result: %d\n", result);
  return 0;
}