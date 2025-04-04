/*
In a 3x2 cross-hatched grid, a total of 37 different rectangles could be situated within that grid as indicated in the sketch.

There are 5 grids smaller than 3x2, vertical and horizontal dimensions being important, i.e. 1x1, 2x1, 3x1, 1x2 and 2x2. If each of them is cross-hatched, the following number of different rectangles could be situated within those smaller grids:

1x1: 1
2x1: 4
3x1: 8
1x2: 4
2x2: 18

Adding those to the 37 of the 3x2 grid, a total of 72 different rectangles could be situated within 3x2 and smaller grids.

How many different rectangles could be situated within 47x43 and smaller grids?
***Notes***
We know the formula for the normally orientated rectangle from problem 85,
for an i x j rectangle it will contain sumtorial(i) x sumtorial(j) 'normal'
rectangles. After writing out the numbers of regular and diagonal
up to about 5 x 5:
2 x 1		  2 x 2					
diag: 1   diag: 9		
reg: 3		reg: 9		

3 x 1			3 x 2			3 x 3
diag: 2		diag: 19	diag: 51
reg: 6		reg: 18		reg: 36

4 x 1			4 x 2			4 x 3			4 x 4
diag: 3		diag: 29	diag: 86	diag: 166
reg: 10		reg: 30		reg: 60		reg: 100

5 x 1			5 x 2			5 x 3			5 x 4			5 x 5
diag: 4		diag: 39	diag: 121	diag: 250	diag: 410
reg: 15		reg: 45		reg: 90		reg: 150	reg: 225 

I noticed that the a pattern starts whenever we reach a square. 
After an n x n square, an (n+1) x n rectangle is going to have something 
added to it, while an (n+2) x n rectangle will have twice that something
added to it. It was pretty quick work to recognize that something took
the form of 2j+1 C 3, and then the only hard part left was working out the 
formula for the n x n squares, which after some time came out to be 
4n^4-n^2-3n / 6
I think there could be an even faster way to deal with this, since we're dealing 
with the tetrahedral numbers for the reg squares and a pretty clear 
arithmetic sequence for the diagonals, but this ran so quickly that I couldn't 
be bothered.  
*/

#include <stdio.h>
#include <stdint.h>

int64_t factorial( int n ) {
	if ( !n ) return 1;
	int64_t result = n;
	while ( n > 1 ) result *= --n;
	return result;
}

int64_t comb( int n, int c ) {
	if ( c == n || !c ) return 1; 
	int64_t res = 1;
	int i = n-c;
	while ( i < n ) res *= ++i; 
	return res / factorial( c );
}

int64_t sumtorial( int64_t n ) {
	if ( !n ) return 1;
	return n * ( n+1 ) / 2;
}

int main() {
	int64_t b, d, r, result = 1;
	static long sum_cache[ 48 ];
	static long comb_cache[ 88 ];
	for ( int i = 2; i < 48; ++i ) {
		for ( int j = 1; j <= i && j < 44; ++j ) {
			b = ( 4*j*j*j*j-j*j-3*j ) / 6;
			if ( !comb_cache[ 2*j+1 ] ) comb_cache[ 2*j+1 ] = comb( 2*j+1, 3 );
			if ( !sum_cache[ i ] ) sum_cache[ i ] = sumtorial( i );
			if ( !sum_cache[ j ] ) sum_cache[ j ] = sumtorial( j );
			d = b + ( i - j ) * comb_cache[ 2*j+1 ];
			r = sum_cache[ j ] * sum_cache[ i ];
			if ( i == j || i > 43 ) result += d + r;
			else 
				result += 2 * ( d + r );
		}
	}
	printf("Result: %ld\n", result);
}
