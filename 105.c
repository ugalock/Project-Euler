/*
Let S(A) represent the sum of elements in set A of size n. We shall call it a special sum set if for any two non-empty disjoint subsets, B and C, the following properties are true:

    S(B) ≠ S(C); that is, sums of subsets cannot be equal.
    If B contains more elements than C then S(B) > S(C).

For example, {81, 88, 75, 42, 87, 84, 86, 65} is not a special sum set because 65 + 87 + 88 = 75 + 81 + 84, whereas {157, 150, 164, 119, 79, 159, 161, 139, 158} satisfies both rules for all possible subset pair combinations and S(A) = 1286.

Using sets.txt (right click and "Save Link/Target As..."), a 4K text file with one-hundred sets containing seven to twelve elements (the two examples given above are the first two sets in the file), identify all the special sum sets, A1, A2, ..., Ak, and find the value of S(A1) + S(A2) + ... + S(Ak).

NOTE: This problem is related to Problem 103 and Problem 106.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int sets[ 100 ][ 20 ] = { 0 };

static inline uint64_t pop64(uint64_t y) {
	y -= ((y >> 1) & 0x5555555555555555ull);
	y = (y & 0x3333333333333333ull) + (y >> 2 & 0x3333333333333333ull);
	return ((y + (y >> 4)) & 0xf0f0f0f0f0f0f0full) * 0x101010101010101ull >> 56;
}

int testPartition( int n, int sum, int size ) {
	// unsigned partition;
	for ( unsigned partition = 1; partition < pow( 2, size-1 ); ++partition ) {
		int bCount = pop64( partition );
		int aMax = size - bCount;
		int aIndex = 0;
		int a[ size-1 ];
		int aCount, bSum = 0, aSum = 0;
		for ( unsigned i = 0; i < size; ++i ) {
			if ( partition & ( 1 << i ) ) {
				bSum += sets[ n ][ i ];
			} else {
				a[ aIndex ] = sets[ n ][ i ];
				++aIndex;
			}
		}
		for ( unsigned i = 1; i < pow( 2, aMax ); ++i ) {
			aCount = pop64( i );
			aSum = 0;
			for ( int j = 0; j < aMax; ++j ) {
				if ( i & ( 1 << (unsigned)j ) ) aSum += a[ j ];
			}
			if ( aSum == bSum ) return 0;
			else if ( aCount < bCount && aSum > bSum ) return 0;
			else if ( aCount > bCount && aSum < bSum ) return 0;
		}
	}
	return 1;
}

int main() {
	int i, j, n = 0, count = 0;
  char ( *lines )[ 60 ] = NULL;
  FILE *f = fopen("105_sets.txt", "r");
  if ( !f ) {
    fprintf(stderr, "Error opening file\n");
    return 1;
  } 
  if ( !( lines = malloc( 100 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 100 && fgets( lines[ n ], 60, f)) {
    char *p = lines[ n ];
    int sum = 0;
    for ( i = 0; p[ i ] != '\n'; ++i ) { ; }                  
    p[ i ] = '\0';
  	i = 0;
    const char d[ 2 ] = ",";
    char *token;
    token = strtok( p, d );
    while ( token ) {
    	int temp = atoi( token );
    	sum += temp;
    	sets[ n ][ i ] = temp;
    	token = strtok( NULL, d );
    	++i;
    }
    sets[ n ][ i ] = 0;
    if ( testPartition( n, sum, i ) ) count += sum;
    ++n;
  }
  printf("Result: %d\n", count);
  return 0;
    
}