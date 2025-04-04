/* 
Using a combination of black square tiles and oblong tiles chosen from: red tiles measuring two units, green tiles measuring three units, and blue tiles measuring four units, it is possible to tile a row measuring five units in length in exactly fifteen different ways.

How many ways can a row measuring fifty units in length be tiled?
***Notes***
n 		f( n )
0     1
1     1
2     2
3     4
4     8
5     15
6     29
7     56
8     108

so f( n ) = f( n-1 ) + f( n-2 ) + f( n-3 ) + f( n-4 ) where f( n ) ; n < 0 == 0
*/

#include <stdio.h>
#include <stdint.h>

int main() {
	static uint64_t cache[ 51 ] = { 1 };
	for ( int i = 1; i <= 50; ++i ) {
		for ( int j = 1; j <= 4; ++j ) {
			cache[ i ] += i - j >= 0 ? cache[ i-j ] : 0;
		}
	}
	printf("Result: %lu\n", cache[ 50 ] ); 
}