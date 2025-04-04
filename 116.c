/* 
A row of five black square tiles is to have a number of its tiles replaced with coloured oblong tiles chosen from red (length two), green (length three), or blue (length four).

If red tiles are chosen there are exactly seven ways this can be done.

If green tiles are chosen there are three ways.

And if blue tiles are chosen there are two ways.

Assuming that colours cannot be mixed there are 7 + 3 + 2 = 12 ways of replacing the black tiles in a row measuring five units in length.

How many different ways can the black tiles in a row measuring fifty units in length be replaced if colours cannot be mixed and at least one coloured tile must be used?

NOTE: This is related to Problem 117.
*/

#include <stdio.h>
#include <stdint.h>

static uint64_t cache[ 3 ][ 51 ];

uint64_t fillTiles( int blockLength, int blocksLeft ) {
	if ( blocksLeft < blockLength ) return 1;
	if ( cache[ blockLength-2 ][ blocksLeft ] ) return cache[ blockLength-2 ][ blocksLeft ];
	uint64_t count = 0;

	count += fillTiles( blockLength, blocksLeft-blockLength );
	count += fillTiles( blockLength, blocksLeft-1 );

	cache[ blockLength-2 ][ blocksLeft ] = count;
	return count;
}

int main() {
	uint64_t result = 0; 
	int blocks[ 3 ] = { 2, 3, 4 };
	for ( int i = 0; i < 3; ++i ) {
		result += fillTiles( blocks[ i ], 50 );
	}
	// have to subtract the 3 solutions that contain no colored tiles
	printf("Result: %lu\n", result-3); 
}